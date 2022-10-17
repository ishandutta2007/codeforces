#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
bool a[15];

set<ll> s1,s2;

int chk(int x){
	int i,j,k=0;
	memset(a,0,sizeof(a));
	while(x){
		a[x%10]=1;x/=10;
	}
	for(i=0;i<=9;i++){
		k+=a[i];
	}
	return k;
}

void dfs1(int x,ll y){
	s1.insert(y);
	s2.insert(y);
	if(y>=1e9){return ;}
	dfs1(x,y*10+x);
}

void dfs2(int x,int y,ll z){
	if(!z){
		if(x){dfs2(x,y,x);}
		if(y){dfs2(x,y,y);}
	}
	else{
		s2.insert(z);
		if(z>=1e9){return;}
		dfs2(x,y,z*10+x);
		dfs2(x,y,z*10+y);
	}
}

int main(){
	for(i=1;i<=9;i++){
		dfs1(i,i);
	}
	/*for(auto i:s1){
		cout<<i<<endl;
	}*/
	for(i=0;i<=9;i++){
		for(j=i+1;j<=9;j++){
			dfs2(i,j,0);
		}
	}
	//cout<<s2.size();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&i,&j);
		if(j==1){
			printf("%lld\n",*s1.lower_bound(i));
			continue;
		}
		if(j==2){
			printf("%lld\n",*s2.lower_bound(i));
			continue;
		}
		while(1){
			if(chk(i)<=j){
				printf("%d\n",i);break;
			}
			i++;
		}
	}
}
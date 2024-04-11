#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ii,j,k,n,m,t,i;
bool a[15];
ll t1,t2,t3,res;
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

set<ll> v[15],sb;

void dfs3(int dep,int x,ll y){
	v[dep].insert(y);
	if(dep>=10){return;}
	dfs3(dep+1,x,y*10+x);
}

void dfs4(int dep,ll y,ll pw){
	ll k;
	if(dep>9){return;}
	for(auto i:v[dep]){
		k=i+y*pw;
		if(chk(k)<=j&&k>=ii){
			res=min(res,k);
		}
	}
	dfs4(dep+1,y/10,pw*10);
}

int main(){
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			dfs3(1,j,i);
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&ii,&j);
		if(chk(ii)<=j){
			printf("%d\n",ii);continue;
		}
		sb.clear();
		res=1e18;
		dfs4(1,ii/10,10);
		printf("%lld\n",res);
	}
}
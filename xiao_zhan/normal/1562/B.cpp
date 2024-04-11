#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,sb,a[666],res;
bool f[10050];

bool chk3(int a,int b,int c){
	int sb=a*100+b*10+c;
	if(f[sb]){
		res=min(res,sb);
	}
	return 0;
}

bool chk2(int a,int b){
	int sb=a*10+b;
	if(f[sb]){
		res=min(res,sb);
	}
	return 0;
}

bool chk1(int a){
	if(f[a]){
		res=min(res,a);
	}
	return 0;
}

int main(){
	f[1]=1;
	for(i=2;i<=10000;i++){
		if(!f[i]){
			for(j=i+i;j<=10000;j+=i){f[j]=1;}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=114514;
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
		}
		for(i=1;i<=n;i++){
			chk1(a[i]);
		}
		
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				chk2(a[i],a[j]);
			}
		}
		
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=n;k++){
					chk3(a[i],a[j],a[k]);
				}
			}
		}
		if(res==114514){
			return 1;
		}
		if(res<10){
			printf("1\n%d\n",res);continue;
		}
		if(res<100){
			printf("2\n%d\n",res);continue;
		}
		if(res<1000){
			printf("3\n%d\n",res);continue;
		}
		
	}
}
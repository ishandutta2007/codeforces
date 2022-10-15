#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 1000;
const int maxm = 10000;

typedef long long LL;

LL f[maxn+7][maxm+7];
int ans=0,n;
LL W,B,X;
int c[maxn+7];
LL cost[maxn+7];

int main(){
	scanf("%d%lld%lld%lld",&n,&W,&B,&X);
	for (int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%lld",&cost[i]);
	}
	f[0][0]=W;
	for (int i=1;i<=n;++i){
		int tmp=0;
		for (int j=0;j<=ans+c[i];++j){
			for (int k=max(0,j-ans);k<=c[i]&&k<=j;++k){
				if(f[i-1][j-k]>=k*cost[i]){
					tmp=j;
					f[i][j]=max(f[i][j],min(f[i-1][j-k]-k*cost[i]+X,W+j*B));
				}
			}
		}
		ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
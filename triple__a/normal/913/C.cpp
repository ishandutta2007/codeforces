#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;

const LL inf = (LL)1e18;

const int maxn=31;

LL cost[maxn+7];
LL ans=0;
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		scanf("%lld",&cost[i]);
	}
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			cost[i]=min(cost[i],cost[j]);
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<i;++j){
			LL tmp=cost[j];
			for (int k=0;k<i-j;++k){
				tmp*=2;
				if (tmp>cost[i]) break;
			}
			cost[i]=min(cost[i],tmp);
		}
	}
	for (int i=0;i<=n-1;++i){
		if (m&1){
			ans+=cost[i];
			ans=min(ans,2*cost[i]);
		}
		else{
			ans=min(ans,cost[i]);
		}
		m>>=1;
	}
	ans+=2*m*cost[n-1];
	printf("%lld\n",ans);
	return 0;
}
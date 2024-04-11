#include "bits/stdc++.h"
using namespace std;

const int maxn=100007;

int n,k,ans=0;
int sum[maxn];
int a[maxn],b[maxn];

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		if (b[i]==1){
			ans+=a[i];
			a[i]=0;
		}
	}
	sum[0]=0;
	for (int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int mx=0;
	for (int i=1;i+k-1<=n;++i){
		mx=max(mx,sum[i+k-1]-sum[i-1]);
	}
	ans+=mx;
	printf("%d\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,mod=998244353,inv2=(mod+1)/2;
int n,ans;
int f[maxn],sum[2];
int main(){
	scanf("%d",&n),sum[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=sum[(i&1)^1];
		sum[i&1]=(sum[i&1]+f[i])%mod;
	}
	ans=f[n];
	for(int i=1;i<=n;i++)
		ans=1ll*ans*inv2%mod;
	printf("%d\n",ans);
	return 0;
}
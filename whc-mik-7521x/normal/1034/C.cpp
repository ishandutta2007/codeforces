#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
long long gcd(long long a,long long b){
	long long az=__builtin_ctz(a);
	long long bz=__builtin_ctz(b);
	long long z=min(az,bz);
	b>>=bz;
	while(a){
		a>>=az;
		long long diff=a-b;
		az=__builtin_ctz(diff);
		b=min(a,b),a=abs(diff);
	}
	return b<<z;
}
int n,a[N],fa[N],ct[N],vl[N],dp[N];
long long sum[N];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)scanf("%d",&fa[i]);
	for(int i=n;i>=1;i--)sum[i]+=a[i],sum[fa[i]]+=sum[i];
	for(int i=1;i<=n;i++){
		long long now=sum[1]/gcd(sum[i],sum[1]);
		if(now<=n)ct[now]++;
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o+=i){
			vl[o]+=ct[i];
		}
	}
	for(int i=n;i>=1;i--){
		if(vl[i]==i){
			dp[i]=1;
			for(int o=i+i;o<=n;o+=i)(dp[i]+=dp[o])%=mod;
		}
	}
	printf("%d",dp[1]);
}
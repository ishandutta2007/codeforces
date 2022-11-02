#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int t,k,n;
int a[100009],b[100009];
ll f[100009][2],sum[100009];
int main(){
	scanf("%d%d",&t,&k);n=0;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&a[i],&b[i]);
		n=max(b[i],n);
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;sum[0]=0;
	for(int i=1;i<=n;i++){
		if(i>=k){
			f[i][1]=((f[i][1]+f[i-k][0])%mod+f[i-k][1])%mod;
		} 
		f[i][0]=((f[i][0]+f[i-1][0])%mod+f[i-1][1])%mod;
		sum[i]=((sum[i-1]+f[i][0])%mod+f[i][1])%mod;
	}
	for(int i=1;i<=t;i++)
		printf("%lld\n",(sum[b[i]]-sum[a[i]-1]+mod+mod)%mod);
	return 0;
}
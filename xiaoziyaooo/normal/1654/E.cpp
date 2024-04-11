#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005,base=200000,BASE=30000005;
int n,ans;
int a[maxn],tot[maxn<<1],vis[maxn*300];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=-300;i<=300;i++){
		for(int j=1;j<=n;j++)
			vis[BASE+a[j]-i*j]++,ans=max(ans,vis[BASE+a[j]-i*j]);
		for(int j=1;j<=n;j++)
			vis[BASE+a[j]-i*j]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=max(1ll,i-700);j<=min(n,i+700);j++)
			if(i!=j&&(a[i]-a[j])%(i-j)==0){
				int v=base+(a[i]-a[j])/(i-j);
   				tot[v]++,ans=max(ans,tot[v]+1);
			}
		for(int j=max(1ll,i-700);j<=min(n,i+700);j++)
			if(i!=j&&(a[i]-a[j])%(i-j)==0)
				tot[base+(a[i]-a[j])/(i-j)]--;
	}
	printf("%lld\n",n-ans);
	return 0;
}
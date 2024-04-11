#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],f[N],g[N],pre[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int s=0;
	for (int i=1;i<=n;i++)f[i]=f[i-1]+pre[i-1],pre[i]=pre[i-1]+a[i];
	int ans=f[n],len=0;
	for (int i=n;i;i--){
		g[i]=g[i+1]+a[i]*((n-i)/(m+1));
		len=(n-i)/(m+1);
		ans=max(ans,g[i]+f[i-1]+pre[i-1]*(1+len));
	}
	printf("%lld\n",ans);
}
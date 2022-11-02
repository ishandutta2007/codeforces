#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int T,n,p,k,x,y,f[N];
char s[N];
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld",&n,&p,&k);
		scanf("%s",s+1);
		scanf("%lld%lld",&x,&y);
		for (int i=n;i;i--)f[i]=(s[i]=='1'?0:x)+(i+k<=n?f[i+k]:0);
		int ans=1e18;
		for (int i=p;i<=n;i++)ans=min(ans,y*(i-p)+f[i]);
		printf("%lld\n",ans);
	}
}
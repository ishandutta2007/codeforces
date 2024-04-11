#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005,M=998244353;
int n,k,x,vis[N],a[N],ans;
signed main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++)scanf("%lld",&x),vis[x]=i;
	for (int i=n;i>=n-k+1;i--)a[n-i+1]=vis[i],ans+=i;
	sort(a+1,a+k+1);
	printf("%lld ",ans);
	ans=1;
	for (int i=1;i<k;i++)(ans*=a[i+1]-a[i])%=M;
	printf("%lld\n",ans);
}
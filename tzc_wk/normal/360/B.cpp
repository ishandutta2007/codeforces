#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
ll n,k,a[200005],dp[200005];
inline bool check(ll x){
	fill0(dp);ll mx=1;
	for(ll i=1;i<=n;i++) dp[i]=1;
	for(ll i=2;i<=n;i++) for(ll j=1;j<i;j++){
		if(abs(a[i]-a[j])<=1ll*(i-j)*x)
			dp[i]=max(dp[i],dp[j]+1);
		mx=max(mx,dp[i]);
	}
	return (mx>=n-k);
}
int main(){
//	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll l=0,r=2e9,ans=-23987;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
/*
dp[i]=max{dp[j]}+1 (|a[i]-a[j]|<=(i-j)*x}
a[i]-(i-j)*x<=a[j]<=a[i]+(i-j)*x
a[i]-i*x+j*x<=a[j]<=a[i]+i*x-j*x
*/
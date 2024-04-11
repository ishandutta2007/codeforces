#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=300005;
int n;
ll a[N],b[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&a[i],&b[i]);
	ll S=0,ans=1ll<<60;
	For(i,1,n) S+=max(0ll,a[i%n+1]-b[i]);
	For(i,1,n) ans=min(ans,min(b[i],a[i%n+1]));
	printf("%lld\n",S+ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
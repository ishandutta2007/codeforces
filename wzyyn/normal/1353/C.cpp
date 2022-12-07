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
int n,k,a[55],b[55];
void solve(){
	int n;
	ll ans=0;
	scanf("%d",&n);
	for (ll x=n;n>0;ans+=1ll*x*x-1ll*n*n,n-=2);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
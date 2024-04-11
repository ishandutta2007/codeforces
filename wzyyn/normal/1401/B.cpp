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
ll a[5],b[5];
void solve(){
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	scanf("%lld%lld%lld",&b[0],&b[1],&b[2]);
	ll v=min(a[2],b[1]),ans=v*2;
	a[2]-=v; b[1]-=v;
	v=min(a[2],b[2]); a[2]-=v; b[2]-=v;
	v=min(a[0],b[2]); a[0]-=v; b[2]-=v;
	ans-=min(a[1],b[2])*2;
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
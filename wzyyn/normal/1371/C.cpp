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
#define all(v) v.begin(),v.end()
using namespace std;

void solve(){
	ll n,m,A,B;
	scanf("%lld%lld%lld%lld",&n,&m,&A,&B);
	if (min(n,m)<B||n+m<A+B) puts("No");
	else puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
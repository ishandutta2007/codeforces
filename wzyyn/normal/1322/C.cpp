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
const int N=500005;
pll a[N];
ll val[N];
int n,m;
ll rnd(){
	ll x=0;
	For(i,1,18)
		x=x*10+rand()%10;
	return x;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%lld",&a[i].se);
	For(i,1,n) val[i]=rnd(),a[i].fi=0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		a[y].fi^=val[x];
	}
	sort(a+1,a+n+1);
	ll ans=0,s=a[1].se;
	For(i,2,n+1){
		if (i==n+1||a[i].fi!=a[i-1].fi){
			if (a[i-1].fi) ans=gcd(ans,s);
			s=0;
		}
		s+=a[i].se;
	}
	printf("%lld\n",ans);
}
int main(){
	srand(time(NULL));
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
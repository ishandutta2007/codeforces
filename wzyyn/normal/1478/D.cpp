#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int N=200005;
int n;
ll k,x,y,g;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void solve(){
	g=0;
	scanf("%d%lld%lld",&n,&k,&x);
	For(i,2,n) scanf("%lld",&y),g=gcd(g,abs(x-y));
	if (g==0) puts(k==x?"YES":"NO");
	else puts((k-x%g)%g==0?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
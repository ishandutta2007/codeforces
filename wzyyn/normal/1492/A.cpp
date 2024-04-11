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

void solve(){
	ll p,a,b,c;
	scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
	ll re=1ll<<60;
	re=min(re,(p+a-1)/a*a-p);
	re=min(re,(p+b-1)/b*b-p);
	re=min(re,(p+c-1)/c*c-p);
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
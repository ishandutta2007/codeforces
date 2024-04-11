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

ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
bool check(ll n){
	ll m=n,x=0;
	for (;m;x+=m%10,m/=10);
	return gcd(n,x)!=1;
}
void solve(){
	ll n;
	scanf("%lld",&n);
	for (;!check(n);++n);
	cout<<n<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
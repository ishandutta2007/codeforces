#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
const int MOD = 1e9+7;
ll bell[4009],inv[4009];
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
		if (b) { ll d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}
ll modinv(int i){
	ll x,y;
	euclid(i,MOD,x,y);
	return (x+MOD)%MOD;
}
void comb(vi& c,int n){
	c[0] = 1;
	repA(i,1,n){
		c[i] = (c[i-1]*(n-i+1)%MOD)*inv[i]%MOD;
		c[i]%=MOD;
	}
}
void cal(int i){
	vi c(i);
	comb(c,i-1);
	rep(j,i){
		bell[i]+=c[j]*bell[j]%MOD;
		bell[i]%=MOD;
	}
}
void pre(){
	bell[0] = 1;
	bell[1] = 1;
	inv[1] =1;
	repA(i,2,4001){
		inv[i] = modinv(i);
		
		cal(i);
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();	
	int n;cin>>n;
	cout<<(bell[n+1]-bell[n]+MOD)%MOD;
	return 0;
}
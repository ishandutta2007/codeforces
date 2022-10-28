#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n; cin >> n;
	ll n_ = n;
	vi p; 
	for(ll i = 2; i*i <= n_; i++){
		if(n_%i == 0){
			p.pb(i);
			while(n_%i == 0) n_ /= i;
		}
	}
	if(n_ != 1) p.pb(n_);
	if(sz(p) == 1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		cout << 2 << endl;
		ll x,y;
		gcd(p[0], p[1], x, y);
		if(x < 0){
			swap(p[0], p[1]);
			swap(x,y);
		}
		cout << n/p[0] - x << " " << n/p[0] << endl;
		cout << -y << " " << n/p[1] << endl;
	}
	return 0;
}
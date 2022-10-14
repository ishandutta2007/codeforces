#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define vi vector<int>
#define vb vector<bool>

#define ll long long
#define vl vector<ll>
#define EACH(x, y) for(auto &x: y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ar array
#define F0R(x, y) rep(x,0,y)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define add push_back
#define V vector
#define P pair
#define tcT template<class T
#define tcTU tcT, class U
#define F first
#define S second
#define str string

#define FOR rep
const double eps = 1e-9;
int ni() {
	int tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
ll nl() {
	ll tsadfsfd;
	cin >> tsadfsfd;
	return tsadfsfd;
}
string next() {
	string s;
	cin >> s;
	return s;
}

tcT> bool umin(T &x, T y) {
	if(x<y)
		return 1;
	else
		return x=y,0;
}
tcT> bool umax(T &x, T y) {
	if(x>y)
		return 1;
	else
		return x=y,0;
}

ll modpow(ll x, ll y, ll m) {
	ll res = 1;
	for(; y; y >>= 1, x = x * x % m)
		if(y&1)
			res = res * x % m;
	return res;
}

const ll mod = (1e9)+7; // change to something else

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt=1;
	// cin >> tt;

	rep(TT, 0, tt) {
		int n; cin >> n;
		int m; cin >> m;
		int k; cin >> k;
		int t, x, y;
		vi a(n);
		for(auto &i : a)
			cin >> i;
		vi s(n);
		int curseg=0;
		rep(i,0,n) {
			int x=i;
			if(a[x]<=k)
				continue;
			s[x]=1;
			if(x&&x<n-1) {
				if(s[x-1]==s[x+1]&&s[x-1]==0) {
					++curseg;
				} else if(s[x-1]==s[x+1]&&s[x-1]==1) {
					--curseg;
				}
			} else if(x==0) {
				if(x<n-1&&s[x+1]==1) {
					continue;
				}
				++curseg;
			} else if(x==n-1) {
				if(x>0&&s[x-1]==1) {
					continue;
				}
				++curseg;
			}
		}
// 		cout << curseg << "\n";
		rep(i,0,m) {
			cin >> t;
			if(t==0) {
				cout << curseg << "\n";
			} else {
				
				cin >> x >> y;
				
				--x;
				if(s[x])
					continue;
				a[x]+=y;
				if(a[x]<=k)
					continue;
				s[x]=1;
				if(x&&x<n-1) {
					if(s[x-1]==s[x+1]&&s[x-1]==0) {
						++curseg;
					} else if(s[x-1]==s[x+1]&&s[x-1]==1) {
						--curseg;
					}
				} else if(x==0) {
					if(x<n-1&&s[x+1]==1) {
						continue;
					}
					++curseg;
				} else if(x==n-1) {
					if(x>0&&s[x-1]==1) {
						continue;
					}
					++curseg;
				}
			}
		}


	}


}
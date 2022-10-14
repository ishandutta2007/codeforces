#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define nl "\n"
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
const ll mod = 1e9+7; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod() : x(0) {}
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


template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};


template<class T>
struct RG {
	vector<vector<T>> jmp;
	RG(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = __gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return __gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
bool ch(int l, int r, RMQ<int> &a, RG<int> &b) {
	return a.query(l, r+1) == b.query(l, r+1);
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int &i : a)
		cin >> i;
	RMQ<int> ax(a);	
	RG<int> by(a);
	int lb = 1, rb = n;
	vi ans;
	int choice=1;
	while(lb < rb) {
		int mid=(lb+rb+1)/2;
		vi res;
		for(int i=0;i<n-mid+1;i++) {
			if(ch(i,i+mid-1, ax, by))
				res.push_back(i+1);
		}
		if(sz(res))
			ans=res, lb=mid, choice=mid;
		else rb=mid-1;
	}
	if(choice==1) {
		ans.clear();
		rep(i,0,n)
			ans.push_back(i+1);
	}
	cout << sz(ans) << " " << choice - 1 << "\n";
	for(int i : ans)
		cout << i << " ";
}
int32_t main() {
    int t = 1;
    while(t--) {
        solve();
    }
}
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


void solve() {
	int N; ll K;
	scanf("%d%lld", &N, &K);
	ll a[N]; rep(i,0,N) cin >> a[i];
	vector<vector<Mod>> mat(N + 1, vector<Mod>(N + 1));
	rep(i,0,N) rep(j,0,N)
		mat[i][j] = Mod(__builtin_popcountll(a[i] ^ a[j]) % 3 == 0);
	rep(i,0,N)
		mat[i][N]=1;
	auto mul = [&](vector<vector<Mod>> a, vector<vector<Mod>> b) -> vector<vector<Mod>> {
		vector<vector<Mod>> m(N+1, vector<Mod>(N+1));
		rep(i,0,N+1) rep(j,0,N+1)
			rep(k,0,N+1)
				m[i][j] = m[i][j] + (a[i][k] * b[k][j]);
		return m;
	};

	auto matrix_exp = [&](vector<vector<Mod>> a, ll M) -> vector<vector<Mod>> {
		vector<vector<Mod>> temp(N + 1, vector<Mod> (N + 1));
		rep(i,0,N+1)
			temp[i][i]=Mod(1);
		while(M) {
			if(M&1)
				temp=mul(temp,a);
			a = mul(a, a);
			M >>= 1;
		}
		return temp;
	};
	auto M = matrix_exp(mat, K);
	Mod ans;
	//rep(i,0,N+1) {
		//rep(j,0,N+1) cout << M[i][j].x << " ";
		//cout << nl;
	//}
	rep(j,0,N) {
		ans = ans + M[j][N];
	}
	cout << ans.x << "\n";


	
}
int32_t main() {
    int t = 1;
    while(t--) {
        solve();
    }
}
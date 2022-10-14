#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F0R(i,N) rep(i,0,N)
#define P pair
ll n, m, k;
const int mxN=1e5,M=998244353,mod=1e9+7;
const ll MOD = 1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)





ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		rep(j,i+1,n) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
		rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	rep(i,0,n) rep(j,0,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
	return n;
}
vector<pii> generalMatching(int N, vector<pii>& ed) {
	vector<vector<ll>> mat(N, vector<ll>(N)), A;
	for (pii pa : ed) {
		int a = pa.first, b = pa.second, r = rand() % mod;
		mat[a][b] = r, mat[b][a] = (mod - r) % mod;
	}

	int r = matInv(A = mat), M = 2*N - r, fi, fj;
	assert(r % 2 == 0);

	if (M != N) do {
		mat.resize(M, vector<ll>(M));
		rep(i,0,N) {
			mat[i].resize(M);
			rep(j,N,M) {
				int r = rand() % mod;
				mat[i][j] = r, mat[j][i] = (mod - r) % mod;
			}
		}
	} while (matInv(A = mat) != M);

	vi has(M, 1); vector<pii> ret;
	rep(it,0,M/2) {
		rep(i,0,M) if (has[i])
			rep(j,i+1,M) if (A[i][j] && mat[i][j]) {
				fi = i; fj = j; goto done;
		} assert(0); done:
		if (fj < N) ret.emplace_back(fi, fj);
		has[fi] = has[fj] = 0;
		rep(sw,0,2) {
			ll a = modpow(A[fi][fj], mod-2);
			rep(i,0,M) if (has[i] && A[i][fj]) {
				ll b = A[i][fj] * a % mod;
				rep(j,0,M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
			}
			swap(fi,fj);
		}
	}
	return ret;
}
void solve(int test_case = 0) {
    // first i drop my top ayy
    // then i swerve my couple ayy
    // couting all these bands huh
    // who the fuck are you ayy
    //
    
    int n; cin >> n;
    vector<vi> g(n);
    vi a(n);
    F0R(i,n) cin>>a[i],--a[i];
    bool u[100];
    fill(u,u+100,false);
    F0R(i,n) u[a[i]]=true;
    vector<pii> ed;
    rep(i,0,n) {
        rep(j,i+1,n) {
            if(a[i]%2==a[j]%2)
                ed.pb({i,j});
            else if(abs(a[i]-a[j])==1)
                ed.pb({i,j});
        }
    }
    vector<pii> result = generalMatching(n,ed); 
    if(sz(result) == n / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}


int main()
{
    //setup();
    cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
    cin >> T;
    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}
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
#define nl '\n'
#define vi vector<int>
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
#define P pair
int n, m, k;
const int mxN=1e6,M=998244353,mod=1e9+7;
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
const ll MOD = 1e9+7;

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
struct RQ {
	vector<vector<T>> jmp;
	RQ(const vector<T>& V) : jmp(1, V) {
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


vi a;
void solve(int test_case = 0) {
	map<int, int> st;
	
	int n; cin >> n;
	vector<vi> store(n);
	a.resize(n);
	rep(i,0,n) {
		cin >> a[i];
		st[a[i]]=i;
	}
	rep(i,0,n) {
		store[st[a[i]]].pb(i);
	}
	RMQ<int> tmp(a);
	RQ<int> gcds(a);
	int q; cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		int mn = tmp.query(l,r+1);
		int gd = gcds.query(l,r+1);
		if(gd%mn==0) {
			int ot = r - l + 1;
			int idx = st[mn];
			int ct = (ub(all(store[idx]), r)) - (lb(all(store[idx]), l));
			cout << ot - ct << "\n";
		} else {
			cout << (r-l+1) << "\n";
		}
	}
}


int main()
{
	//setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
	// cin >> T;
	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define gen generate
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi V<int>
#define pii pair<int, int>
#define vl V<ll>
#define vpi V<pi>
#define vpl V<pl>
#define trav(x,y) for(auto &x:y)
#define vb V<bool>
#define bs bitset
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F0R(i,N) rep(i,0,N)
#define P pair


const int mxN=1e5,M=998244353,mod=1e9+7;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, V<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


inline ll nxt() {
    ll x; cin >> x;
    return x;
}
inline string read() {
    string a; cin >> a;
    return a;
}
template<class T> bool umax(T &x, T y) {
    if(x < y) {
        x = y;
        return 1;
    }
    return 0;
}
template<class T> bool umin(T &x, T y) {
    if(x > y) {
        x = y;
        return 1;
    }
    return 0;
}


void solve(int test_case = 0) {
	int k; cin >> k;

	for(int i=1;i<=1e9;i++) {
		if(i%3==0) continue;
		if(i%10==3) continue;
		--k;
		if(k==0) {
			cout << i << nl;
			return;
		}
	}
	cout << -1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    for(int nt = 0, i; nt < t; nt++) {
        solve(nt);
        ++i;
    }
}
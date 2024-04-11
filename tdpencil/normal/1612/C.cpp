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


const int mxN=1e5,M=998244353,mod=1e9+7;
const ll MOD = 1e9+7;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)













































// right, down, left, up
inline ll nxt() {
	ll x; cin >> x;
	return x;
}


void solve(int test_case = 0) {
	ll k, x;
	cin >> k >> x;
	// (n * (n + 1) / 2) <= x)
	// (n * (n + 1)) <= 2 * x
	// (n*n + n) <= 2 * x
    if(x >= k * k) {
        cout << 2*k - 1 << nl;
        return;
    }
	ll l = 0, r = 2*k-1;
	auto qry = [&](int am) -> ll {
		if(am > k) {
			ll r = am - k;
			ll l = k - r;
			if(l <= 0)
				return k * (k + 1) / 2;
			r = l + r - 1;
			return k * (k + 1) / 2 + r * (r + 1) / 2 - l * (l - 1) / 2;

		} else {
			return 1LL * am * (am + 1) / 2;
		}
	};

    while(l < r) {
        ll mid = (l + r + 1) / 2;
        if(qry(mid) > x)
            r = mid - 1;
        else
            l = mid;
    }

    if(qry(l) < x)
        cout << l + 1 << "\n";
    else
        cout << l << nl;

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
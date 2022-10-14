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

const ll MAX_LIMIT = 1e16;
void solve(int test_case = 0) {
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> dist(n, MAX_LIMIT);
	vector<int> prohibitedCities(k);
	vector<vector<pii>> graph(n);
	vector<bool> visited(n);

	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		graph[x].pb({y,w});
		graph[y].pb({x,w});
	}

	generate(all(prohibitedCities), nxt);
	// return;
	if(k == 0) {
		cout << "-1" << "\n";
		return;
	}
	pqg<pl> q;
	for(int i = 0; i < k; i++)
		dist[prohibitedCities[i] - 1] = 0, q.push({0, prohibitedCities[i] - 1});

	while(!q.empty()) {
		pl t = q.top();
		q.pop();
		if(visited[t.s])
			continue;
		visited[t.s] = 1;

		for(pii e : graph[t.s]) {
			if(e.s + t.f < dist[e.f]) {
				dist[e.f] = e.s + t.f;
				q.push({dist[e.f], e.f});
			}
		}
	}
	// return;
	ll mx = MAX_LIMIT;
	for(int i = 0; i < n; i++)
		if(dist[i] != 0 && dist[i] != MAX_LIMIT)
			mx = min(mx, dist[i]);

	cout << (mx == MAX_LIMIT ? -1 : mx) << nl;



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
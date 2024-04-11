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
string s;
ll c;
int st[1<<3];
void solve(int test_case = 0) {
	fill(st,st+(1<<3),int(2e9));
	int n; cin >> n;
	rep(i,0,n) {
		cin >> c;
		cin >> s;
		int lp=0;
		for(char ch : s)
			lp^=1<<(ch-'A');
		st[lp]=min(st[lp],(int)c);
	}
	ll ans=2e9;
	vi r;
	for(int s=7;s;s=(s-1)&7)
		r.pb(s);
	for(int i=0;i<(1<<sz(r));++i)
	{
		c=0;
		int v=0;
		for(int j=0;j<sz(r);++j)
			if((1<<j)&i)
				c+=st[r[j]],v|=r[j];
		if(v==(1<<3)-1)
			ans=min(ans,c);
	}
	cout << (ans==int(2e9)?-1:ans) << "\n";
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
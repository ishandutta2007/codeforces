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
const int mxN=1e5,M=998244353,mod=1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
// void dbg_out() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
const ll MOD = 1e9+7;
int a[200000][26];
bool ch(vi &cnt, int l) {
	rep(j,0,26) {
		if(cnt[j]>a[l][j])
			return 0;
	}	
	return 1;
}
void solve(int test_case = 0) {
	cin >> n;
	string s; cin >> s;	

	for(int i=0;i<n;++i) {
		if(i==0) {
			a[i][s[i]-'a']++;
		} else {
			rep(j,0,26) {
				a[i][j]=a[i-1][j];
			}
			a[i][s[i]-'a']++;
		}
	}

	int q; cin >> q;
	while(q--) {
		string t; cin >> t;
		vi c(26);
		rep(i,0,sz(t))
			++c[t[i]-'a'];
		int lb = 0, rb = n;
		while(lb < rb) {
			int mid=(lb+rb)/2;
			if(ch(c,mid))
				rb=mid;
			else
				lb=mid+1;
		}
		cout << lb+1 << nl;
	}
	
}
int main()
{
	
	//setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
	//cin >> T;
	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}
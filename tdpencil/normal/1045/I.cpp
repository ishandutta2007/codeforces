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

void solve(int test_case = 0) {
	int n; cin >> n;	
	vi c(n);
	for(int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		for(char ch : temp) {
			c[i] ^= (1 << (ch - 'a'));
		}
	}
	// now just count how many pairs of bits are the same
	map<int, int> cnt;
	map<int, int> cnt2;	
	for(int i = 0; i < n; ++i) {
		++cnt[c[i]];
	}
	ll ans=0;
	trav(pr, cnt) {
		ans+=1LL*pr.s*(pr.s-1)/2;
		for(int j=0;j<26;j++) {
			if(!(pr.f&(1<<j))) {
				if(cnt.count(pr.f^1<<j))
					ans += 1LL*(pr.s)*cnt[pr.f^(1<<j)];
			}
		}
	}
	cout << ans << "\n";
}


int main()
{
    //setup();
	cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
//    cin >> T;
    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
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
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

ll n, m, k;
const int mxN=1e6,M=1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int test_case = 0) {
	cin >> n >> k;


	ll A[n];
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	
	ll lb = n * n - k * 2 * n;
	ll ans=-2e9;
	for(ll i = n - 1; i >= 0; --i) {
		for(ll j = n - 1; j >= 0; --j) {
			if(i == j)
				continue;
			ll res = (i+1) * (j+1);
			if(res<lb)
				break;
			ans=max(ans,res-k*(A[i]|A[j]));
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
    cin >> T;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}
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
const int mxN=1e6,M=998244353;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



void solve(int test_case = 0) {
	ll ans = 0;
	int n; cin >> n;
	ll s[n]={};
	ll p[n]={};
	ll a[n]={};
	rep(i,0,n) {
		s[i]=0;
		p[i]=0;
		cin >> a[i];
		if(i)
			p[i]=p[i-1]+a[i];
		else
			p[i]=a[i];
	}
	for(int i = n-1; ~i; --i) {
		if(i+1<n)
			s[i]=s[i+1]+a[i];
		else
			s[i]=a[i];
	}


	for(int i = 0; i < n; ++i) {
		ll x = p[i];
		int lb = i + 1, rb = n;
		bool w = 0;
		while(lb <= rb) {
			int mid = (lb + rb) / 2;
			if(s[mid] == x) {
				w = 1;
				break;
			} else if(s[mid] < x) {
				rb = mid - 1;
			} else {
				lb = mid + 1;
			}
		}
		if(w) {
			ans=max(ans,x);
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
    // cin >> T;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}
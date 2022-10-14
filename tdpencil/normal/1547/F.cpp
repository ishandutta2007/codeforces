#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define ll long long
#define vi vector<int>
#define vt vector
#define vl vector<ll>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

ll n, m, k;
const int mxN=3e5,M=1e9+7;
ll a[mxN];


bool all_same() {
	ll res=a[0];
	bool w = 1;
	for(int i = 1; i < n; ++i)
		w &= a[i] == res;
	return w;
}
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
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
void solve(int test_case = 0) {
    int n; cin >> n;
    vi a(n);
    for(auto &i : a)
        cin >> i;
    
    int lo = 0, hi = n;
    RMQ<int> Q(a);
    while(lo < hi) {
        int mid = (lo + hi) >> 1;
        vector<int> t(n);

        for(int i = 0; i < n; ++i) {
            int lb = i, rb = (i + mid) % n;
            if(lb > rb) {
                t[i] = __gcd(Q.query(lb, n), Q.query(0, rb + 1));
            } else {
                t[i] = (Q.query(lb, rb + 1));
            }
        }
        sort(all(t));

        if(t[0] == t[n - 1]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << nl;
}

int main()
{
	 //setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
	cin >> T;

	for(int nt = 0, i; nt < T; nt++) {
		solve();
		++i;

	}
}
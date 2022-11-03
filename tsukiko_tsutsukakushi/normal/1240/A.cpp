/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; cin >> n;
    vector<ll> p(n);
    rep(i, n) {
        cin >> p[i]; p[i] /= 100;
    }
    int x, a; cin >> x >> a;
    int y, b; cin >> y >> b;
    if(x < y) {
        swap(x, y);
        swap(a, b);
    }
    ll k; cin >> k;
    auto check = [&](int co) -> bool {
        ll sum = 0;
        sort(p.begin(), p.begin() + co);
        reverse(p.begin(), p.begin() + co);
        int cab = co / (a / __gcd(a, b) * b);
        int ca = co / a - cab, cb = co / b - cab;
        rep(i, co) {
            if(i < cab) sum += p[i] * (x + y);
            else if(i < cab + ca) sum += p[i] * x;
            else if(i < cab + ca + cb) sum += p[i] * y;
        }
        return sum >= k;
    };
    if(!check(n)) {
        cout << -1 << "\n";
        return;
    }
    int ok = n, ng = 0;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}
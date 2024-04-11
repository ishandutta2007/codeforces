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

bool check(string a, string b) {
    int n = (int)a.size(), m = (int)b.size();
    if(m % n != 0) return false;
    rep(i, m) {
        if(b[i] != a[i % n]) return false;
    }
    return true;
}

void solve() {
    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    string lcm = "-1";
    for(int i = n; i >= 1; -- i) {
        string gcd = s.substr(0, i);
        if(check(gcd, s) and check(gcd, t)) {
            lcm = "";
            int a = n / i, b = m / i;
            int cnt = a * b / __gcd(a, b);
            rep(_, cnt) {
                lcm += gcd;
            }
            break;
        }
    }
    cout << lcm << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}
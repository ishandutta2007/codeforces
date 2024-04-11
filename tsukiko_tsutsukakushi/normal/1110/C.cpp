/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void test(int MAX) {
    for(int a = 2; a <= MAX; ++ a) {
        int bb = -1, c = -1;
        for(int b = 1; b < a; ++ b) {
            if(chmax(c, __gcd(a ^ b, a & b))) bb = b;
        }
        cout << a << " " << bb << " " << c << endl;
    }
    exit(0);
    return;
}

void solve() {
    // test(65);
	int a; cin >> a;
    int n = 0;
    while(a >= (1<<n)) {
        ++ n;
    }
    if(a == (1<<n) - 1) {
        int ans = 1;
        for(int i = 2; i * i <= a; ++ i) {
            if(a % i == 0) {
                chmax(ans, a / i);
                chmax(ans, i);
            }
        }
        cout << ans << endl;
    } else {
        cout << (1<<n) - 1 << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}
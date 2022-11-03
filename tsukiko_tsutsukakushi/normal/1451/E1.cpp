/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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

void solve() {
    int n; cin >> n;
    vector<int> res(n + 1, 0);
    for(int i = 1; i < n; ++ i) {
        cout << "XOR " << i - 1 + 1 << " " << i + 1 << endl;
        fflush(stdout);
        cin >> res[i + 1];
    }
    int a, b, c;
    cout << "AND 1 2" << endl;
    fflush(stdout);
    cin >> a;
    cout << "AND 2 3" << endl;
    fflush(stdout);
    cin >> b;
    cout << "AND 1 3" << endl;
    fflush(stdout);
    cin >> c;
    int sum = res[2] + 2 * a + res[3] + 2 * b + (res[2] ^ res[3]) + 2 * c;
    assert(sum % 2 == 0);
    sum /= 2;
    vector<int> ans(n);
    ans[0] = sum - (res[3] + 2 * b);
    assert(ans[0] >= 0 and ans[0] < n);
    for(int i = 1; i < n; ++ i) {
        ans[i] = (res[i + 1] ^ ans[i - 1]);
        assert(ans[i] >= 0 and ans[i] < n);
    }
    // assert(ans[1] == sum - ((res[0] ^ res[1]) + 2 * c));
    // assert(ans[2] == sum - (res[1] + 2 * a));
    cout << "!";
    rep(i, n) {
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}
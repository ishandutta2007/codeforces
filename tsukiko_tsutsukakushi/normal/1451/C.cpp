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

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<int> cnta(26, 0), cntb(26, 0);
    rep(i, n) {
        cnta[(a[i] - 'a')] ++;
        cntb[(b[i] - 'a')] ++;
    }
    int tmp = 0;
    rep(i, 26) {
        if(cnta[i] == cntb[i]) continue;
        else if(cnta[i] - cntb[i] > 0) {
            if((cnta[i] - cntb[i]) % k == 0) {
                tmp += (cnta[i] - cntb[i]) / k;
            } else {
                cout << "No\n";
                return;
            }
        } else { 
            if((cntb[i] - cnta[i]) % k == 0) {
                int need = (cntb[i] - cnta[i]) / k;
                if(need > tmp) {
                    cout << "No\n";
                    return;
                }
                tmp -= need;
            } else {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}
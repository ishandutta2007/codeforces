#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
typedef long long ll;
using namespace std;
ll n,i,j,k,m,q,timer,mx, v,tot,x,y,INF, sz,ans;
set<ll> used;
ll count_bits(ll y) {
    int ans= 0 ;
    while (y) {
        ans += y%2;
        y /= 2;
    }
    return ans;
}
int dirs[6][2] = {{3, 0}, {2, 1}, {1, 2}, {0, 3}, {-1, 2}, {-2, 1}};
void go(ll x) {
    if (used.find(x) != used.end())
        return;
    used.insert(x);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (!((x>>(i*m+j))&1)) {
            int flag = 0;
            for (int k = 0; k < 6; k++) {
                int ki = i+dirs[k][0];
                int kj = j+dirs[k][1];
                if (ki >= 0 && ki < n && kj >= 0 && kj < m && (!((x>>(ki*m+kj))&1))) {
                    flag = 1;
                    go(x | (1LL<<(i*m+j)) | (1LL<<(ki*m+kj)));
                }
            }
            if (flag)
                return;
        }
    }
    ans = max(ans, count_bits(x));
}
int pat1[6] = {0, 0, 0, 2, 4, 6};
int pat2[6] = {0, 2, 4, 8, 10, 12};
void solve() {

    if (n > m)
        swap(n, m);
    if (n >= 3) {
        cout << n*m - n*m%2 << endl;
        return;
    }
    if (n == 1) {
        m--;
        cout << (m/6)*6 + pat1[m%6] << endl;
        return;
    }
    if (n == 2) {
        if (m == 2) {
            cout << 0 << endl;
            return;
        }
        if (m == 1) {
            cout << 0 << endl;
        } else if (m == 3) {
            cout << 4 << endl;
        } else if (m == 7) {
            cout << 12 << endl;
        } else {
            cout << n*m << endl;
        }
        return;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);

    
    cin >> n >> m;
    solve();
    return 0;
}
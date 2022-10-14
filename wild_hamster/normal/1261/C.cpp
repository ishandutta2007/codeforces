#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 10000007
#define MOD 998244353
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
vector<vector<ll> > a, pa, pb, b;
bool shit(ll mid) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            b[i][j] = pb[i][j] = 0;
        }
    }

    ll inc = 2 * mid - 1;
    //cout << inc << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + inc - 1 <= n && j + inc - 1 <= m) {
                ll sum = pa[i+inc-1][j+inc-1] - pa[i-1][j+inc-1] - pa[i+inc-1][j-1] + pa[i-1][j-1];
                if (sum == inc * inc) {
                    b[i][j] = 1;
                }
            }
            pb[i][j] = pb[i-1][j] + pb[i][j-1] - pb[i-1][j-1] + b[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            ll pi = max(i - inc + 1, 1LL);
            ll pj = max(j - inc + 1, 1LL);
            ll sum = pb[i][j] - pb[pi-1][j] - pb[i][pj-1] + pb[pi-1][pj-1];
            if (a[i][j] == 1) {
                if (sum == 0) {
                    //cout << "blya1 " << i << " " << j << endl;
                    return false;
                }
            } else {
                if (sum > 0) {
                    //cout << "blya2 " << i << " " << j << endl;
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    a.resize(n+1);
    b.resize(n+1);
    pa.resize(n+1);
    pb.resize(n+1);
    a[0].resize(m+1);
    b[0].resize(m+1);
    pa[0].resize(m+1);
    pb[0].resize(m+1);
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 1);
        b[i].resize(m + 1);
        pa[i].resize(m + 1);
        pb[i].resize(m + 1);
        for (int j = 0; j <= m; j++) {
            pa[i][j] = 0;
        }
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
            pa[i][j] = pa[i-1][j] + pa[i][j-1] - pa[i-1][j-1] + a[i][j];
        }
    }

    ll l = 1, r = max(n, m) + 1;
    while (l < r) {

        ll mid = (l + r + 1) / 2;

        bool good = shit(mid);
        if (good) {
            l = mid;
        } else {
            r = mid - 1;
        }

    }
    bool pshe = shit(l);
    cout << l - 1 << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= l && j >= l && b[i-l+1][j-l+1] == 1) {
                cout << "X";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }


    return 0;
}
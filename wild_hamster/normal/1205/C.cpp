#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 1488228
ll x, y, n, m, k;
ll a[505][505], res[505][505];
vector<ll> g[205];
ll ask(ll x1, ll y1, ll x2, ll y2){
    if (x1 + y1 + 2 > x2 + y2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    fflush(stdout);
    ll ans;
    cin >> ans;
    return ans;
}

ll good(ll x, ll y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && a[x][y] != -1;
}

ll asks[6][2] = {{-2, 0}, {-1, -1}, {0, -2}, {2, 0}, {1, 1}, {0, 2}};
void determine(ll x, ll y) {
    for (int i = 0; i < 6; i++) {
        ll askx = x + asks[i][0];
        ll asky = y + asks[i][1];
        if (good(askx, asky)) {
            ll ans = ask(askx, asky, x, y);
            if (ans) {
                a[x][y] = a[askx][asky];
            } else {
                a[x][y] = 1 - a[askx][asky];
            }
            break;
        }
    }
}

ll b[3][3];
ll dirs[2][2] = {{1, 0}, {0, 1}};

ll fnd(ll x1, ll y1, ll x2, ll y2) {
    if (b[x1][y1] != b[x2][y2]) {
        return 0;
    }
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (i + j == x1 + y1 || i + j == x2 + y2) {
                continue;
            }
            for (int k = 0; k < 2; k++) {
                ll nx = i + dirs[k][0];
                ll ny = j + dirs[k][1];
                if (nx < x1 || nx > x2 || ny < y1 || ny > y2) {
                    continue;
                }
                if (nx + ny == x1 + y1 || nx + ny == x2 + y2) {
                    continue;
                }
                if (b[nx][ny] == b[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void do_fucking_magic(ll x, ll y) {
    ll ask1 = ask(x, y, x + 1, y + 2);
    ll ask2 = ask(x, y + 1, x + 2, y + 2);
    ll ask3 = ask(x + 1, y, x + 2, y+2);
    ll ask4 = ask(x, y, x+2, y+1);
    ll ask5 = ask(x, y+1, x+1, y+2);
    ll ask6 = ask(x+1, y, x+2, y+1);

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            b[j][k] = a[x+j][y+k];
        }
    }
    for (int j = 0; j < 16; j++) {
        vector<ll> f;
        ll xx = j;
        for (int k = 0; k < 4; k++) {
            f.push_back(xx % 2);
            xx /= 2;
        }
        b[0][1] = f[0];
        b[1][0] = f[1];
        b[2][1] = f[2];
        b[1][2] = f[3];
        ll pal1 = fnd(0, 0, 1, 2);
        ll pal2 = fnd(0, 1, 2, 2);
        ll pal3 = fnd(1, 0, 2, 2);
        ll pal4 = fnd(0, 0, 2, 1);
        ll pal5 = (b[0][1] == b[1][2]);
        ll pal6 = (b[1][0] == b[2][1]);
        if (ask1 == pal1 && ask2 == pal2 && ask3 == pal3 && ask4 == pal4 && ask5 == pal5 && ask6 == pal6) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    a[x+j][y+k] = b[j][k];
                }
            }
            //cout << "HYU" << endl;
            return;
        }
    }
}

void check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != res[i][j]) {
                cout << "Pidaras";
                exit(0);
            }
        }
    }
}

void print() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = -1;
        }
    }

    a[1][1] = 1;
    a[n][n] = 0;
    for (int i = 4; i <= 2 * n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - j >= 1 && i - j <= n && a[j][i-j] == -1) {
                determine(j, i - j);
            }
        }
    }
    //print();
    ll flag = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (good(i + 2, j + 2) && good(i, j) && a[i+2][j+2] != a[i][j]) {
                do_fucking_magic(i, j);
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    //print();
    for (int k = 0; k < n*n; k++) {
        ll flag = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == -1) {
                    determine(i, j);
                    flag = 1;
                }
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
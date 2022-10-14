#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>

#define X first
#define Y second
#define mp make_pair
#define MOD 998244353
#define pii pair<ll,ll>

typedef int ll;
using namespace std;
#define MAXN 400228
#define SQ 700
ll x, y, n, m, k, i, j, q;
ll a[1005][1005], used[1005000];
map<ll, ll> f;

void check(ll n) {
    set<ll> f;
    set<ll> g;
    for (int i = 0; i < n; i++) {
        ll sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            sum1 ^= a[i][j];
            sum2 ^= a[j][i];
            g.insert(a[i][j]);
            if (a[i][j] >= n*n || a[i][j] < 0) {
                cout << "Pidor" << endl;
            }
        }
        f.insert(sum1);
        f.insert(sum2);
    }
    if (f.size() != 1 || g.size() != n*n) {
        cout << "Pidor" << " " << n << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void solve(ll n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = -1;
        }
    }
    for (int i = 1; i <= n*n; i++) {
        used[i] = 0;
    }

    ll k;
    for (int j = 1; j <= 22; j++) {
        if ((1 << j) > n * n - 1) {
            k = (1 << (j - 1));
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        a[i][i] = k + i;
        used[k+i] = 1;
    }
    ll cur = k - 1;
    for (int i = 0; i < n; i++) {
        ll p = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1) {
                if (p == 0) {
                    a[i][j] = cur;
                    p++;
                } else if (p == 1) {
                    a[i][j] = k - 1 - cur;
                    break;
                }
            }
        }
        used[cur] = used[k - 1 - cur] = 1;
        cur--;

        p = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == -1) {
                if (p == 0) {
                    a[j][i] = cur;
                    p++;
                } else if (p == 1) {
                    a[j][i] = k - 1 - cur;
                    break;
                }
            }
        }
        used[cur] = used[k-1-cur] = 1;
        cur--;
    }
    ll pos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1) {
                while (used[pos]) {
                    pos++;
                }
                a[i][j] = pos++;
            }
        }
    }
}

int main() {
    int b[4][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11},
            {12, 13, 14, 15}
    };
    cin >> n;
    for (int i = 0; i < n/4; i++) {
        for (int j = 0; j < n/4; j++) {
            ll cur = i * n/4 * 16 + j * 16;
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    a[i*4+k][j*4+l] = cur + b[k][l];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
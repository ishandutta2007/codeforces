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
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN], ans[MAXN];
vector<ll> f;

ll imp(ll x) {
    if (x == 0) {
        if (b[1] > 0)
            return 1;
        return -2;
    }
    if (x == 3) {
        if (b[2] > 0)
            return 2;
        return -2;
    }
    if (x == 1) {
        if (b[0] > 0 && b[2] <= 0) {
            return 0;
        }
        if (b[0] <= 0 && b[2] > 0) {
            return 2;
        }
        if (b[0] <= 0 && b[2] <= 0) {
            return -2;
        }
    }
    if (x == 2) {
        if (b[1] > 0 && b[3] <= 0) {
            return 1;
        }
        if (b[1] <= 0 && b[3] > 0) {
            return 3;
        }
        if (b[1] <= 0 && b[3] <= 0) {
            return -2;
        }
    }
    return -1;
}

ll Abs(ll x) {
    return x > 0 ? x : -x;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n = 0;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        n += a[i];
    }
    if (n == 1) {
        cout << "YES\n";
        for (int j = 0; j < 4; j++) {
            if (a[j] > 0) {
                cout << j << endl;
                return 0;
            }
        }
    }
    if (n == 2) {
        vector<ll> g;
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < a[j]; i++) {
                g.push_back(j);
            }
        }
        sort(g.begin(), g.end());
        if (g[1] - g[0] != 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << g[0] << " " << g[1] << endl;
        }
        return 0;
    }
    for (int l = 0; l < 4; l++) {
        for (int r = 0; r < 4; r++) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
            }
            bool hyu = false;
            b[l]--;
            b[r]--;
            if (b[l] < 0 || b[r] < 0) {
                continue;
            }
            ans[0] = l;
            ans[n-1] = r;
            ll L = 1;
            ll R = n - 2;
            while (L < R) {
                ll cur1 = imp(ans[L-1]);
                ll cur2 = imp(ans[R+1]);
                if (cur1 == -2 || cur2 == -2) {
                    hyu = true;
                    break;
                }
                if (cur1 != -1) {
                    ans[L++] = cur1;
                    b[cur1]--;
                } else if (cur2 != -1) {
                    ans[R--] = cur2;
                    b[cur2]--;
                } else {
                    if (ans[L-1] == 1) {
                        ans[L++] = 0;
                        b[0]--;
                    } else {
                        ans[L++] = 3;
                        b[3]--;
                    }
                }
            }
            ll lol = 0;
            for (int j = 0; j < 4; j++) {
                if (b[j] < 0) {
                    hyu = true;
                }
                if (b[j] > 0) {
                    lol = j;
                }
            }
            ans[L] = lol;
            if (Abs(lol - ans[L-1]) != 1 || Abs(lol - ans[L+1]) != 1) {
                hyu = true;
            }

            if (!hyu) {
                cout << "YES\n";
                /*for (int i = 0; i < 4; i++) {
                    cout << b[i] << "\n";
                }*/
                for (int i = 0; i < n; i++) {
                    cout << ans[i] << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
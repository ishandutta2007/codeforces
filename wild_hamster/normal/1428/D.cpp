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
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 1000000007
#define NN 1000000
ll n, m, k, w, r;
ll c[1005000], b[1005000], a[1005005], dp[1005000], maxdp[1005000];
ll t, x, y, z;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
vector<pii> ans;
vector<ll> g[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b[i] = x;
        g[x].push_back(i);
    }
    ll pos = 1;
    if (g[3].size() > 0) {
        for (int i = 0; i + 1 < g[3].size(); i++) {
            ll x = g[3][i];
            ll y = g[3][i+1];
            ans.push_back(mp(pos, x));
            ans.push_back(mp(pos, y));
            pos++;
        }
        ll lst = g[3].back();
        ll two = -1;
        for (int i = lst + 1; i < n; i++) {
            if (b[i] == 2) {
                two = i;
                break;
            }
        }
        if (two != -1) {
            ll one = -1;
            for (int i = two + 1; i < n; i++) {
                if (b[i] == 1) {
                    one = i;
                    break;
                }
            }
            if (one == -1) {
                cout << -1 << "\n";
                return 0;
            }
            ans.push_back(mp(pos, lst));
            ans.push_back(mp(pos, two));
            pos++;
            ans.push_back(mp(pos, two));
            ans.push_back(mp(pos, one));
            pos++;
            b[two] = 0;
            b[one] = 0;
        } else {
            ll one = -1;
            for (int i = lst + 1; i < n; i++) {
                if (b[i] == 1) {
                    one = i;
                    break;
                }
            }
            if (one == -1) {
                cout << -1 << "\n";
                return 0;
            }
            ans.push_back(mp(pos, lst));
            ans.push_back(mp(pos, one));
            pos++;
            ans.push_back(mp(pos, one));
            pos++;
            b[one] = 0;
        }
    }
    g[1].clear();
    g[2].clear();
    for (int i = 0; i < n; i++) {
        g[b[i]].push_back(i);
    }
    if (g[1].size() < g[2].size()) {
        cout << -1 << "\n";
        return 0;
    }
    ll diff = g[1].size() - g[2].size();
    for (int i = 0; i < g[2].size(); i++) {
        if (g[2][i] > g[1][i + diff]) {
            cout << -1 << "\n";
            return 0;
        }
        ans.push_back(mp(pos, g[2][i]));
        ans.push_back(mp(pos, g[1][i + diff]));
        pos++;
    }
    for (int i = 0; i < diff; i++) {
        ans.push_back(mp(pos++, g[1][i]));
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x.X << " " << x.Y + 1 << "\n";
    }
    return 0;
}
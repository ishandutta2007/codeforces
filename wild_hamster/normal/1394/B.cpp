
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
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii;
ll a[1000500], b[1005000], dp[1000500], used[1005000];
vector<pii> g[200500];
ll bad[10][10][10][10];
set<pii> ff[200500];
ll zalupa[10][10];
vector<ll> pshe;
ll ANS = 0;
void dfs(ll x) {
    if (x == k + 1) {
        bool flag = true;
        /*for (auto x : pshe) {
            cout << x;
        }
        cout << "\n";*/
        for (int i = 0 ;i < pshe.size(); i++) {
            for (int j = 0; j < pshe.size(); j++) {
                if (zalupa[i+1][pshe[i]] ||
                    zalupa[j+1][pshe[j]] ||
                    bad[i+1][pshe[i]][j+1][pshe[j]]) {
                    flag = false;
                }
            }
        }
        if (flag) {
           ANS++;
        }
        return;
    }
    for (int j = 1; j <= x; j++) {
        pshe.push_back(j);
        dfs(x+1);
        pshe.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[x].push_back(mp(z, y));
    }
    for (int i = 1; i <= n; i++ ){
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            auto x = g[i][j];
            ll hj = (ll)g[i].size();
            ll hk = j + 1;
            auto p = mp(hj, hk);
            if (ff[x.Y].find(p) != ff[x.Y].end()) {
                zalupa[hj][hk] = 1;
            } else {
                ff[x.Y].insert(p);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto x : ff[i]) {
            for (auto y : ff[i]) {
                if (x == y) {
                    continue;
                }
                if (!bad[x.X][x.Y][y.X][y.Y])
                //cout << x.X << " " << x.Y << " " << y.X << " " << y.Y << "\n";
                bad[x.X][x.Y][y.X][y.Y] = 1;
            }
        }
    }
    dfs(1);
    cout << ANS << "\n";
    return 0;
}
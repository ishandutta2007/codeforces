#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>
#include <assert.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 1000000000
#define OFF 2001
#define N 100000000
#define PI 3.14159265358979323846
ll n, x, k, z, m, pos, q, ans_v, y, mx;
ll x1, p1, x2;
ll a[100500];
ll w[27][27];
vector<ll> g[27];
ll used[27];
vector<ll> comp;
void dfs(ll v, ll p = - 1) {
    comp.push_back(v);
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        ll n = s.size();
        if (s.size() <= 1) {
            cout << "YES\n";
            for (int i = 0; i < 26; i++) {
                cout << char(i + 'a');
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i < 26; i++) {
            used[i] = 1;
            g[i].clear();
            for (int j = 0; j < 26; j++) {
                w[i][j] = 0;
            }
        }
        ll edges = 0;
        for (int i = 0; i + 1 < n; i++) {
            ll u = s[i]-'a';
            ll v = s[i+1]-'a';
            assert(u != v && u >= 0 && u < 26 && v >= 0 && v < 26);
            if (w[u][v] == 0) {
                g[u].push_back(v);
                g[v].push_back(u);
                w[u][v] = w[v][u] = 1;
                used[u] = used[v] = 0;
                edges++;
            }
        }
        ll x = 0;
        ll hyu = 0;
        for (int i = 0; i < 26; i++) {
            if (used[i] == 0) {
                x++;
            }
            if (g[i].size() > 2) {
                hyu = 1;
            }
        }

        if (edges + 1 == x && !hyu) {
            cout << "YES\n";
            comp.clear();
            for (int i = 0; i < 26; i++) {
                if (g[i].size() == 1) {
                    dfs(i);
                    break;
                }
            }
            for (int i = 0; i < 26; i++) {
                used[i] = 0;
            }
            for (auto x : comp) {
                used[x] = 1;
                cout << char(x+'a');
            }
            for (int i = 0 ;i < 26; i++) {
                if (!used[i]) {
                    cout << char(i+'a');
                }
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
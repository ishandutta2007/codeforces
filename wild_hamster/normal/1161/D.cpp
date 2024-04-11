#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[100500], b[100500];
ll dp[505][505], used[5005], pw[5005], color[5005];
pii se[200500], de[200500];
vector<pii> g[20002];
vector<ll> comp;
ll pred[2005];
void dfs(ll v) {
    if (used[v]) {
        return;
    }
    used[v] = 1;
    comp.push_back(v);
    for (auto to : g[v]) {
        dfs(to.X);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    pw[0] = 1;
    for (int i = 1; i <= 3000; i++) {
        pw[i] = pw[i-1] * 2 % MOD;
    }
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < (n + 1)/ 2; i++) {
        a[i] = a[n-1-i] = i;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ll cur = (n + 1)/ 2;
        ll tot = (cur + (i + 1) / 2);
        for (int j = 0; j < n; j++) {
            b[j] = -1;
        }
        /*for (int j = 0; j < n; j++) {
            if (s[j] != s[n-j-1] && s[j] != '?' && s[n-j-1] != '?' && j < n - i && n - j - 1 < n - i) {
            bad = true;
            }
        }*/
        for (int j = 0; j < tot - cur; j++) {
            b[n-j-1] = b[n-i+j] = cur + j;
        }
        for (int j = 0; j < tot; j++) {
            g[j].clear();
            used[j] = 0;
        }
        for (int j = n-i; j < n; j++) {
            if (s[j] == '?') {
                continue;
            }
            g[b[j]].push_back(mp(a[j], s[j] - '0'));
            g[a[j]].push_back(mp(b[j], s[j] - '0'));
        }

        ll k = 0;
        for (int j = 0; j < tot; j++) {
            if (used[j]) {
                continue;
            }
            comp.clear();
            dfs(j);
            ll cnt = 0;
            for (int l = 0; l < 2; l++) {
                for (auto v : comp) {
                    pred[v] = -1;
                }
                vector<ll> bfs;
                ll st = comp[0];
                bfs.push_back(st);
                ll it = 0;
                pred[st] = l;
                while (it < bfs.size()) {
                    ll v = bfs[it];
                    for (auto kv : g[v]) {
                        ll to = kv.X;
                        ll val = kv.Y;
                        if (pred[to] == -1) {
                            pred[to] = (pred[v] ^ val);
                            bfs.push_back(to);
                        }
                    }
                    it++;
                }
                bool bad = false;
                for (auto v : comp) {
                    for (auto kv : g[v]) {
                        ll to = kv.X;
                        ll val = kv.Y;
                        if ((pred[to]^pred[v]) != val ) {
                            bad = true;
                        }
                    }
                }
                for (auto v : comp) {
                    if (v == cur) {
                        if (pred[v] != 1) {
                            bad = true;
                            break;
                        }
                    }
                        if (v <= (n - 1) / 2 && v < n - i && s[v] != '?' && pred[v] != s[v] - '0') {
                            bad = true;
                            break;
                        }
                        if (v <= (n - 1) / 2 && n - v - 1 < n - i && s[n - 1 - v] != '?' && pred[v] != s[n-1-v]-'0') {
                            bad = true;
                            break;
                        }
                }

                //cout << i << " " << l << " " << bad << endl;
                if (!bad) {
                    cnt++;
                }
            }
            if (cnt == 0) {
                k = -1;
                break;
            }
            if (cnt == 2) {
                k++;
            }
        }
        //cout << i << " " << k << endl;
        if (k != -1)
        ans = (ans + pw[k]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
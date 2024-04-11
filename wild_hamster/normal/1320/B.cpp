
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
#define N 1000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[500500], b[500500], d[500500];
vector<ll> g[200500], gr[200500];
vector<ll> bfs;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[y].push_back(x);
        gr[x].push_back(y);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    bfs.push_back(b[k-1]);

    ll i = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = MOD;
    }
    d[b[k-1]] = 0;
    while (i < bfs.size()) {
        ll v = bfs[i++];
        for (auto to : g[v]) {
            if (d[to] == MOD) {
                d[to] = d[v] + 1;
                bfs.push_back(to);
            }
        }
    }
    ll l = 0;
    ll r = 0;
    for (int i = 0; i + 1 < k; i++) {
        ll x = d[b[i]];
        ll sum = 0;
        if (d[b[i+1]] + 1 != d[b[i]]) {
            l++;
            continue;
        }
        for (auto v : gr[b[i]]) {
            if (d[v] == x - 1) {
                sum++;
            }
        }
        //cout << sum << "\n";
        if (sum > 1) {
            r++;
        }
    }
    cout << l << " " << l+r << "\n";
    return 0;
}
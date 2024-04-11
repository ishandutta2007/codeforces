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
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
vector<ll> g[200500];
vector<ll> hyu, f;
ll d1[200500], dn[200500];
vector<ll> bfs;
bool cmp(ll x, ll y) {
    return dn[x] - d1[x] > dn[y] - d1[y];
}
multiset<ll> ff;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        hyu.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        d1[i] = dn[i] = MOD;
    }
    d1[1] = 0;
    dn[n] = 0;

    bfs.clear();
    bfs.push_back(1);
    ll i = 0;
    while (i < bfs.size()) {
        ll v = bfs[i++];
        for (auto to : g[v]) {
            if (d1[to] == MOD) {
                d1[to] = d1[v] + 1;
                bfs.push_back(to);
            }
        }
    }

    bfs.clear();
    bfs.push_back(n);
    i = 0;
    while (i < bfs.size()) {
        ll v = bfs[i++];
        for (auto to : g[v]) {
            if (dn[to] == MOD) {
                dn[to] = dn[v] + 1;
                bfs.push_back(to);
            }
        }
    }



    ll mx = 0;
    sort(hyu.begin(), hyu.end(), cmp);
    for (auto v : hyu) {
        ff.insert(dn[v]);
    }
    for (auto v : hyu) {
        ff.erase(ff.find(dn[v]));
        if (ff.empty()) {
            break;
        }
        mx = max(mx, *(prev(ff.end())) + 1 + d1[v]);
    }
    cout << min(mx, d1[n]) << "\n";

    return 0;
}
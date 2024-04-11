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
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
ll N;
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[205000], b[200500], w[2005];
ll f[2];
vector<ll> g[2005], comp, tot_comp;
void dfs_sub(ll v, ll p = -1) {
    comp.push_back(v);
    tot_comp.push_back(v);
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs_sub(to, v);
    }
}
void dfs(ll v, ll p = -1) {
    w[v] = 1;
    ll cur = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        w[v] += w[to];
    }
    if (a[v] >= w[v]) {
        cout << "NO\n";
        exit(0);
    }
    tot_comp.clear();
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        comp.clear();
        dfs_sub(to, v);
        for (auto c : comp) {
            b[c] += cur;
        }
        cur += w[to];
    }
    b[v] = a[v] + 1;
    for (auto to : tot_comp) {
        if (b[to] >= a[v] + 1) {
            b[to]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> a[i];
        if (x == 0) {
            root = i;
            continue;
        }
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(root);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;

}
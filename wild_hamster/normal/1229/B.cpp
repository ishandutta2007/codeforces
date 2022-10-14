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
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll a[100500];
vector<ll> g[100500];

ll cur_sum;
map<ll, ll> hyu;

ll gcd(ll a, ll b) {
    if (a + b == 0) {
        return 0;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

void dfs(ll v, ll p = -1) {
    for (auto t : hyu) {
        cur_sum += t.X * t.Y;
        cur_sum %= MOD;
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        map<ll, ll> tmp = hyu;
        hyu.clear();
        for (auto t : tmp) {
            hyu[gcd(t.X, a[to])] += t.Y;
        }
        hyu[a[to]]++;
        dfs(to, v);
        hyu = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    hyu[a[0]] = 1;
    dfs(0);

    cout << cur_sum << endl;
    return 0;
}
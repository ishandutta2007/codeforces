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
#define MAXN 3000000
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[200500], b[MAXN], c[100500], primes[3000000];
vector<ll> g[3005000];
ll binpow(ll x, ll y) {
    if (y == 0) {
        return 1;
    }
    ll tmp = binpow(x, y / 2);
    tmp = tmp * tmp % MOD;
    if (y % 2) {
        return x * tmp % MOD;
    }
    return tmp;
}
ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll mulg(ll x, ll y) {
    return x * y % MOD;
}

void add(ll& x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}
vector<ll> prs;
ll used[MAXN];
vector<int> ans;
void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    ans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<MAXN; ++i)
        used[i] = false;
    ans.clear();
    for (int i=0; i<MAXN; ++i)
        if (!used[i])
            dfs (i);
    reverse (ans.begin(), ans.end());
}

int main() {
    for (int i = 2; i <= 2750131; i++) {
        primes[i] = 1;
    }
    for (int i = 2; i <= 2750131; i++) {
        if (i > 30000) {
            break;
        }
        if (primes[i]) {
            for (int j = i * i; j <= 2750131; j+=i) {
                primes[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 2750131; i++) {
        if (primes[i]) {
            prs.push_back(i);
        }
    }
    for (int i = 2; i <= 200000; i++) {
        if (i <= prs.size()) {
            a[i] = prs[i - 1];
        }
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                a[i] = i / j;
                break;
            }
        }
        g[i].push_back(a[i]);
    }
    topological_sort();
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        scanf("%d", &x);
        b[x]++;
    }
    for (auto x : ans) {
        while (b[x] > 0) {
            int p = x;
            printf("%d ", x);
            b[x]--;
            b[a[x]]--;
        }
    }
    return 0;
}
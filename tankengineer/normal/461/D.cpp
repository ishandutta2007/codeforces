#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

const int N = 100005, MOD = 1000000007;

pair<int, int> calInterval(int x, int y) {
    int l = abs(x - y) / 2, r = x + y < n ? (x + y) / 2 : (n - 1 - (x + y - n + 1)) / 2;
    return make_pair(l, r);
}

int fa[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        fa[u] = v;
    }
}

int solve(vector<pair<pair<int, int>, int> > &v, int n) {
    for (int i = 0; i <= n; ++i) {
        fa[i << 1] = i << 1; 
        fa[i << 1 | 1] = i << 1 | 1;
    }
    for (int i = 0; i < (int)v.size(); ++i) {
        int l = v[i].first.first, r = v[i].first.second + 1, delta = v[i].second;
        if (delta) {
            merge(l << 1, r << 1 | 1);
            merge(l << 1 | 1, r << 1);
        } else {
            merge(l << 1, r << 1);
            merge(l << 1 | 1, r << 1 | 1);
        }
    }
    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
        if (find(i << 1) == find(i << 1 | 1)) {
            return -N;
        }
        cnt += (find(i << 1) == (i << 1));
        cnt += (find(i << 1 | 1) == (i << 1 | 1));
    }
    return cnt / 2 - 1; 
}

int powmod(int n) {
    int ret = 1, mul = 2;
    while (n) {
        if (n & 1) {
            ret = (long long)ret * mul % MOD;
        }
        mul = (long long)mul * mul % MOD;
        n >>= 1;
    }
    return ret;
}

vector<pair<pair<int, int>, int> > interval[2];

int main() {
    scanf("%d%d", &n, &k);    
    for (int i = 0; i < k; ++i) {
        int x, y, sign;
        char ch[2];
        scanf("%d%d%s", &x, &y, ch);
        sign = ch[0] == 'o';
        --x, --y;
        interval[(x + y) & 1].push_back(make_pair(calInterval(x, y), sign));
    }
    int num = solve(interval[0], (n + 1) / 2) + solve(interval[1], n / 2);
    if (num < 0) {
        printf("0\n");
    } else {
        printf("%d\n", powmod(num));
    }
    return 0;
}
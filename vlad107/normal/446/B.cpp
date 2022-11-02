#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 1000100;
const long long INF = 1000000000000000000LL;

int n, m, k, p, sx[N], sy[N];
long long f[2][N];
long long ans;
multiset<long long> s;

void solve(int u, int t) {
    f[u][0] = 0;
    for (int i = 1; i <= k; i++) {
        multiset<long long>::iterator it = s.end();
        --it;
        long long x = *it;
        f[u][i] = f[u][i - 1] + x;
        s.erase(it);
        s.insert(x - t);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            sx[i] += x;
            sy[j] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        s.insert(sx[i]);
    }
    solve(0, m * p);
    s.clear();
    for (int i = 0; i < m; i++) {
        s.insert(sy[i]);
    }
    solve(1, n * p);
    // for (int i = 0; i <= k; i++) {
        // fprintf(stderr, "%d %d\n", f[0][i], f[1][i]);
    // }
    ans = -INF;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, f[0][i] + f[1][k - i] - p * 1LL * i * (k - i));
    }
    cout << ans << endl;
}
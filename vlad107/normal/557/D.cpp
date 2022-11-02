#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define pb push_back

using namespace std;

const int N = 2e5;

int n, m, cnt[2];
vector<int> g[N];
bool used[N][2];

void dfs(int x, int c) {
    if (used[x][c]) return;
    used[x][c] = 1;
    cnt[c]++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        dfs(y,c^1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if (m == 0) {
        printf("3 ");
        long long res = n;
        res *= (n - 1);
        res *= (n - 2);
        res /= 6;
        cout << res << endl;
        return 0;
    }
    long long sum = 0;  
    for (int i = 0; i < n; i++) {
        if ((!used[i][0]) && (!used[i][1])) {
            cnt[0] = cnt[1] = 0;
            dfs(i,0);
            sum += (cnt[0] - 1) * 1LL * cnt[0] / 2;
            sum += (cnt[1] - 1) * 1LL * cnt[1] / 2;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((used[i][0]) && (used[i][1])) {
            puts("0 1");
            return 0;
        }
    }
    bool found = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() >= 2) {
            found = 1;
        }
    }
    if (!found) {
        long long res = m;
        res *= n - 2;
        cout << 2 << " " << res << endl;
        return 0;
    }
    cout << 1 << " " << sum << endl;
}
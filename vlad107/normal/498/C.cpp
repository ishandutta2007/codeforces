#include <vector>
#include <algorithm>
#include <memory.h>
#include <iostream>

using namespace std;

const int N = 6666;
const int K = 666;

vector<pair<int, int>> v;
vector<int> h;
int used[N], mt[N], n, m, qqq;
bool can[K][K];

bool dfs(int x) {
    if (used[x] == qqq) return false;
    used[x] = qqq;
    for (int i = 0; i < h.size(); i++) {
        int y = h[i];
        if ((v[x].second == v[y].second) && (can[v[x].first][v[y].first])) {
            if ((mt[y] < 0) || (dfs(mt[y]))) {
                mt[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int xx = x;
        for (int j = 2; j * j <= xx; j++) {
            while (x % j == 0) {
                v.push_back(make_pair(i, j));
                if (i & 1) h.push_back(v.size() - 1);
                x /= j;
            }
        }
        if (x != 1) {
            v.push_back(make_pair(i, x));
            if (i & 1) h.push_back(v.size() - 1);
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        can[x][y] = can[y][x] = true;
    }
    memset(mt, -1, sizeof(mt));
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ++qqq;
        if ((v[i].first & 1) == 0) ans += dfs(i);
    }
    printf("%d\n", ans);
}
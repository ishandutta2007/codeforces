#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
bool u[maxn][maxn];

int main() {
    vector<pair<int, int>> v(3);
    for (int i = 0; i < 3; ++i) scanf("%d%d", &v[i].first, &v[i].second);
    vector<int> o(3);
    for (int i = 0; i < 3; ++i) o[i] = i;
    vector<pair<int, int>> ans;
    do {
        for (int s = 0; s < 4; ++s) {
            memset(u, false, sizeof(u));
            for (int i = 0; i < 3; ++i) u[v[i].first][v[i].second] = true;
            for (int i = 0; i < 2; ++i) {
                int x = v[o[i]].first, y = v[o[i]].second;
                if (s >> i & 1) {
                    while (x > v[o[i + 1]].first) u[x][y] = true, --x;
                    while (x < v[o[i + 1]].first) u[x][y] = true, ++x;
                    while (y > v[o[i + 1]].second) u[x][y] = true, --y; 
                    while (y < v[o[i + 1]].second) u[x][y] = true, ++y; 
                } else {
                    while (y > v[o[i + 1]].second) u[x][y] = true, --y; 
                    while (y < v[o[i + 1]].second) u[x][y] = true, ++y; 
                    while (x > v[o[i + 1]].first) u[x][y] = true, --x;
                    while (x < v[o[i + 1]].first) u[x][y] = true, ++x;
                }
            }
            vector<pair<int, int>> res;
            for (int i = 0; i < maxn; ++i) {
                for (int j = 0; j < maxn; ++j) 
                    if (u[i][j]) res.emplace_back(i, j);
            }
            if ((int)ans.size() == 0 || (int)res.size() < (int)ans.size()) ans = res;
        }
    } while (next_permutation(o.begin(), o.end()));
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0; 
}
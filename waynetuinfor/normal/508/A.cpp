#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const int dx[4][4] = {{-1, 0, -1, 0}, {0, 1, 0, 1}, {-1, 0, -1, 0}, {0, 1, 0, 1}}, dy[4][4] = {{-1, -1, 0, 0}, {-1, -1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
int g[maxn][maxn], n, m, k;

bool check(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int a, b; cin >> a >> b;
        g[a][b] = 1;
        for (int j = 0; j < 4; ++j) if (check(a, b, j)) return cout << i << endl, 0; 
    }
    cout << "0" << endl;
    return 0;
}

bool check(int a, int b, int id) {
    for (int i = 0; i < 4; ++i) {
        if (b + dx[id][i] >= 1 && b + dx[id][i] <= m && a + dy[id][i] >= 1 && a + dy[id][i] <= n) {
            if (g[a + dy[id][i]][b + dx[id][i]] == 0) return false;
        } else return false;
    }
    return true;
}
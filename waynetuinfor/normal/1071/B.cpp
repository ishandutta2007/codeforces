#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int maxc = 1e7 + 5;
char s[maxn][maxn];
int a[maxn][maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    if (k >= 2 * n - 1) {
        for (int i = 0; i < 2 * n - 1; ++i) printf("a");
        puts("");
        return 0;
    }
    a[0][0] = (s[0][0] == 'a');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) continue;
            a[i][j] = 0;
            if (i > 0) a[i][j] = max(a[i][j], a[i - 1][j]);
            if (j > 0) a[i][j] = max(a[i][j], a[i][j - 1]);
            if (s[i][j] == 'a') a[i][j]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int dis = i + j + 1;
            if (dis - a[i][j] <= k) s[i][j] = 'a';
        }
    }
    vector<pair<int, int>> pos = { make_pair(0, 0) };
    string bst = ""; bst += s[0][0];
    for (int i = 1; i < 2 * n - 1; ++i) {
        char z = 'z' + 1;
        vector<pair<int, int>> np;
        sort(pos.begin(), pos.end());
        pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
        for (int j = 0; j < pos.size(); ++j) {
            int x, y; tie(x, y) = pos[j];
            if (x + 1 < n) {
                if (s[x + 1][y] < z) z = s[x + 1][y], np = { make_pair(x + 1, y) };
                else if (s[x + 1][y] == z) np.emplace_back(x + 1, y);
            }
            if (y + 1 < n) {
                if (s[x][y + 1] < z) z = s[x][y + 1], np = { make_pair(x, y + 1) };
                else if (s[x][y + 1] == z) np.emplace_back(x, y + 1);
            }
        }
        bst += z, pos = np;
    }
    cout << bst << endl;
}
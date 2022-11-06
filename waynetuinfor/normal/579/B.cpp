#include <bits/stdc++.h>
using namespace std;

const int maxn = 800 + 5;
int a[maxn][maxn], to[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j < i; ++j) cin >> a[i][j], a[j][i] = a[i][j];
    }
    n <<= 1;
    for (int k = 0; k < n / 2; ++k) {
        bool ok = false;
        for (int i = 1; i <= n && !ok; ++i) if (!v[i]) {
            int s = 0, bst = 0;
            for (int j = 1; j <= n; ++j) if (!v[j]) {
                if (a[i][j] > s) s = a[i][j], bst = j;
            }
            s = 0; int bst2 = 0;
            for (int j = 1; j <= n; ++j) if (!v[j]) {
                if (a[bst][j] > s) s = a[bst][j], bst2 = j;
            }
            if (bst2 == i) to[i] = bst, to[bst] = i, ok = true, v[i] = v[bst] = true;
        }
    }
    for (int i = 1; i <= n; ++i) cout << to[i] << ' '; cout << endl;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

array<int, 2> path[N];
int perm[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
    }

    for (int i = 0, j = 0; i < n; ++i) {
        j = max(j, i + 1);
        while (j < n && perm[j] < perm[j - 1]) {
            ++j;
        }
        path[i][0] = j - i;
    }

    for (int i = n - 1, j = n - 1; i >= 0; --i) {
        j = min(j, i - 1);
        while (j >= 0 && perm[j] < perm[j + 1]) {
            --j;
        }
        path[i][1] = i - j;
    }

    int u = max_element(path, path + n) - path;
    bool ok = path[u][0] == path[u][1] && path[u][0] % 2 == 1;
    for (int i = 0; i < n; ++i) {
        if (i != u) {
            ok &= path[i][0] != path[u][0] && path[i][1] != path[u][0];
        }
    }

    cout << ok << "\n";
}
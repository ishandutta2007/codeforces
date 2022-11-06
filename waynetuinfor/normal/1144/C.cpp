#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    vector<int> v[2];
    for (int i = 0; i < n; ++i) v[i % 2].push_back(a[i]);
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j < (int)v[i].size(); ++j) {
            if (v[i][j] == v[i][j - 1]) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    reverse(v[1].begin(), v[1].end());
    for (int i = 0; i < 2; ++i) {
        printf("%d\n", (int)v[i].size());
        for (int j = 0; j < (int)v[i].size(); ++j)
            printf("%d ", v[i][j]);
        puts("");
    }
}
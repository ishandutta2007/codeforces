#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], ans[maxn];
vector<int> pos[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }
    int c = 1;
    for (int i = 0; i < n; ++i) {
        if ((int)pos[i].size() % (n - i) != 0) {
            puts("Impossible");
            return 0;
        }
        for (int j = 0; j < (int)pos[i].size(); j += n - i) {
            for (int k = 0; k < n - i; ++k) ans[pos[i][j + k]] = c;
            c++;
        }
    }
    puts("Possible");
    for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
    puts("");
    return 0;
}
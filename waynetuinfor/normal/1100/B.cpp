#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int cnt[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    multiset<int> ms;
    for (int i = 0; i < n; ++i) ms.insert(0);
    int r = 1;
    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        ms.erase(ms.find(cnt[x]));
        ++cnt[x];
        ms.insert(cnt[x]);
        if (*ms.begin() >= r) {
            printf("1");
            ++r;
        } else {
            printf("0");
        }
    }
    puts("");
    return 0;
}
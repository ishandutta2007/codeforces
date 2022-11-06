#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1e9 + 1;
int l[maxn], r[maxn];

int main() {
    int n; scanf("%d", &n);
    multiset<int> ls, rs;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        ls.insert(l[i]);
        rs.insert(r[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ls.erase(ls.find(l[i]));
        rs.erase(rs.find(r[i]));
        ans = max(ans, *rs.begin() - *ls.rbegin());
        ls.insert(l[i]);
        rs.insert(r[i]);
    }
    printf("%d\n", ans);
    return 0;
}
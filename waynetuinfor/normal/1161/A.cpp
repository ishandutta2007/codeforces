#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int x[maxn], cnt[maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) scanf("%d", &x[i]), ++cnt[x[i]];
    int ans = 0;
    set<int> s;
    set<pair<int, int>> pr;
    for (int i = k - 1; i >= 0; --i) {
        if (x[i] - 1 > 0 && s.count(x[i] - 1))
            pr.insert(make_pair(x[i], x[i] - 1));
        if (x[i] + 1 <= n && s.count(x[i] + 1))
            pr.insert(make_pair(x[i], x[i] + 1));

        s.insert(x[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0)
           ++ans;
        
        if (i - 1 > 0 && pr.count(make_pair(i, i - 1)) == 0)
           ++ans;

        if (i + 1 <= n && pr.count(make_pair(i, i + 1)) == 0)
           ++ans; 
    }
    printf("%d\n", ans);
    return 0;
}
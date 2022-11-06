#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int deg[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) ++deg[j];
    }
    int s = 0, p = 1;
    while (p <= n && s + deg[p] < k) s += deg[p], ++p;
    if (p > n) return 0 * puts("No");
    s += deg[p];
    set<pair<int, int>> st;
    // printf("p = %d\n", p);
    for (int i = (p + 2) / 2; i <= p; ++i) st.insert(make_pair(deg[i], i));
    // printf("s = %d\n", s);
    while (s > k) {
        auto it = prev(st.upper_bound(make_pair(s - k, maxn)));
        // printf("it = (%d, %d)\n", it->first, it->second);
        s -= it->first;
        st.erase(it);
    }
    puts("Yes");
    printf("%d\n", st.size() + p / 2);
    for (int i = 1; i <= p / 2; ++i) printf("%d ", i);
    for (auto it = st.begin(); it != st.end(); ++it) printf("%d ", it->second); puts("");
    return 0;
}
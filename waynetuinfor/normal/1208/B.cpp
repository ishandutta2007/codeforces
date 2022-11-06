#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    set<int> st;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        ok &= st.count(a[i]) == 0;
        st.insert(a[i]);
    }
    if (ok) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        map<int, int> cnt;
        int kind = 0;
        for (int j = i; j < n; ++j) {
            if (++cnt[a[j]] == 1) ++kind;
        }
        if (kind == n - i) {
            printf("%d\n", i);
            return 0;
        }
        for (int j = i; j < n; ++j) {
            if (--cnt[a[j]] == 0) --kind;
            if (++cnt[a[j - i]] == 1) ++kind;
            if (kind == n - i) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    assert(false);
}
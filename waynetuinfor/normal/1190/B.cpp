#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    map<int, int> cnt;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;

    for (auto it : cnt) {
        if (it.second >= 3) {
            puts("cslnb");
            return 0;
        }
    }

    int c = 0;
    for (auto it : cnt) {
        if (it.second >= 2) ++c;
        if (it.second >= 2 && cnt.count(it.first - 1) > 0) {
            puts("cslnb");
            return 0;
        }
    }

    if (c >= 2) {
        puts("cslnb");
        return 0;
    }

    if (cnt[0] >= 2) {
        puts("cslnb");
        return 0;
    }


    sort(a, a + n);
    long long diff = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= i)
            diff += a[i] - i;
    }

    if (diff & 1) puts("sjfnb");
    else puts("cslnb");

    return 0;
}
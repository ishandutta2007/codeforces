#include <bits/stdc++.h>
using namespace std;

multiset<int> ms[31];
long long sum[31];

int f(int x) {
    int res = 0;
    while (1 << (res + 1) <= x) ++res;
    return res;
}

int main() {
    int q; scanf("%d\n", &q);
    while (q--) {
        char c; int x;
        scanf("%c %d\n", &c, &x);
        int z = f(x);
        if (c == '+') ms[z].insert(x), sum[z] += x;
        else ms[z].erase(ms[z].find(x)), sum[z] -= x;
        int ans = 0;
        for (int i = 0; i < 31; ++i) ans += (int)ms[i].size();
        if (ans > 0) --ans;
        long long pf = 0;
        for (int i = 0; i < 31; ++i) {
            if (pf && ms[i].size() && pf * 2 < *ms[i].begin()) --ans;
            pf += sum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
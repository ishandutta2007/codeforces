#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
char s[kN];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x; scanf("%d%d", &n, &x);
        scanf("%s", s);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') sum++;
            else sum--;
        }
        if (sum == 0) {
            bool ok = sum == x;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') sum++;
                else sum--;
                ok |= sum == x;
            }
            if (ok) puts("-1");
            else puts("0");
        } else {
            int k = 0, ans = x % sum == 0 && x / sum >= 0;
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] == '0') k++;
                else k--;
                if ((x - k) % sum == 0 && (x - k) / sum >= 0) ++ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", &s);
    if (s[0] != '1' || s[n - 1] != '1') {
        printf("NO\n");
        return;
    }
    char ans[2][n];
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        }
    }
    if (ones % 2 == 1) {
        printf("NO\n");
        return;
    }
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (cnt[1] < ones / 2) {
                ans[0][i] = ans[1][i] = '(';
            } else {
                ans[0][i] = ans[1][i] = ')';
            }
            cnt[1]++;
        } else {
            if (cnt[0] % 2 == 0) {
                ans[0][i] = '(';
                ans[1][i] = ')';
            } else {
                ans[0][i] = ')';
                ans[1][i] = '(';
            }
            cnt[0]++;
        }
    }
    auto Valid = [&](char* s) {
        int bal = 0;
        for (int i = 0; i < n; i++) {
            bal += (s[i] == '(' ? 1 : -1);
            if (bal < 0) {
                return false;
            }
        }
        return bal == 0;
    };
    if (!Valid(ans[0]) || !Valid(ans[1])) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%c", ans[0][i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c", ans[1][i]);
    }
    printf("\n");
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
        test_case();
}
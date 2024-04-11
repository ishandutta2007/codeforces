#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
char s[maxn];
int cnt[3], tg[3];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) ++cnt[s[i] - '0'];
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        if (cnt[i] > n / 3) ans += cnt[i] - n / 3;
    }
    for (int i = 0; i < 3; ++i) tg[i] = n / 3;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        --cnt[s[i] - '0'];
        for (int j = 0; j < 3; ++j) {
            if (tg[j] == 0) continue;
            --tg[j];
            if (j != s[i] - '0') ++p; 
            int q = p;
            for (int k = 0; k < 3; ++k) {
                if (cnt[k] > tg[k]) q += cnt[k] - tg[k];
            }
            ++tg[j];
            if (j != s[i] - '0') --p;
            if (q == ans) {
                putchar(j + '0');
                --tg[j];
                if (j != s[i] - '0') ++p;
            }
        }
    }
    puts("");
}
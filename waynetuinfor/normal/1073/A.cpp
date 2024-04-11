#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
char s[maxn];
int cnt[26];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; ++j) {
            ++cnt[s[j] - 'a'];
            bool ok = true;
            for (int k = 0; k < 26; ++k) ok &= cnt[k] * 2 <= (j - i + 1);
            if (ok) {
                puts("YES");
                for (int k = i; k <= j; ++k) putchar(s[k]);
                puts("");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
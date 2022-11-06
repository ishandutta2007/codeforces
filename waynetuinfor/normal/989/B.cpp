#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
char s[maxn];

int main() {
    int n, p; scanf("%d %d", &n, &p);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            int a = 0, b = 0;
            for (int j = i + p; j < n; j += p) {
                if (s[j] == '.') {
                    s[i] = '1';
                    s[j] = '0';
                    for (int k = 0; k < n; ++k) if (s[k] == '.') s[k] = '0';
                    printf("%s\n", s);
                    return 0;
                }
                if (s[j] == '1') ++a;
                if (s[j] == '0') ++b;
            }
            if (a > 0 && b > 0) continue;
            if (a == 0 && b == 0) continue;
            if (a == 0) {
                s[i] = '1';
                for (int j = 0; j < n; ++j) if (s[j] == '.') s[j] = '0';
                printf("%s\n", s);
                return 0;
            }
            if (b == 0) {
                s[i] = '0';
                for (int j = 0; j < n; ++j) if (s[j] == '.') s[j] = '0';
                printf("%s\n", s);
                return 0;
            }
        } else {
            for (int j = i; j < n; j += p) {
                if (s[j] == '.') {
                    s[j] = s[i] == '1' ? '0' : '1';
                    for (int k = 0; k < n; ++k) if (s[k] == '.') s[k] = '0';
                    printf("%s\n", s);
                    return 0;
                }
                if (s[j] != s[i]) {
                    for (int k = 0; k < n; ++k) if (s[k] == '.') s[k] = '0';
                    printf("%s\n", s);
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}
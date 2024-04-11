#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
char s[maxn], t[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i + 1 < n; ++i) {
        int z = 0;
        for (int j = i + 1; j < n; ++j) t[z++] = s[j];
        for (int j = 0; j <= i; ++j) t[z++] = s[j];
        bool p = true, neq = false;
        for (int j = 0; j < n; ++j) p &= t[j] == t[n - 1 - j];
        for (int j = 0; j < n; ++j) neq |= s[j] != t[j];
        if (p && neq) {
            puts("1");
            return 0;
        }
    }
    for (int i = 0; i < 26; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) cnt += s[j] - 'a' == i;
        if (cnt == n || n % 2 == 1 && cnt == n - 1) {
            puts("Impossible");
            return 0;
        } 
    }
    puts("2");
    return 0;
}
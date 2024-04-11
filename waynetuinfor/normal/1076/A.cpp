#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];

int main() {
    int n; scanf("%d%s", &n, s);
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i + 1] < s[i]) {
            for (int j = 0; j < i; ++j) putchar(s[j]);
            for (int j = i + 1; j < n; ++j) putchar(s[j]);
            return 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) putchar(s[i]);
    return 0;
}
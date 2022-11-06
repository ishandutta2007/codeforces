#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '[') {
            x = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == ']') {
            y = i;
            break;
        }
    }
    if (x == -1 || y == -1) {
        puts("-1");
        return 0;
    }
    int a = -1, b = -1;
    for (int i = x + 1; i < n; ++i) {
        if (s[i] == ':') {
            a = i;
            break;
        }
    }
    for (int i = y - 1; i >= 0; --i) {
        if (s[i] == ':') {
            b = i;
            break;
        }
    }
    if (a == -1 || b == -1 || a >= b) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i = a + 1; i < b; ++i) {
        if (s[i] == '|') ++ans;
    }
    printf("%d\n", ans + 4);
    return 0;
}
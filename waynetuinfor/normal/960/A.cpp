#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
char s[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0;
    while (a < n && s[a] == 'a') ++a;
    if (a == 0) return 0 * puts("NO");
    int b = a;
    while (b < n && s[b] == 'b') ++b;
    if (b == a) return 0 * puts("NO");
    int c = b;
    while (c < n && s[c] == 'c') ++c;
    if (c - b != b - a && c - b != a || c != n) return 0 * puts("NO");
    puts("YES");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
char s[maxn];
int n;

bool check() {
    for (int i = 0; i < n; ++i) if (s[i] == '1') {
        if (i > 0 && s[i - 1] == '1') return false;
        if (i + 1 < n && s[i + 1] == '1') return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    if (!check()) return 0 * puts("No");
    for (int i = 0; i < n; ++i) if (s[i] == '0') {
        s[i] = '1';
        if (check()) return 0 * puts("No");
        s[i] = '0';
    } 
    puts("Yes");
}
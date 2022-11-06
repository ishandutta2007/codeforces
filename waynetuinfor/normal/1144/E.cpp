#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
char s[maxn], t[maxn];
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; ++i)
        a[i] = s[i] - 'a' + t[i] - 'a';
    int c = 0;
    for (int i = n - 1; i >= 0; --i) {
        a[i] += c;
        c = a[i] >= 26;
        a[i] %= 26;
    }
    if (c) a[0] += 26;
    for (int i = 0; i < n; ++i) {
        assert(a[i] <= 51);
        printf("%c", a[i] / 2 + 'a');
        a[i + 1] += (a[i] % 2) * 26;
    }
    puts("");
}
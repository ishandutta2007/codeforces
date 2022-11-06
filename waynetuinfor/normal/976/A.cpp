#include <bits/stdc++.h>
using namespace std;

const int maxn = 101;
char s[maxn];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    if (n == 1 && s[0] == '0') return 0 * puts("0");
    int c = 0, d = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') ++c;
        else ++d;
    }
    printf("1");
    for (int i = 0; i < d; ++i) printf("0");
    puts("");
    return 0;
}
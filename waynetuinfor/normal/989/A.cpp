#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
char s[maxn];
set<char> cc[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') continue;
        if (i + 1 < n) cc[i + 1].insert(s[i]);
        if (i - 1 >= 0) cc[i - 1].insert(s[i]);
        cc[i].insert(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (cc[i].size() == 3) return 0 * puts("Yes");
    }
    puts("No");
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int pos[maxn];

int main() {
    int q; scanf("%d\n", &q);
    int l = 0, r = 1;
    while (q--) {
        char c; int x;
        scanf("%c %d\n", &c, &x);
        if (c == 'L') pos[x] = l--;
        if (c == 'R') pos[x] = r++;
        if (c == '?') printf("%d\n", min(pos[x] - l, r - pos[x]) - 1);
    }
}
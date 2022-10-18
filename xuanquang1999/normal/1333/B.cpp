#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, a[MAXN], b[MAXN];

bool solve() {
    bool pos = false, neg = false;
    for(int i = 0; i < n; ++i) {
        if (b[i] > a[i] && !pos) 
            return false;
        if (b[i] < a[i] && !neg)
            return false;
        pos |= (a[i] == 1);
        neg |= (a[i] == -1);
    }

    return true;
}

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &b[i]);

        puts(solve() ? "YES" : "NO");
    }

    return 0;
}
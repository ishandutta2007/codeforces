#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int nTest, n, m, k, h[MAXN];

bool solve() {
    for(int i = 0; i < n-1; ++i) {
        int minH = max(0, h[i+1] - k);
        m += h[i] - minH;
        if (m < 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &nTest);
    for(int iTest = 0; iTest < nTest; ++iTest) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; ++i)
            scanf("%d", &h[i]);

        puts(solve() ? "YES" : "NO");
    }

    return 0;
}
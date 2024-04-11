#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, p[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) p[i] = i;
        for(int i = n; i > 1; i -= 2) {
            swap(p[i], p[i-1]);
        }

        for(int i = 1; i <= n; ++i) {
            printf("%d ", p[i]);
        }
        puts("");
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int oo = (int)1e9 + 7;

int a, b;

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        scanf("%d%d", &a, &b);

        int ans = oo;

        for(int i = 0; i <= 32; ++i) {
            int x = b + i, y = a;
            if (x == 1) continue;

            int cnt = i;
            while (y) {
                y /= x;
                ++cnt;
            }

            ans = min(ans, cnt);
        }

        printf("%d\n", ans);
    }

    return 0;
}
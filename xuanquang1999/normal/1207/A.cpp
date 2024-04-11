#include <bits/stdc++.h>

using namespace std;

int nTest, b, p, f, h, c;

int main() {
    scanf("%d", &nTest);
    for(int iTest = 1; iTest <= nTest; ++iTest) {
        scanf("%d%d%d", &b, &p, &f);
        scanf("%d%d", &h, &c);

        int ans = 0;
        for(int i = 0; i <= p; ++i)
            for(int j = 0; j <= f; ++j)
                if (2*(i+j) <= b)
                    ans = max(ans, i*h + j*c);

        printf("%d\n", ans);
    }

    return 0;
}
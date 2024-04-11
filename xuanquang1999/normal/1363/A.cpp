#include <bits/stdc++.h>

using namespace std;

int nTest, n, x, cnt0, cnt1;

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &x);
        cnt0 = cnt1 = 0;
        for(int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (a%2 == 0)
                ++cnt0;
            else
                ++cnt1;
        }

        if (cnt1 == 0)
            puts("No");
        else if (cnt0 == 0 && x%2 == 0)
            puts("No");
        else if (x == n && cnt1%2 == 0)
            puts("No");
        else
            puts("Yes");
    }


    return 0;
}
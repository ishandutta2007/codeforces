#include <bits/stdc++.h>
using namespace std;

int ans[200];

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= 180; ++i) ans[i] = 1000000;
    for (int i = 3; i <= 1000; ++i) {
        for (int j = 1; j <= i - 2; ++j) {
            if (j * 180 % i == 0) ans[j * 180 / i] = min(ans[j * 180 / i], i);
            // if (j * 360 % i == 0) ans[j * 180 / i] = min(ans[j * 360 / i], i);
        }
    }
    while (t--) {
        int x; scanf("%d", &x);
        if (ans[x] < 1000) printf("%d\n", ans[x]); 
        else printf("%d\n", -1);
    }
}
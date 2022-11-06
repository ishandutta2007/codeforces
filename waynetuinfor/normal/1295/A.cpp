#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        if (n % 2 == 1) {
            printf("7");
            for (int i = 0; i < (n - 3) / 2; ++i) printf("1");
            puts("");
        } else {
            for (int i = 0; i < n / 2; ++i) printf("1");
            puts("");
        }
    }
}
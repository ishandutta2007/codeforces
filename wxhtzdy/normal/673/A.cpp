#include <bits/stdc++.h>
using namespace std;

int a[95];

int main() {

    int n;
    scanf("%d", &n);

    while(n--) {
        int x;
        scanf("%d", &x);

        a[x] = 1;
    }

    for (int i = 15; i <= 90; i++) {
        int sum = 0;
        for (int j = 0; j < 15; j++) sum += a[i - j];

        if (sum == 0) return printf("%d", i), 0;
    }

    printf("90");
    return 0;
}
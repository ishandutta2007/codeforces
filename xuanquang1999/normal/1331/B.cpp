#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    for(int i = 2; i <= a; ++i) {
        if (a%i == 0) {
            printf("%d%d\n", i, a/i);
            break;
        }
    }

    return 0;
}
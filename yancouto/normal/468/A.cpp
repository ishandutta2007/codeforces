#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, n;
    scanf("%d", &n);
    if(n <= 3) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if(n % 2) {
        puts("2 + 3 = 5\n5 * 4 = 20\n5 - 1 = 4\n20 + 4 = 24");
        for(i = 7; i <= n; i += 2)
            printf("%d - %d = 1\n24 * 1 = 24\n", i, i - 1);
    } else {
        puts("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24");
        for(i = 6; i <= n; i += 2)
            printf("%d - %d = 1\n24 * 1 = 24\n", i, i - 1);
    }
    return 0; 
}
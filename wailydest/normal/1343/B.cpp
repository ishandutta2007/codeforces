#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n % 4) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 0; i < n / 2; ++i) printf("%d ", i * 2 + 2);
        for (int i = n / 2; i < n - 1; ++i) printf("%d ", (i - n / 2) * 2 + 1);
        printf("%d\n", (int)((long long)(2 + n) * n / 4 - (long long)(n - 2) * (n / 2 - 1) / 2));
    }
    return 0;
}
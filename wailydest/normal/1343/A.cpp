#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int k = 2;
        while (n % ((1 << k) - 1)) ++k;
        printf("%d\n", n / ((1 << k) - 1));
    }
    return 0;
}
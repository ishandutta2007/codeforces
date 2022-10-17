#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d %d %d\n", a, c, c);
    }
    return 0;
}
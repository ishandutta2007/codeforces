#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if (a * 2 < b) printf("%lld\n", (long long)(x + y) * a);
        else printf("%lld\n", (long long)min(x, y) * b + (long long)abs(x - y) * a);
    }
    return 0;
}
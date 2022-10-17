#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    
    int x, n, m;
    while (t--) {
        scanf("%d%d%d", &x, &n, &m);
        while (n-- && x / 2 + 10 < x) x = x / 2 + 10;
        if (x > 10 * m) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
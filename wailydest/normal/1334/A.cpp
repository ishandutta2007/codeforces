#include <iostream>
using namespace std;

bool solve()
{
    int n;
    scanf("%d", &n);
    int p, c;
    int prev1 = 0, prev2 = 0;
    bool t = true;
    while (n--) {
        scanf("%d%d", &p, &c);
        if (t) {
            if (c - prev2 > p - prev1 || c < prev2 || p < prev1 || p < c) t = false;
            prev1 = p;
            prev2 = c;
        }
    }
    if (t) return true;
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        if (solve()) printf("YES");
        else printf("NO");
        printf("\n");
    }
    return 0;
}
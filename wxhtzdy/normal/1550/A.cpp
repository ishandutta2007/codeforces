#include <bits/stdc++.h>

using namespace std;

void test()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    for (int i = 1; i <= n; i += 2) n -= i, c++;
    if (n > 0) c++;
    printf("%d\n", c);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}
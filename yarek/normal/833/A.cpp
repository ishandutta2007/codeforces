#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        long long c = 1LL * a * b;
        int d = pow(c, 1.0 / 3);
        bool ok = false;
        for(int i = max(1, d - 10); i < d + 10; i++)
            if(1LL * i * i * i == c && a % i == 0 && b % i == 0)
                ok = true;
        puts(ok ? "Yes" : "No");
    }
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

int n;
ll l, r, ans;

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%I64d%I64d", &l, &r);
        r++;
        ans = 0;
        for (int k = 61; k >= 0; k--)
        {
            if ((l & (1LL << k)) == (r & (1LL << k)))
            {
                ans += (r & (1LL << k));
            }
            else
            {
                ans += (r & (1LL << k)) - 1LL;
                break;
            }
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
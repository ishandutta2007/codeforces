#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 100;

ll arr[N];
ll sum[N];


bool cmp(ll a, ll b)
{           
    return a > b;
}

ll Sum(int ind)
{
    return (ind < 0) ? 0 : sum[ind];
}
           
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &arr[i]);

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++)
        sum[i] = (i == 0) ? arr[i] : sum[i - 1] + arr[i];


    int ansL = -1, ansNum = (ll)1e15;
    for (int i = 0; i < n; i++)
    {
        int l = i - 1, r = n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            ll s1 = Sum(m) - Sum(i - 1);
            int len = m - i + 1;
            if (s1 + k < len * arr[i])
                r = m;  
            else
                l = m;
        }                                   
        if (ansL < l - i + 1 || (ansL == l - i + 1 && ansNum > arr[i]))
        {
            ansNum = arr[i];
            ansL = l - i + 1;
        }
    }
    printf("%d %d", ansL, ansNum);
    return 0;
}
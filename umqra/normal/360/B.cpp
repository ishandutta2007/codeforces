#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)2e3 + 100;
const int INF = (int)1e9;

int a[N];
int dp[N];

int getDp(int val, int n)
{       
    for (int i = 0; i < n; i++)
    {
        dp[i] = i;
        for (int s = 0; s < i; s++)
        {
            int t = (abs(a[i] - a[s]) + (i - s - 1)) / (i - s);                 
            if (t <= val)
            {
                dp[i] = min(dp[i], dp[s] + (i - s - 1));
            }
        }                      
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[i] + n - i - 1);
    }
    return ans;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (k == n)
    {
        puts("0");
        return 0;
    }
                         
    ll l = -1, r = (ll)2e9 + 10;
                                                    
    while (r - l > 1)
    {                                  
        ll m = (l + r) / (ll)2;
        int val = getDp((int)m, n);
        if (val <= k)
            r = m;
        else
            l = m;                    
    }
    printf("%d", (int)r);

    return 0;
}
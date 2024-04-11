#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

const int INF = (int)1e9;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

char com[100];
int x[100];
int c[101];
int dp[21][(1 << 20)];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    sort(c, c + n, greater<int>());

    int m;
    scanf("%d", &m);                 
                     
    for (int i = 0; i < m; i++)
    {         
        scanf(" %c%d", &com[i], &x[i]);     
    }
        

    for (int i = m - 1; i >= 0; i--)
    {
        if (x[i] == 1)
        {
            if (com[i] == 'p')
            {
                for (int mask = 0; mask < (1 << m); mask++)
                {
                    dp[i][mask] = -INF;
                    for (int pos = 0; pos < m; pos++)
                    {
                        if (!(mask & (1 << pos)))
                        {
                            dp[i][mask] = max(dp[i][mask], dp[i + 1][mask | (1 << pos)] + c[pos]);
                        }
                    }
                }
            }
            else
            {
                for (int mask = 0; mask < (1 << m); mask++)
                {
                    dp[i][mask] = -INF;
                    for (int pos = 0; pos < m; pos++)
                    {
                        if (!(mask & (1 << pos)))
                        {
                            dp[i][mask] = max(dp[i][mask], dp[i + 1][mask | (1 << pos)]);
                        }
                    }
                }
            }
        }
        else
        {
            if (com[i] == 'p')
            {                     

                for (int mask = 0; mask < (1 << m); mask++)
                {
                    dp[i][mask] = INF;
                    for (int pos = 0; pos < m; pos++)
                    {
                        if (!(mask & (1 << pos)))
                        {
                            dp[i][mask] = min(dp[i][mask], dp[i + 1][mask | (1 << pos)] - c[pos]);
                        }
                    }
                }
            }
            else
            {                        
                for (int mask = 0; mask < (1 << m); mask++)
                {
                    dp[i][mask] = INF;

                    for (int pos = 0; pos < m; pos++)
                    {
                        if (!(mask & (1 << pos)))
                        {
                            dp[i][mask] = min(dp[i][mask], dp[i + 1][mask | (1 << pos)]);
                        }
                    }
                }
            }
        }   
    }
    printf("%d", dp[0][0]);

    return 0;
}
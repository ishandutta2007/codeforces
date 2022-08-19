#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 2007;
const int Z = 1002;
int n, k;
char s[N];
bool dp[N][N];
int par[N][N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d %s", &n, &k, s);
    dp[0][Z] = 1;
    for (int i = 0; i < n; i++)
        for (int bal = -k + 1; bal < k; bal++)
        {
            if (!dp[i][Z + bal]) continue;
            if (s[i] == 'W' || s[i] == '?')
            {
                dp[i + 1][Z + bal + 1] = 1;
                par[i + 1][Z + bal + 1] = 1;
            }
            if (s[i] == 'D' || s[i] == '?')
            {
                dp[i + 1][Z + bal] = 1;
                par[i + 1][Z + bal] = 0;
            }
            if (s[i] == 'L' || s[i] == '?')
            {
                dp[i + 1][Z + bal - 1] = 1;
                par[i + 1][Z + bal - 1] = -1;
            }
        }
    if (dp[n][Z + k])
    {
        int p = n, w = Z + k;
        while(p > 0)
        {
            int d = par[p][w];
            p--;
            w -= d;
            if (d == 1)
                s[p] = 'W';
            if (d == 0)
                s[p] = 'D';
            if (d == -1)
                s[p] = 'L';
        }
        printf("%s\n", s);
    }
    else if (dp[n][Z - k])
    {
        int p = n, w = Z - k;
        while(p > 0)
        {
            int d = par[p][w];
            p--;
            w -= d;
            if (d == 1)
                s[p] = 'W';
            if (d == 0)
                s[p] = 'D';
            if (d == -1)
                s[p] = 'L';
        }
        printf("%s\n", s);
    }
    else
        printf("NO\n");

    return 0;
}
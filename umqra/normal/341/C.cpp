#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#ifdef UMQRA
    #define getTime() fprintf(stderr, "Running time:%.3lf seconds\n", (double)(clock()) / CLOCKS_PER_SEC)
#else
    #define getTime()
#endif

const int mod = (int)1e9 + 7;
const int N = 2001;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

int a[N];
int cnt[N];
int dp[N][N];
bool used[N][N];

int add(int a, int b)
{
    return (a + b < mod ? a + b : a + b - mod);
}

int mult(int a, int b)
{
    return (int)(((ll)a * (ll)b) % (ll)mod);
}

void calcDp(int a, int b)
{                                       
    if (used[a][b])
        return;                 
    if (a == 0 && b == 0)
    {
        dp[a][b] = 1;
        used[a][b] = 1;
        return;
    }
    if (a == b)
    {   
        calcDp(a - 1, b - 1);
        dp[a][b] = mult(dp[a - 1][b - 1], a);
        int cntPrison = a - b;
        if (cntPrison != 0)
        {
            calcDp(a - 2, b - 1);
            dp[a][b] = add(dp[a][b], mult(dp[a - 2][b - 1], cntPrison));
        }
    }
    else
    {
        calcDp(a - 1, b);   
        dp[a][b] = mult(dp[a - 1][b], a - 1);
        int cntPrison = a - b - 1;
        if (cntPrison != 0)
        {
            calcDp(a - 2, b);
            dp[a][b] = add(dp[a][b], mult(dp[a - 2][b], cntPrison));
        }
    }
    used[a][b] = 1;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    fill(cnt, cnt + N, 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i] - 1]--;
    }

    int cntVertex = 0, cntFree = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            cntVertex++;
            if (cnt[i] == 0)
                cntFree++;
        }
    }                          
    calcDp(cntVertex, cntFree);
    cout << dp[cntVertex][cntFree];
    return 0;
}
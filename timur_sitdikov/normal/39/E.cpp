#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

const long long maxn=50000;
long long lim[maxn+5], n, lima;
vector<char> g[maxn+5];

void work(int a, int st)
{
    if (a>=40000)
        a=a;
    if (lim[a+1]>=st)
    {
        if (!g[a+1][st])
            g[a][st]=1;
        else if (g[a+1][st]==2)
            g[a][st]=2;
        else g[a][st]=0;
    }
    if (lim[a]>=st+1)
    {
        if (!g[a][st+1])
            g[a][st]=1;
        else if (g[a][st+1]==2 && g[a][st]!=1)
            g[a][st]=2;
        else if (g[a][st]<=0)
            g[a][st]=0;
    }
    if (g[a][st]==-1)
    {
        if (a==1 && st==lim[1])
            g[a][st]=2;
        else if (a==lima)
        {
            if ((a&1)!=(n&1))
                g[a][st]=0;
            else g[a][st]=1;
        }
        else g[a][st]=0;
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long a, st, i, j, limst, cur;
    cin >> a >> st >> n;
    lima=min(n-1, maxn);
    limst=50;
    for(i=1; i<=lima; i++)
    {
        cur=i;
        for(j=1; cur<n && j<=limst; j++)
            cur*=i;
        lim[i]=j-1;
    }
    for(i=a; i<=lima; i++)
        for(j=0; j<=lim[i]; j++)
            g[i].pb(-1);
    for(i=lima; i>=a; i--)
        for(j=lim[i]; j>=st; j--)
        {
            work(i, j);
        }
    if (g[a][st]==0)
        printf("Stas");
    if (g[a][st]==1)
        printf("Masha");
    if (g[a][st]==2)
        printf("Missing");
}
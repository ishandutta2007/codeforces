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

int dp[15][15], num[15], n;
int cur[15], bad[15], f;
vector<int> ans[11];

void output()
{
    int i, j;
    for(i=0; i<n; i++)
        ans[i].clear();
    for(i=0; i<n; i++)
        ans[cur[i]].pb(i+1);
    for(i=0; ; )
    {
        printf("{%d", ans[i][0]);
        for(j=1; j<ans[i].size(); j++)
            printf(",%d", ans[i][j]);
        putchar('}');
        i++;
        if (!ans[i].empty())
            putchar(',');
        else break;
    }
    putchar('\n');  
    f=1;
}

void rec_solve(int depth)
{
    if (depth==n)
    {
        output();
        return;
    }
    int i, mx=min(1, depth), j, last, lim1, lim2, d;
    for(i=0; i<depth; i++)
        if (cur[i]+1>mx)
        {
            mx=cur[i]+1;
        }
    if (bad[depth]!=-1)
        rec_solve(depth+1);
    if (f)
    {
        lim1=mx;
        lim2=-1;
        d=-1;
    }
    else
    {
        lim1=0;
        lim2=mx+1; 
        d=1;
    }
    for(i=lim1; i!=lim2; i+=d)
        if (bad[depth]!=i)
        {
            cur[depth]=i;
            /*for(j=depth+1; j<n; j++)
                bad[j]=cur[j];*/
            rec_solve(depth+1);
            last=i;
        }
    bad[depth]=last;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    cin >> n;
    dp[1][1]=1;
    for(i=2; i<=n; i++)
        for(j=1; j<=i; j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j; 
        }
    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++)
            num[i]+=dp[i][j];
    printf("%d\n", num[n]);
    for(int i=0; i<n; i++)
        bad[i]=cur[i]=-1;
    rec_solve(0);
    

}
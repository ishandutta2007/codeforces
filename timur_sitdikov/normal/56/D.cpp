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

const int maxn=1005, inf=100000000;
int dp[maxn][maxn], prv[maxn][maxn];
char s1[maxn], s2[maxn];
vector<pair<string, pair<int, char> > > vc;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n1, n2, i, j, tmp;
    scanf("%s %s", &s1[1], &s2[1]);
    s1[0]=s2[0]='#';
    n1=strlen(s1)-1;
    n2=strlen(s2)-1;
    for(i=0; i<=n1; i++)
        for(j=0; j<=n2; j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    /*for(i=1; i<=n1; i++)
    {
        dp[i][0]=i;
        prv[i][0]=2;
    }
    for(j=1; i<=n2; i++)
    {
        dp[0][j]=i;
        prv[0][j]=1;
    }*/
    for(i=0; i<=n1; i++)
        for(j=0; j<=n2; j++)
        {
            if (i<n1 && j<n2)
            {
                if (s1[i+1]==s2[j+1])
                {
                    if (dp[i][j]<dp[i+1][j+1])
                    {
                        dp[i+1][j+1]=dp[i][j];
                        prv[i+1][j+1]=3;
                    }
                }
                else
                {
                    if (dp[i][j]+1<dp[i+1][j+1])
                    {
                        dp[i+1][j+1]=dp[i][j]+1;
                        prv[i+1][j+1]=3;
                    }
                }
            }
            if (j<n2)
            {
                if (dp[i][j]+1<dp[i][j+1])
                {
                    dp[i][j+1]=dp[i][j]+1;
                    prv[i][j+1]=1;
                }
            }
            if (i<n1)
            {
                if (dp[i][j]+1<dp[i+1][j])
                {
                    dp[i+1][j]=dp[i][j]+1;
                    prv[i+1][j]=2;
                }
            }
        }
    //printf("%d\n", dp[n1][n2]);
    for(i=n1, j=n2; i || j; )
    {
        tmp=prv[i][j];
        if (tmp==3 && dp[i-1][j-1]!=dp[i][j])
            vc.pb(make_pair("REPLACE", make_pair(j, s2[j])));
        if (tmp==2)
            vc.pb(make_pair("DELETE", make_pair(j+1, 0)));
        if (tmp==1)
            vc.pb(make_pair("INSERT", make_pair(j, s2[j])));
        i-=((tmp&2)>>1);
        j-=(tmp&1);
    }
    printf("%d\n", (int)vc.size());
    for(i=(int)vc.size()-1; i>=0; i--)
    {
        cout << vc[i].first << " " << vc[i].second.first;
        if (vc[i].second.second)
            cout << " " << vc[i].second.second;
        putchar('\n');
    }
}
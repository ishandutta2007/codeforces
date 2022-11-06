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

const int maxn=53, al=26, inf=1000000;
int g[maxn][maxn][maxn][maxn];
int dp[maxn][maxn];
vector<int> g1[al][al];
set <int> good[2][maxn][maxn];
char good2[2][al][maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s[2], tmp, tmp1;
    int i, j, i1, j1, k1, k, l, n;
    set <int>::iterator it, it1;
    cin >> s[0] >> s[1] >> n;
    for(i=0; i<n; i++)
    {
        cin >> tmp;
        tmp[0]-='a';
        tmp[3]-='a';
        tmp[4]-='a';
        g1[tmp[3]][tmp[4]].pb((int)tmp[0]);
    }
    for(i=0; i<s[0].length(); i++)
        for(j=0; j<s[2].length(); j++)
            for(k=0; i+k<s[0].length() && j+k<s[1].length() && s[0][i+k]==s[1][j+k]; k++)
                g[i][i+k][j][j+k]=k+1;
    for(i=0; i<2; i++)
        for(j=0; j<s[i].length(); j++)
            good[i][j][j].insert(s[i][j]-'a');
    for(i1=0; i1<2; i1++)
    {
        for(i=s[i1].length()-2; i>=0; i--)
            for(j=i; j<s[i1].length(); j++)
                for(it=good[i1][i][j].begin(); it!=good[i1][i][j].end(); it++)
                {
                    for(j1=j+1; j1<s[i1].length(); j1++)
                        for(it1=good[i1][j+1][j1].begin(); it1!=good[i1][j+1][j1].end(); it1++)
                            for(l=0; l<g1[*it][*it1].size(); l++)
                                //good2[i1][g1[good[i1][i][j][k]][good[i1][j+1][j1][k1]][l]][i][j]=1;
                                good[i1][i][j1].insert(g1[*it][*it1][l]);           
                }
    }
    for(i1=0; i1<2; i1++)
        for(i=0; i<s[i1].size(); i++)
            for(j=i; j<s[i1].size(); j++)
                for(it=good[i1][i][j].begin(); it!=good[i1][i][j].end(); it++)
                    good2[i1][*it][i][j]=1;
    for(i=0; i<=s[0].length(); i++)
        for(j=0; j<=s[1].length(); j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for(i=0; i<=s[0].length(); i++)
        for(j=0; j<=s[1].length(); j++)
        {
            if (dp[i][j]==inf)
                continue;
            for(i1=i+1; i1<=s[0].length(); i1++)
                for(j1=j+1; j1<=s[1].length(); j1++)
                {
                    if (g[i+1-1][i1-1][j+1-1][j1-1])
                        dp[i1][j1]=min(dp[i1][j1], dp[i][j]+g[i+1-1][i1-1][j+1-1][j1-1]);
                    for(k=0; k<al; k++)
                        if (good2[0][k][i+1-1][i1-1] && good2[1][k][j+1-1][j1-1])
                        {
                            dp[i1][j1]=min(dp[i1][j1], dp[i][j]+1);
                            break;
                        }
                }
        }
    if (dp[s[0].length()][s[1].length()]==inf)
        printf("-1");
    else printf("%d", dp[s[0].length()][s[1].length()]);
    
}
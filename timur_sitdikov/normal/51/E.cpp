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
#define mp make_pair

const int maxn=700;
long long g[maxn][maxn], tmp[maxn][maxn], g2[maxn][maxn], g3[maxn][maxn], g5[maxn][maxn], gg[maxn][maxn], st[maxn], n;
char g1[maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, m, a, b;
    long long ans, vv;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a][b]=g[b][a]=1;
        g1[a][b]=g1[b][a]=1;
    }
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            for(k=0; k<n; k++)
                g2[i][j]+=g[i][k]*g[k][j];
            g2[j][i]=g2[i][j];
        }
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            for(k=0; k<n; k++)
                g3[i][j]+=g2[i][k]*g[k][j];
            g3[j][i]=g3[i][j];
        }
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            for(k=0; k<n; k++)
                g5[i][j]+=g2[i][k]*g3[k][j];
            g5[j][i]=g5[i][j];
        }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=0; k<n; k++)
                if (g1[i][k] && g1[j][k])
                    gg[i][j]++;
    ans=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            st[i]+=g[i][j];
    for(i=0; i<n; i++)
    {
        vv=0;
        for(j=0; j<n; j++)
            if (g1[i][j])
                for(k=0; k<n; k++)
                    if (g1[i][k] && g1[k][j])
                        vv++;
        ans-=2*st[i]*vv;
        for(j=0; j<n; j++)
            if (g1[i][j])
            {
                ans-=gg[i][j]*(st[j]-1);
                //ans-=4*gg[i][j];
                ans-=(g3[j][j]-2*gg[i][j]);
                for(k=0; k<n; k++)
                    if (g1[i][k] && g1[j][k])
                        ans-=st[k]-2;
            }
    }
    for(i=0; i<n; i++)
        ans+=g5[i][i];
    ans/=10;
    cout << ans;

}
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
#define point complex<double>

const int maxn=505;
char c[maxn][maxn];
char f[maxn][maxn][15];
int ans, n, m, ff;

void fill()
{
    int i, j, k, s, fff[4];
    for(s=1, k=1; k<1000; k*=2, s++)
    {
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if (i+k<n && j+k<m)
                {
                    fff[0]=f[i][j][s-1];
                    fff[1]=f[i+k][j][s-1];
                    fff[2]=f[i][j+k][s-1];
                    fff[3]=f[i+k][j+k][s-1];
                    if (fff[0]==(ff&1) && fff[1]==((ff&2)/2) && fff[2]==((ff&4)/4) && fff[3]==((ff&8)/8))
                    {
                        if (ff!=15)
                            f[i][j][s]=0;
                        else
                            f[i][j][s]=1;
                        if (k!=1)
                            ans++;
                    }
                    else
                    {
                        if (fff[0]==1 && fff[1]==1 && fff[2]==1 && fff[3]==1)
                            f[i][j][s]=1;
                        else
                            f[i][j][s]=2;
                    }
                }
                else
                {
                    f[i][j][s]=2;
                }
            }
    }

}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, s;
    cin >> n >> m;
    for(i=n-1; i>=0; i--)
        scanf("%s", &c[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (c[i][j]=='.')
                c[i][j]=0;
            else c[i][j]=1;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            f[i][j][0]=c[i][j];
    for(ff=0; ff<(1<<4); ff++)
        fill();
    cout << ans;
}
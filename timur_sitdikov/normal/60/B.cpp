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
#define xx first
#define yy second

char g[15][15][15];
int n, m, h, ans;

void dfs(int k, int i, int j)
{
    g[k][i][j]='#';
    ans++;
    int i1, j1, k1;
    for(k1=-1; k1<=1; k1++)
        for(i1=-1; i1<=1; i1++)
            for(j1=-1; j1<=1; j1++)
                if (abs(k1)+abs(i1)+abs(j1)==1 && g[k+k1][i+i1][j+j1]=='.')
                    dfs(k+k1, i+i1, j+j1);
            
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int i, j, k;
    cin >> h >> n >> m;
    for(k=1; k<=h; k++)
        for(i=1; i<=n; i++)
            scanf("%s", &g[k][i][1]);
    scanf("%d %d", &i, &j);
    dfs(1, i, j);
    cout << ans;
}
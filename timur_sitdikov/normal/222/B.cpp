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

const int maxn=1005;
int v[maxn][maxn], per1[maxn], per2[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, j, a, b;
    char c[2];
    cin >> n >> m >> k;
    for(i=0; i<n; i++)
        per1[i]=i;
    for(j=0; j<m; j++)
        per2[j]=j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &v[i][j]);
    for(i=0; i<k; i++)
    {
        scanf("%s %d %d", &c, &a, &b);
        a--;
        b--;
        if (c[0]=='c')
            swap(per2[a], per2[b]);
        if (c[0]=='r')
            swap(per1[a], per1[b]);
        if (c[0]=='g')
            printf("%d\n", v[per1[a]][per2[b]]);

    }

    
}
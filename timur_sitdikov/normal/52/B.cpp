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

const int maxn=1005;
long long str[maxn], stol[maxn];
char c[maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j;
    long long ans=0;
    cin >> n >> m;
    for(i=0; i<n; i++)
        scanf("%s", &c[i]);
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (c[i][j]=='*')
            {
                str[i]++;
                stol[j]++;
            }
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (c[i][j]=='*')
                ans+=(str[i]-1)*(stol[j]-1);
    cout << ans;
}
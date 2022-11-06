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
#define xx real()
#define yy imag()

int m[105][2];
int bad[100];
vector<int> good[105];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, s;
    cin >> n >> s;
    for(i=0; i<n; i++)
    {
        cin >> m[i][0]>> m[i][1];
    }
    good[0].pb(7-s);
    for(i=1; i<n; i++)
    {
        for(j=1; j<=6; j++)
            bad[j]=0;
        for(j=0; j<2; j++)
            bad[m[i][j]]=bad[7-m[i][j]]=1;
        if (good[i-1].size()==1)
            bad[7-good[i-1][0]]=1;
        for(j=1; j<=6; j++)
            if (!bad[j])
                good[i].pb(j);
    }
    if (good[n-1].size()==1)
        printf("YES");
    else printf("NO");
}
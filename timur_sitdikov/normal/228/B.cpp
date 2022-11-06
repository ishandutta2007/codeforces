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

char v1[100][100], v2[100][100];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n1, m1, n2, m2, i, j, i1, j1, i2, j2, mn=-1, cur, x, y;
    cin >> n1 >> m1;
    for(i=0; i<n1; i++)
    {
        scanf("%s", &v1[i]);
        for(j=0; j<m1; j++)
            v1[i][j]-='0';
    }
    cin >> n2 >> m2;
    for(i=0; i<n2; i++)
    {
        scanf("%s", &v2[i]);
        for(j=0; j<m2; j++)
            v2[i][j]-='0';
    }
    for(i=-(n1-1); i<=n2-1; i++)
        for(j=-(m1-1); j<=m2-1; j++)
        {
            cur=0;
            for(i1=0; i1<n1; i1++)
                for(j1=0; j1<m1; j1++)
                    if (i1+i>=0 && i1+i<n2 && j1+j>=0 && j1+j<m2)
                        cur+=v1[i1][j1]*v2[i1+i][j1+j];
            if (cur>mn)
            {
                mn=cur;
                x=i;
                y=j;
            }
        }
    cout << x << " " << y;
}
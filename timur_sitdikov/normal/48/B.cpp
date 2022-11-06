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

int v[100][100];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int mn=1000000, cur, i, j, k, l, n, m, a, b;
    cin >> n >> m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin >> v[i][j];
    cin >> a >> b;
    for(i=a-1; i<n; i++)
        for(j=b-1; j<m; j++)
        {
            cur=0;
            for(k=i-a+1; k<=i; k++)
                for(l=j-b+1; l<=j; l++)
                    cur+=v[k][l];
            if (cur<mn)
                mn=cur;
        }
    for(i=b-1; i<n; i++)
        for(j=a-1; j<m; j++)
        {
            cur=0;
            for(k=i-b+1; k<=i; k++)
                for(l=j-a+1; l<=j; l++)
                    cur+=v[k][l];
            if (cur<mn)
                mn=cur;
        }
    cout << mn;
}
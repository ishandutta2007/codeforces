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

char c[300][300];
string s[5];
int stn[10];

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    int n, k, i, j, k1, k2;
    cin >> n >> k;
    stn[0]=1;
    for(i=1; i<=k; i++)
        stn[i]=stn[i-1]*n;
    for(i=0; i<n; i++)
        cin >> s[i];
    for(i=0; i<stn[k]; i++)
        for(j=0; j<stn[k]; j++)
        {
            c[i][j]='.';
            for(k1=k-1; k1>=0; k1--)
                if (c[i][j]=='.')
                    c[i][j]=s[(i/stn[k1])%n][(j/stn[k1])%n];
        }
    for(i=0; i<stn[k]; i++)
        printf("%s\n", c[i]);
}
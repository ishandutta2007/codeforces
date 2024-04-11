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

const int maxn=105;

int m[maxn][maxn], v[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i, j;
    cin >> n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> m[i][j];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (j!=i)
                v[i]|=m[i][j];
    for(i=0; i<n; i++)
        cout << v[i] << " ";
}
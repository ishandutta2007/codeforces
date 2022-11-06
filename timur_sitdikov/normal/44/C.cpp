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

int v[105];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, n, m, a, b;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b;
        for(j=a; j<=b; j++)
            v[j]++;
    }
    for(i=1; i<=n; i++)
        if (v[i]!=1)
        {
            cout << i << " " << v[i];
            return 0;
        }
    cout << "OK";
}
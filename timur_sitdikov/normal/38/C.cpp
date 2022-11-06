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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m[105], n, l, i, j, mn, cur;
    cin >> n >> l;
    for(i=0; i<n; i++)
        cin >> m[i];
    mn=0;
    for(i=l; i<=100; i++)
    {
        cur=0;
        for(j=0; j<n; j++)
            cur+=m[j]/i;
        mn=max(mn, cur*i);
    }
    cout << mn;
}
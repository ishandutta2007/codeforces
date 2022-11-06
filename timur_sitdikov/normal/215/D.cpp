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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long ans=0, x, T, t, cost, m, n, i, cur, cur1;
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> t >> T >> x >> cost;
        cur=cost;
        if (t+m>T)
            cur+=x*m;
        if (T>t)
        {
            cur1=cost*((m+T-t-1)/(T-t));
            cur=min(cur, cur1);
        }
        ans+=cur;
    }
    cout << ans;
}
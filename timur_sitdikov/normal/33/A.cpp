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

const int inf=10000000;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, a, b, i, mn[1005], ans;
    cin >> n >> m >> k;
    for(i=1; i<=n; i++)
        mn[i]=inf;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        mn[a]=min(b, mn[a]);

    }
    ans=0;
    for(i=1; i<=n; i++)
        if (mn[i]!=inf)
            ans+=mn[i];
    ans=min(ans, k);
    cout << ans;
}
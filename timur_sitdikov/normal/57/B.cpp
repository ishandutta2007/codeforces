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

const int maxn=100005;
int l[maxn], r[maxn], d[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, j, x;
    long long ans=0;
    cin >> n >> m >> k;
    for(i=0; i<m; i++)
        cin >> l[i] >> r[i] >> d[i];
    for(i=0; i<k; i++)
    {
        cin >> x;
        for(j=0; j<m; j++)
            if (l[j]<=x && x<=r[j])
                ans+=(long long)(d[j]+x-l[j]);
    }
    cout << ans;
}
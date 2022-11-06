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

const int maxn = 105;
char used[maxn];
int v[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, k, i, ans, f;
    cin >> n >> k;
    for(i=0; i<n; i++)
        cin >> v[i];
    for(ans=0; ;ans++)
    {
        for(i = 0; i < k; i++)
            used[i] = 0;
        f = 0;
        for(i = 0; i < n; i++)
            if (v[i] < k && !used[v[i]])
            {
                f = 1;
                used[v[i]] = 1;
                v[i]++;         
            }
        if (!f)
            break;
    }
    cout << ans;
}
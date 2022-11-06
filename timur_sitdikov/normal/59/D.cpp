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

const int maxn=300005;
char used[maxn], bad[maxn];
int w[maxn];
int tt[maxn][3];
vector<int> ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, n3, i, a, b, ind, j;
    cin >> n;
    n3=3*n;
    for(i=0; i<n3; i++)
    {
        cin >> a;
        w[a]=n-i;
    }
    for(i=0; i<n; i++)
    {
        cin >> tt[i][0] >> tt[i][1] >> tt[i][2];
    }
    cin >> ind;
    for(i=0; i<n; i++)
    {
        if (tt[i][0]==ind || tt[i][1]==ind || tt[i][2]==ind)
            break;
    }
    for(j=0; j<3; j++)
        if (tt[i][j]==ind)
            break;
    a=tt[i][(j+1)%3];
    b=tt[i][(j+2)%3];
    if (w[ind]<w[a] || w[ind]<w[b])
    {
        for(i=1; i<=n3; i++)
            if (i!=ind)
                cout << i << " ";
        return 0;
    }
    if (a>b)
        swap(a, b);
    for(i++; i<n; i++)
    {
        for(j=0; j<3; j++)
            bad[tt[i][j]]=1;
    }
    for(i=1; i<=b; i++)
    {
        if (i==ind)
            continue;
        if (!bad[i])
        {
            used[i]=1;
            ans.pb(i);
        }
    }
    for(i=1; i<=n3; i++)
    {
        if (i==ind)
            continue;
        if (!used[i])
        {
            used[i]=1;
            ans.pb(i);
        }
    }
    for(i=0; i<n3-1; i++)
        cout << ans[i] << " ";
}
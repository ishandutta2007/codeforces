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

vector<int> vc[1055];
const int inf=1000000;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, i1, i2, i3, cur1, cur3, a, ans;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> m;
        for(j=0; j<m; j++)
        {
            cin >> a;
            vc[i].pb(a);
        }
    }
    for(i=0; i<n; i++)
        sort(vc[i].begin(), vc[i].end());
    vc[n]=vc[0];
    vc[n+1]=vc[1];
    ans=0;
    for(i=1; i<=n; i++)
    {
        i1=i2=i3=0;
        cur1=cur3=0;
        vc[i-1].pb(inf);
        vc[i+1].pb(inf);
        for(; i1<vc[i-1].size() && i2<vc[i].size() && i3<vc[i+1].size(); )
        {
            if (vc[i-1][i1]<vc[i][i2] && vc[i-1][i1]<=vc[i+1][i3])
            {
                cur1++;
                i1++;
            }
            else if (vc[i+1][i3]<vc[i][i2] && vc[i+1][i3]<vc[i-1][i1])
            {
                cur3++;
                i3++;
            }
            else
            {
                if (cur1!=cur3 && i2)
                    ans++;
                cur1=cur3=0;
                i2++;
            }
        }
        vc[i-1].pop_back();
        vc[i+1].pop_back();
    }
    cout << ans;
}
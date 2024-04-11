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

vector<pair<int, int> > vv[105];
vector<pair<int, int> > vi, vj;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int v, t, i, n, j, ans=0, k1, k2, f, s1, s2, s;
    cin >> n >> s;
    for(i=0; i<n; i++)
    {
        cin >> k1;
        for(j=0; j<k1; j++)
        {
            cin >> v >> t;
            vv[i].pb(mp(v, t));
        }
    }
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
        {
            if (vv[i][0].first>vv[j][0].first)
                f=0;
            else f=1;
            s1=s2=0;
            vi=vv[i];
            vj=vv[j];
            for(k1=k2=0; k1<(int)vv[i].size() && k2<(int)vv[j].size(); )
            {
                t=min(vv[i][k1].second, vv[j][k2].second);
                vv[i][k1].second-=t;
                vv[j][k2].second-=t;
                s1+=vv[i][k1].first*t;
                s2+=vv[j][k2].first*t;
                if (!f && s2>s1)
                {
                    ans++;
                    f=1;
                }
                if (f && s1>s2)
                {
                    ans++;
                    f=0;
                }
                if (!vv[i][k1].second)
                    k1++;
                if (!vv[j][k2].second)
                    k2++;
            }
            vv[i]=vi;
            vv[j]=vj;

        }
    cout << ans;
}
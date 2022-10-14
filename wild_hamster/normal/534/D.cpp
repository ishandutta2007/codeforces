 #include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,x1,x2,x3,y1,t,y2,z,w,l,r,i,j,n,x,y,d,m,q,A;
pair <ll,ll> a[200500];
set <pair<ll,ll> > f[5];
set <pair<ll,ll> >::iterator itr;
vector <ll> g[200500];
string s;
vector <ll> ans;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        g[x].push_back(i+1);
    }
    ll flag = 1;
    ll cnt = 0;
    for (i = 0; i < n; i++)
        {
         for (j = 0; j < g[i].size(); j++)
             f[i%3].insert(mp(i,g[i][j]));
         if (f[i%3].empty())
            flag = 0;
         else
         {
             itr = f[i%3].end();
             itr--;
             ll val = (*itr).first;
             ans.push_back((*itr).second);
             if ((i - val)/3 < cnt)
                flag = 0;
             cnt = max(cnt, (i - val)/3);
             f[i%3].erase(itr);
         }
        }
           
    if (!flag)
       cout << "Impossible" << endl;
    else
    {
        cout << "Possible" << endl;
        for (i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }       
    return 0;
}
#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
typedef long long ll;
using namespace std;
ll q,n,k,i,j,x,y,z,isprime[2000005],rez[100500],a[100500],used[100500],level[100500];
vector <vector <ll> > basdil(2000005);
vector <vector <ll> > tree(100500);
map <ll,ll> vd;
void dfs(ll v, ll k)
{
     used[v] = 1;
     level[v] = k;
     int i,j;
     vector <pair<ll,ll> > tmp;
     ll max1 = -1, vr;
     for (i = 0; i < basdil[a[v]].size(); i++)
     {
         tmp.push_back(make_pair(basdil[a[v]][i],vd[basdil[a[v]][i]]));
         if (max1 < level[vd[basdil[a[v]][i]]])
         {
          vr = vd[basdil[a[v]][i]];
          max1 = level[vd[basdil[a[v]][i]]];
         }
         vd[basdil[a[v]][i]] = v;
     }
     if (max1 == -1) rez[v] = -1; else rez[v] = vr;
     for (i = 0; i < tree[v].size(); i++)
     if (!used[tree[v][i]])
         dfs(tree[v][i],k+1);
     for (i = 0; i < tmp.size(); i++)
         vd[tmp[i].first] = tmp[i].second;
}
int main()
{
    cin >> n >> q;
    level[0] = -1;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for (i = 2; i < 2000004; i++)
        isprime[i] = 1;
    for (i = 2; i < 2000004; i++)
        if (isprime[i])
        for (j = i; j < 2000004; j+=i)
        {
            basdil[j].push_back(i);
            isprime[j] = 0;
        }
    dfs(1,0);
    for (i = 0; i < q; i++)
    {
        cin >> x;
        if (x == 1)
        {
              cin >> y;
              cout << rez[y] << endl;
        }
        else
        {
            for (j = 0; j < 100400; j++)
            used[j] = 0;
            vd.clear();
            cin >> y >> z;
            a[y] = z;
            dfs(1,0);
        }
    }
    return 0;
}
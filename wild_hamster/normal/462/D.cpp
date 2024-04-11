#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll a[100500],n,k,x,y,i,j,rez;
vector <vector <ll> > tree(100500);
ll binpow(ll x, ll y)
{
 if (y == 0) return 1;
 ll tmp = binpow(x,y/2);
 if (y%2 == 0) return (tmp*tmp)%tr;
 else return (((x*tmp)%tr)*tmp)%tr;
}
ll inv (ll x)
{
       return binpow(x,tr-2);
}
pair <ll,ll> dfs(ll v)
{
     if (tree[v].size() == 0)
     {
      if (a[v]) return mp(0,1);
      else return mp(1,0);
     }
     ll d0 = 1, d1 = 0;
     vector <pair<ll,ll> > tmp;
     for (int i = 0; i < tree[v].size(); i++)
     {
         tmp.push_back(dfs(tree[v][i]));
         d0*=(tmp[i].first+tmp[i].second);
         d0%=tr;
         //cout << v << " " << tmp[i].first << " " << tmp[i].second << endl;
     }
     for (int i = 0; i < tree[v].size(); i++)
     {
         d1 = (d1 + ((d0*inv(tmp[i].first+tmp[i].second))%tr)*tmp[i].second)%tr;
        // cout << d1 << endl;
     }
     if (a[v]) return mp(0,d0);
     else return mp(d0,d1);
}
int main()
{
    //cout << binpow(2,7) << endl;
    //cout << inv(2) << endl;
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> x;
        tree[x].push_back(i+1);
    }
    for (i = 0; i < n; i++)
        cin >> a[i];
    pair <ll,ll> rez = dfs(0);
    cout << rez.second << endl;
    return 0;
}
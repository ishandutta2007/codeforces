#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],dp[200500],used[1000],n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,cur,rez,kokoko;
string s,s1,s2;
vector <pair<ll,ll> > f[5];
char c;
ll dist(pair<ll,ll> x, pair<ll,ll> y)
{
 return (y.first-x.first)*(y.first-x.first) + (y.second-x.second)*(y.second-x.second);
}
void find_square(ll cur, ll cnt, ll bits)
{
 if (cur == 4)
 {         
 kokoko++;
  //cout << bits << endl;
  ll i, j;
  vector <pair<ll,ll> > g;
  g.clear();
  for (i = 0; i < 4; i++)
  {
   g.push_back(f[i][bits%4]);
   bits /= 4;
  }
  vector <ll> b;
  b.clear();
  ll min1 = (ll)1e+12;
  for (i = 0; i < 4; i++)
      for (j = i+1; j < 4; j++)
      {
          b.push_back(dist(g[i],g[j]));
          min1 = min(min1,dist(g[i],g[j]));
      }
  ll k1 = 0, k2 = 0;
  sort(b.begin(),b.end());
  for (i = 0; i < 6; i++)
  {
      //if (cnt == 8) cout << b[i] << " ";
      if (b[i] == min1) k1++;
      if (b[i] == 2*min1) k2++;
  }
  //cout << endl;
  if (min1 != 0 && k1 == 4 && k2 == 2)
     rez = min(rez,cnt);
  return;
 }
 for (ll i = 0; i < 4; i++)
     find_square(cur+1,cnt+i,bits+i*(1<<(cur*2)));
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        f[j].clear();
        for (j = 0; j < 4; j++)
        {
            cin >> k1 >> k2 >> k >> m;
            x = k1-k; y = k2-m;
            f[j].push_back(mp(x+k,y+m));            
            f[j].push_back(mp(-y+k,x+m));
            f[j].push_back(mp(-x+k,-y+m));            
            f[j].push_back(mp(y+k,-x+m));
        }
       /* for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
                cout << f[j][k].first << " " << f[j][k].second << "     ";
            cout << endl;
        }*/
        rez = 20;
        find_square(0,0,0);
        if (rez == 20) cout << -1 << endl;
           else cout << rez << endl;        
    }
    //cout << kokoko << endl;
   return 0;
}
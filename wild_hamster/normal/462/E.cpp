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
ll a[100500],l,r,q,n,cur_size,i,j,parsum[100500],isrev,t,k1,k2;
ll find_sum(int x, int y)
{
 return parsum[y] - parsum[x-1];
}
void update(int v)
{
     ll i,tmp;
     if (!isrev)
     {
      if (v*2 < r-l+1)
      {
       for (i = l; i < l+v; i++)
       a[2*l+2*v-i-1]+=a[i];
       parsum[l+v-1] = 0;
       for (i = l+v; i < l+2*v; i++)
           parsum[i] = parsum[i-1] + a[i];
       l += v;
      }
      else
      {
       for (i = l+v; i <= r; i++)
           a[2*l+2*v-i-1] += a[i];
       for (i = 2*l+2*v-r-1; i < l+v; i++)
           parsum[i] = parsum[i-1] + a[i];
       r = l + v - 1;
       isrev = 1;
      }
     }
     else
     {
     if (v*2 < r-l+1)
       {
       for (i = r-v+1; i <= r; i++)
           a[2*r-2*v+1-i] += a[i];
       for (i = r - 2*v + 1; i < r - v + 1; i++)
           parsum[i] = parsum[i-1] + a[i];
       r = r-v;
      }
      else
      {
       for (i = l; i < r - v + 1; i++)
       a[2*r-2*v-i+1]+=a[i];
       parsum[r-v] = 0;
       for (i = r-v+1; i <= 2*r-2*v-l+1; i++)
           parsum[i] = parsum[i-1] + a[i];
       l = r-v+1;
       isrev = 0;
      }
     }
}
void find(ll x, ll y)
{
     if (!isrev) cout << find_sum(l+x,l+y-1) << endl;
     else cout << find_sum(r-y+1,r-x) << endl;
}
int main()
{
    //cout << binpow(2,7) << endl;
    //cout << inv(2) << endl;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
        a[i] = 1;
    for (i = 1; i <= n; i++)
        parsum[i] = i;
    l = 1; r = n;
    for (i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
              cin >> k1;
              update(k1);
        }
        else
        {
          /*  for (int i = 1; i <= n; i++)
                cout << parsum[i] << " ";
            cout << "         ";
            cout << r << " " << l << endl;*/
            cin >> k1 >> k2;
            find(k1,k2);
        }
    }

    return 0;
}
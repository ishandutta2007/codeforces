#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
//#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
ll used[5000],sum,x,y,i,j,n,m,k,q,j1,max1,min1;
pair <ll,ll> b[5000],c[5000];
struct lal
{
 int first,second,third;
};
lal a[5000];
vector <pair<ll,ll> > f;
bool ff(lal x, lal y)
{
     if (x.first < y.first) return true;
        else return false;
}
int main()
{
string s1,s2;
cin >> n;
for (i = 0; i < n; i++)
{
    cin >> a[i].first >> a[i].second;
    a[i].third = i + 1;
}
cin >> m;
for (i = 0; i < m; i++)
{
    cin >> b[i].first;
    b[i].second = i+1;
}
sum = 0;
sort(a,a+n,ff);
sort(b,b+m);
for (i = 0; i < m; i++)
{
    j = 0; max1 = 0; j1 = -5;
    while (a[j].fi <= b[i].first && j < n)
    {
          if (a[j].se > max1 && !used[j])
             {
              j1 = j;
              max1 = a[j].se;
             }   
          j++;
    }
    if (j1 != -5)
            {
                used[j1] = 1;
                f.pb(mp(j1,i));
                sum += max1;
                k++;
            }      
}
cout << k << " " << sum << endl;
for (i = 0; i < f.size(); i++)
    cout << a[f[i].first].third << " " << b[f[i].second].second << endl;
return 0;
}
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
typedef long long ll;
using namespace std;
ll n,i,j,d,x,y,m,len,l,r,sum,a[105005],b[5000],used[300],flag,k1,k2,k;
map <ll,ll> f[5];
map <ll,ll> :: iterator itr;
ll gcd(ll a, ll b)
{
 if (a%b == 0)
    return b;
 return gcd(b,a%b);
}
int main()
{
    cin >> n;
    //srand(time(0));
    //n = 300;
    for (i = 0; i < n; i++)
        cin >> a[i];
        
    for (i = 0; i < n; i++)
        cin >> b[i];
    for (i = 0; i < n; i++)
    if (f[0][a[i]] == 0)
        f[0][a[i]] = b[i];
    else
        f[0][a[i]] = min(f[0][a[i]],b[i]);
    ll rez = (ll)1e+18;
    if (f[0][1] != 0)
       rez = min(rez,f[0][1]);
    for (j = 1; j < n; j++)
    {
        f[j%2].clear();
        i = (j+1)%2;
        for (itr = f[i].begin(); itr!=f[i].end(); itr++)
        {
            pair<ll,ll> cnt = (*itr);
            ll tmp = cnt.first;
            ll val = cnt.second;
            for (k = 0; k < n; k++)
            {
             ll gc = gcd(a[k],tmp);
             if (gc != tmp)
             {
              if (f[j%2][gc] == 0)
                 f[j%2][gc] = val + b[k];
              else
                 f[j%2][gc] = min(f[j%2][gc],val + b[k]); 
             }
            }
            if (f[j%2][1] != 0)
               rez = min(rez,f[j%2][1]);
        }
    }
    if (rez!=(ll)1e+18)
    cout << rez << endl;
    else
    cout << -1 << endl;
    return 0;
}
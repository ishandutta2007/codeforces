#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef long long ll;
ll i,n,j,k,z,m,l,r,x,y,T;
pair <ll,ll> tq[1005];
vector <ll> f[105];
string s1,s2;
ll gcd(ll a, ll b)
{
 if (a%b == 0)
    return b;
 return gcd(b,a%b);
}
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}

int main()
{
    cin >> n >> T;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        f[x].push_back(y);
    }
    for (i = 1; i < T; i++)
    {
        sort(f[i].begin(),f[i].end());
        ll sz = f[i].size();
        if (sz%2 == 1)
        {
         f[i+1].push_back(f[i][0]);
         for (j = 1; j < sz; j+= 2)
             f[i+1].push_back(f[i][j] + f[i][j+1]);
        } else
        {
         for (j = 0; j < sz; j+= 2)
             f[i+1].push_back(f[i][j] + f[i][j+1]);
        }
    }
    sort(f[T].begin(),f[T].end());
    ll sz = f[T].size();
    cout << f[T][sz-1] << endl;
    return 0;
}
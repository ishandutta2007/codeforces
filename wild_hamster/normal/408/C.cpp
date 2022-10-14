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
ll a[100500],c[300],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f[100500];
string s[200000];
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
ll dist(ll x1, ll y1, ll x2, ll y2)
{
 return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
void out(ll x1, ll y1, ll x2, ll y2)
{
     cout << "YES" << endl;
     cout << 0 << " " << 0 << endl;
     cout << x1 << " " << y1 << endl;
     cout << x2 << " " << y2 << endl;
}
int main()
{
    cin >> n >> k;
    {
    ll ni = 0,nj = 0,ki = 0,kj = 0;
    for (i = 1; i < n; i++)
        for (j = max(1LL,(ll)sqrt(n*n-i*i)-2); j < sqrt(n*n-i*i)+2; j++)
            if (i*i+j*j == n*n)
            {
               ni = i, nj = j;
    for (ll i1 = 1; i1 < k; i1++)
        for (ll j1 = max(1LL,(ll)sqrt(k*k-i1*i1)-2); j1 < sqrt(k*k-i1*i1)+2; j1++)
            if (i1*i1+j1*j1 == k*k)
               {
               ki = i1, kj = j1;
               //out(ki,kj,-ni,-nj);
               if (dist(ki,kj,-ni,nj) == k*k+n*n && kj!=nj) {out(ki,kj,-ni,nj);return 0;}
               if (dist(kj,ki,-ni,nj) == k*k+n*n && ki!=nj) {out(kj,ki,-ni,nj);return 0;}
               if (dist(ki,kj,-nj,ni) == k*k+n*n && kj!=ni) {out(ki,kj,-nj,ni);return 0;}
               if (dist(kj,ki,-nj,ni) == k*k+n*n && ki!=ni) {out(kj,ki,-nj,ni);return 0;}
               }
            }
    
    }
    cout << "NO" << endl;
   return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 998244353
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef int ll;
using namespace std;

ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,x,y,z,max1,pnt,compr[200500];
string s1,s2,s3;
ll a[305305],cnt[305],b[305305],pb[205305][230],good[305305];
vector <ll> segments;
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
void do_stuff()
{
    ll start, i, j,k,x;
    segments.clear();
    ll fflag = 1;
    for (i = 0; i < n; i++)
        if (good[i] != 1)
           fflag = 0;
    if (fflag)
    {
        pb[n+1][pnt] = n;
        return;
    }
   for (i = 0; i < n; i++)
   {
       ll prv = i-1;
       if (prv < 0)
          prv += n;
       if (good[i] == 1 && good[prv] == 0)
       {
        start = i;
        break;
       }
   }
    x = start;
    ll flag = 0;
    while (x != start || flag != 1)
    {
        flag = 1;
        k = 0;
        while (good[x] == 1)
        {
            k++;
            x++;
            if (x == n)
               x = 0;
        }
        segments.push_back(k);
        while (good[x] != 1)
        {
            x++;
            if (x == n)
               x = 0;
        }
    }
    for (i = 0; i <= n; i++)
        b[i] = 0;
    for (i = 0; i < segments.size(); i++)
    {
        for (j = 0; j < segments[i]; j++)
            b[j+1]++;
    }
    for (i = 1; i <= n+1; i++)
        pb[i][pnt] = pb[i-1][pnt] + b[i];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   ll max1 = 0;
   for (i = 0; i < n; i++)
   {
       scanf("%d",&a[i]);
       max1 = max(max1,a[i]);
   }
   ll flag = 1;
   for (i = 0; i < n-1; i++)
       if (a[i] != a[i+1])
          flag = 0;
   if (flag)
   {
    cout << (long long)n*(n-1) << endl;
    return 0;
   }
   long long ans = 0;
    for (i = 1; i < n; i++)
    {
        if (n%i != 0)
        {
            ll x = gcd(n,i);
            ans += pb[n+1][compr[x]] - pb[i-1][compr[x]];
        } else
        {
            for (j = 0; j < n; j++)
                good[j] = 0;
            for (j = 0; j < i; j++)
            {
                ll max1 = 0;
                for (k = j; k < n; k += i)
                    max1 = max(max1,a[k]);
                for (k = j; k < n; k += i)
                    if (a[k] == max1)
                       good[k] = 1;
            }
            compr[i] = pnt;
            do_stuff();
            ans += pb[n+1][pnt] - pb[i-1][pnt];
            pnt++;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef int ll;
using namespace std;
ll minor[10][10],i,j,x1,y1,x2,y2,n,k,k1,k2,m,y,x,p;
string s;
ll a[100500],b[100500],sum[100500],c[100500],used[100500];
vector <ll> gav, fir;
ll Abs(ll x)
{
    if (x < 0)
       return -x;
    return x;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}

int main()
{
    cin >> n;
    for (i = 1; i <= 100000; i++)
        b[i] = c[i] = sum[i] = INF;
    for (i = 0; i < n; i++)
    {
     scanf("%d",&a[i]);
     //a[i] = i+1;
     x = a[i];
     ll tmp = 0;
     if (i == 0)
     while (x != 0)
     {
        ll sec_tmp = tmp;
        for (j = x; j <= 100000; j<<=1)
        {
            b[j] = min(b[j],sec_tmp);
            sec_tmp++;
            if (!used[j])
            {
            used[j] = 1;
            sum[j] = 0;
            fir.push_back(j);
            }
        }
        tmp++;
        x >>= 1;
     }
    }
    for (i = 1; i <= 100000; i++)
        used[i] = 0;
    for (i = 0; i < n; i++)
    {
     x = a[i];
     ll tmp = 0;
     while (x != 0)
     {
        ll sec_tmp = tmp;
        for (j = x; j <= 100000; j<<=1)
        {
            c[j] = min(c[j],sec_tmp);

            sec_tmp++;
            if (!used[j])
            {
            
            used[j] = 1;
            gav.push_back(j);
            }
        }
        tmp++;
        x >>= 1;
     }
     for (j = 0; j < fir.size(); j++)
     {
        //cout << a[i] << " " << fir[j] << " " << c[fir[j]] << endl;
       sum[fir[j]] += c[fir[j]];
       if (sum[fir[j]] > INF)
          sum[fir[j]] = INF;
     }
     for (j = 0; j < gav.size(); j++)
     {
      c[gav[j]] = INF;
      used[gav[j]] = 0;
     }
     gav.clear();
    }
    ll min1 = INF;
    for (i = 1; i <= 100000; i++)
    {
        min1 = min(min1,sum[i]);
    }
    cout << min1 << endl;
    return 0;
}
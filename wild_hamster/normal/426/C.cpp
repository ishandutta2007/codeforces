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
ll a[300],b[300],c[300],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f;

ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
    cin >> n >> x;
    for (i = 0; i < n; i++)
        cin >> a[i];
    rez = -1005;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
    {
        ll cntb = 0, cntc = 0;
        for (k = i; k <= j; k++)
            b[cntb++] = a[k];
        for (k = 0; k < i; k++)
            c[cntc++] = a[k];
        for (k = j+1; k < n; k++)
            c[cntc++] = a[k];
        sort(b,b+cntb);
        sort(c,c+cntc);
        ll br = cntb - 1, cr = cntc - 1;
        ll sum = 0;
        y = x;
        for (k = 0; k < cntb; k++)
            if (cr >= 0 && c[cr] > b[br] && y > 0)
            {
               y--;
               sum+=c[cr];
               cr--;
            } else
            {
              sum += b[br];
              br--;
            }
        rez = max(rez,sum);
    }
    cout << rez << endl;
   return 0;
}
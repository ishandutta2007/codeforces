 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll x1,x2,a1,b1,l,r,j,x,m,k,rez,rez2,cnt,i,n,min1,a[2000],b[2000],p,q,d[2000];
pair <ll,ll> c[2000];

ll lalka(ll x)
{
 if (x == 0) return 0;
 else return 3 + (x-1)*2;
}
ll kub(ll n, ll m, ll k)
{
 return 3*n*m*k+2*n*m+2*m*k+2*n*k+m+n+k;
}        

int main()
{
    cin >> p >> q >> l >> r;
    rez = 0;
    for (i = 0; i < p; i++)
    {
        cin >> x1 >> x2;
        for (j = x1; j <= x2; j++)
            a[j] = 1;
    }
    for (i = 0; i < q; i++)
    {
        cin >> x1 >> x2;
        c[i] = mp(x1,x2);
    }
    for (i = l; i <= r; i++)
    {
        for (j = 0; j <= 1000; j++)
            d[j] = 0;
        for (j = 0; j < q; j++)
        for (k = c[j].first; k<= c[j].second; k++)
            d[k+i] = 1;
        for (j = 0; j <= 1000; j++)
        if (a[j]&& d[j]) {rez++;break;}
    }
    cout << rez << endl;
    return 0;
}
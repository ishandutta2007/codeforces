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
ll x1,x2,a1,b1,j,x,m,k,rez,rez2,cnt,d,i,n,min1,a[200],p,q;


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
    cin >> n;
    cin >> p;
    for (i = 0; i < p; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    k = 1;
    for (i = 1; i <= n; i++)
        if (a[i]!=1) k = 0;
    if (k) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;
    return 0;
}
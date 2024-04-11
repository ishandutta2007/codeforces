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
ll a[200500],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;

ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    rez = 0;
    sort(a,a+n);
    for (i = 0; i < n-1; i++)
        rez += a[i];
    if (rez <= m) cout << "YES" << endl;
       else cout << "NO" << endl;   return 0;
}
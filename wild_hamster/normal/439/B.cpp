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

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    rez = 0;
    for (i = 0; i < n; i++)
    {
        rez += a[i]*m;
        if (m > 1) m--;
    }
    cout << rez << endl;
   return 0;
}
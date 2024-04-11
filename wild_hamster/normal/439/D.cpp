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
ll a[100500],b[100500],parta[100500],partb[100500],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        f.push_back(a[i]);
    }
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
        f.push_back(b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    parta[0] = 0;
    for (i = 0; i < n; i++)
        parta[i+1] = parta[i]+a[i];
    partb[0] = 0;
    for (i = 0; i < m; i++)
        partb[i+1] = partb[i]+b[i];
    rez = (ll)1e+17;
    for (i = 0; i < f.size(); i++)
    {
        ll tmpa, tmpb;
        tmpa = upper_bound(a,a+n,f[i]) - a;
        tmpb = upper_bound(b,b+m,f[i]) - b;
        ll sum = partb[m]-partb[tmpb]-f[i]*(m-tmpb)+f[i]*tmpa-parta[tmpa];
        if (rez > sum) 
        {
           //cout << f[i] << " " << tmpa << " " << tmpb << endl;
           rez = min(rez,sum);
        }
    }
    cout << rez << endl;
   return 0;
}
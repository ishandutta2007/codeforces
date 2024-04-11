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
ll rez,l,r,n,m,k,j,p,pN,pM,k1,k2,i,x,a[100500],b[100500],ax[100500],partb[100500];
vector <ll> f[100500];
ll Abs(ll x)
{
 if (x < 0) return -x;
    return x;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
        cin >> a[i];
     if (m == 1)
     {
           cout << 0 << endl;
           return 0;           
     }
    for (i = 0; i < m; i++)
    {
    if (i == 0) {if (a[i+1] != a[i])
       f[a[i]].push_back(a[i+1]);}  else
    if (i == m-1) {if (a[i-1] != a[i])
       f[a[i]].push_back(a[i-1]);}  else
    {
    if (a[i] != a[i-1])
       f[a[i]].push_back(a[i-1]);
    if (a[i] != a[i+1])
       f[a[i]].push_back(a[i+1]);      
    }
    }
    rez = 0;
    for (i = 1; i <= n; i++)
    {
        /*for (j = 0; j < f[i].size(); j++)
            cout << f[i][j] << " ";
        cout << endl;*/
        ll sum = 0, sum1 = 0, sum2 = 0;
        for (j = 0; j < f[i].size(); j++)
            sum += Abs(f[i][j]-i);
        sort(f[i].begin(),f[i].end());
        ll tmp = f[i].size()/2;
        for (j = 0; j < f[i].size(); j++)
            sum1 += Abs(f[i][j]-f[i][tmp]);
        //cout << i << " " << sum << " " << sum1 << endl;
        rez = max(rez,Abs(sum-sum1));
    }
    rez = -rez;
    //cout << rez << endl;
    for (i = 1; i < m; i++)
        rez += Abs(a[i]-a[i-1]);
    cout << rez << endl;
  return 0;
}
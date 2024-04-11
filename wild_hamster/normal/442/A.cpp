#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
#include <complex>
//#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
#define PI 3.14159265358979323846
struct lalka
{
       ll r1,r2,r3;
};
bool ff(lalka a, lalka b)
{
     if (a.r1 > b.r1) return true;
     return false;
}
ll a[500500],b[50],c[100],d[50],e[50];
vector <ll> f;
ll i,j,x,l,r,k,n,k1,jk1,j2,k2,k3,y,m,w;
string s;
bool rak(ll x, ll y)
{
     if (x%10 != y%10) return true;
     if (x/10 != y/10) return true;
     return false;
}
int main()
{
cin >> n;
for (i = 0; i < n; i++)
{
    ll tmp = 0;
    cin >> s;
    if (s[0] == 'R') tmp = 10;
    if (s[0] == 'W') tmp = 20;
    if (s[0] == 'G') tmp = 30;
    if (s[0] == 'Y') tmp = 40;
    if (s[0] == 'B') tmp = 50;
    tmp += (int)s[1] - (int)'0';
    c[tmp] = 1;
}
k = 0;
for (i = 0; i < 60; i++)
    if (c[i] == 1)
       d[k++] = i;
  
ll min1 = 10;
for (i = 0; i < 1024; i++)
{
    ll lalka = 0;
    for (j = 0; j < 50; j++)
    {
        b[j] = 0;
        e[j] = 0;
    }
    for (j = 1, l = 0; j < 1024; j*=2, l++)
        if (j&i)
        {
           b[l] = 1;
           lalka++;
        }

    for (l = 0; l < 5; l++)
    if (b[l])
        for (j = 0; j < k; j++)
            if (d[j]%10 == l + 1) e[j] += l+1;
            
    for (l = 5; l < 10; l++)
    if (b[l])
        for (j = 0; j < k; j++)
            if (d[j]/10 == l - 4) e[j] += (l-4)*10;
    bool z = true;
    for (j = 0; j < k; j++)
        for (l = 0; l < j; l++)
            if (!rak(e[j],e[l])) z = false;
    if (z) min1 = min(min1,lalka);
}
cout << min1 << endl;
return 0;
}
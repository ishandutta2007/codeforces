#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector <ll> azaza;
ll i,n,j,k,k1,d,x,m,p,a[200500],b[200500];
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}
int main()
{
cin >> n >> m;
for (i = 0; i < m; i++)
{
    cin >> x >> a[i];
}
sort(a,a+m);
b[1] = 1;
for (i = 2; i < 10000; i++)
    b[i] = max((i/2)*i,(i*(i-1))/2+1);
x = upper_bound(b,b+10000,n) - b - 1;
ll rez = 0;
for (i = m-1; i >= 0 && x; i--, x--)
{
    rez += a[i];
} 
cout << rez << endl;
//for (i = 1; i < 15; i++)
//    cout << b[i] << " ";
return 0;
}
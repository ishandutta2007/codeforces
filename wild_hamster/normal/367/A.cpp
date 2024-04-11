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
ll i,n,j,k,k1,d,x,m,a[100500][4],b[100500];
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
string s;
cin >> s;
for (i = 0; i < 3; i++)
    a[0][i] = 0;
for (i = 1; i <= s.size(); i++)
    {
         for (j = 0; j < 3; j++)
             a[i][j] = a[i-1][j];
         if (s[i-1] == 'x') a[i][0]++;
         if (s[i-1] == 'y') a[i][1]++;
         if (s[i-1] == 'z') a[i][2]++;
    }
cin >> m;
for (i = 0; i < m; i++)
{
    ll l,r;
    cin >> l >> r;
    ll tmp[5];
    for (j = 0; j < 3; j++)
        tmp[j] = a[r][j] - a[l-1][j];
    sort(tmp,tmp+3);
    if (tmp[2] - tmp[0] <= 1 || r-l < 2)
       cout << "YES" << endl;
     else
    cout << "NO" << endl;    
}
return 0;
}
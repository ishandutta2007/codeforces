#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector <ll> azaza;
ll i,n,j,k,k1,d,x,m,a[100500],dp[500500],poss_sum[500500];
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
cin >> n;
for (i = 0; i < n; i++)
{
    ll j1,j2;
    vector <ll> K;
    char a[10][10];
    for (j1 = 0; j1 < 8; j1++)
        for (j2 = 0; j2 < 8; j2++)
            {
            cin >> a[j1][j2];
            if (a[j1][j2] == 'K')
            {
            K.pb(j1);K.pb(j2);
            }
            }
    bool z = false;
    ll k1,k2;
    k1 = (Abs(K[0]-K[2])) % 4;
    k2 = (Abs(K[1]-K[3])) % 4;    
    if (k1 == k2 && k1 == 0)
    {
        //   cout << "lalka" << endl;
    for (j1 = 0; j1 < 8; j1++)
        for (j2 = 0; j2 < 8; j2++)
            if ((Abs(j1-K[0]+j2-K[1]))%4 == 0 && 
            (Abs(j1-K[0]))%2 == 0 && (Abs(j2-K[1]))%2 == 0 && 
            (a[j1][j2] == '.'||a[j1][j2] == 'K'))
               z = true;
    K.clear();
    } 
    if (z) cout << "YES" << endl;      
       else cout << "NO" << endl;
}
return 0;
}
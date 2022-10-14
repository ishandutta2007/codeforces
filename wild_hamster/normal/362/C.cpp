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
ll i,n,j,k,k1,d,x,m,a[100500],dp[500500],b[5005][5005];
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
set <int>::iterator itl,itr;
int main()
{
cin >> n;
for (i = 0; i < n; i++)
    cin >> a[i];
ll rez = 0;
ll max1 = -1;
for (i = 0; i < n - 1; i++)
    for (j = i+1; j < n; j++)
     if (a[i] > a[j]) rez++;
for (i = 0; i < n; i++)
if (i < a[0])
    b[0][i] = 0;
else
    b[0][i] = 1;
for (i = 1; i < n; i++)
    for (j = 0; j < n; j++)
        if (j >= a[i])
           b[j][i] = b[j][i-1] + 1;
        else
            b[j][i] = b[j][i-1];
//for (i = 0; i < n; i++)
//{
// for (j = 0; j < n; j++)
//     cout << b[i][j] << " ";
 //cout << endl;   
//}
for (i = 0; i < n - 1; i++)
{
    if (a[i] > max1)
    {
    max1 = a[i];
    for (j = i+1; j < n; j++)
    {
        if (a[i] > a[j])
           {
                 ll k = 2*(b[a[i]][j-1] - b[a[i]][i] - b[a[j]][j-1] + b[a[j]][i]) + 1;
                 dp[k]++;
           } 
    }
    }
}
for (i = 150000; i >= 0; i--)
{
    if (dp[i] > 0)
       {
             cout << rez-i << " " << dp[i] << endl;
             break;
       }
}
return 0;
}
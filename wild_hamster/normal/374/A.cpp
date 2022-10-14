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
#define N 5000
#define NN 25000000
vector <ll> azaza;
ll i,j,m,n,k,a,b,x1,x2,y1,y2;
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
cin >> n >> m >> i >> j >> a >> b;
if ((i - a < 1 && i + a > n)||(j - b < 1 && j + b > m))
{
if ((i == n && j == m)||(i == n && j == 1)||(i == 1 && j == m)||(i == 1 && j == 1)) 
{
cout << 0 << endl;
return 0;
}
else
{
cout << "Poor Inna and pony!" << endl;
return 0;
}
}
if ((n-i)%a == 0) x1 = (n-i)/a; else x1 = -1;
if ((i-1)%a == 0) x2 = (i-1)/a; else x2 = -1;
if ((m-j)%b == 0) y1 = (m-j)/b; else y1 = -1;
if ((j-1)%b == 0) y2 = (j-1)/b; else y2 = -1;
ll min1 = (ll)1e+9;
if (x1!=-1  && y1!=-1 && x1%2 == y1%2) min1 = min(max(x1,y1),min1);
if (x1!=-1 && y2!=-1 && x1%2 == y2%2) min1 = min(max(x1,y2),min1);
if (x2!=-1 && y1!=-1 && x2%2 == y1%2) min1 = min(max(x2,y1),min1);
if (x2!=-1 && y2!=-1 && x2%2 == y2%2) min1 = min(max(x2,y2),min1);
if (min1 != (ll)1e+9)
   cout << min1 << endl;
else
    cout << "Poor Inna and pony!" << endl;
return 0;
}
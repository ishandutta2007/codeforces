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
ll i,j,m,n,k,a[100500],b,x1,x2,y1,y2;
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
n = s.size();
for (i = 0; i < 100500; i++)
    a[i] = 9;
for (i = 0; i < s.size(); i++)
    a[i] = (ll)s[i] - (ll)'0';
i = 0;
ll rez = 1;
while (i < n+15)
{
 k = 0;
 while (a[i] + a[i+1] == 9 && i < n+15) 
{
 i++;
 k++;
}
if (k%2 == 0) rez *= (ll)((k/2)+1);
i++;
}
cout << rez << endl;
return 0;
}
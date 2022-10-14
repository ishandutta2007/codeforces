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
ll i,j,m,n,k,a[1000500],b[15],x1,x2,y1,y2;
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
//cout << 6891%7 << endl;
cin >> s;
n = s.size();
j = 0;
b[1] = 1; b[6] = 1; b[8] = 1; b[9] = 1;
for (i = 0; i < n; i++)
if (!b[(int)s[i]-(int)'0']) 
   a[j++] = (int)s[i]-(int)'0';
else 
   b[(int)s[i]-(int)'0']--;
n = j;
ll tmp = 0;
for (i = 0; i < n; i++)
    tmp = (tmp*10 + a[i]) % 7;
tmp = (tmp*10000) % 7;
//cout << tmp << endl;
j = 0;
while (a[j] == 0 && j < n) { j++;}
for (i = j; i < n; i++)
    printf("%d",a[i]);
if (tmp == 0) cout << "1869";
if (tmp == 1) cout << "1896";
if (tmp == 2) cout << "8916";
if (tmp == 3) cout << "1698";
if (tmp == 4) cout << "6891";
if (tmp == 5) cout << "1689";
if (tmp == 6) cout << "8961";
ll lal = 0;
for (i = 0; i < j; i++)
    printf("%d",lal);
cout << endl;
return 0;
}
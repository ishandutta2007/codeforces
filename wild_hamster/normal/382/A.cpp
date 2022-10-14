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
vector <ll> lal;
ll i,j,t,i1,m,n,k,x,y,x1,x2,y1,y2,rez,b[1000500],c[1000500],k1,k2,n1,m1;
ll a[1000500];
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
string s1,s2,s3,s;
int main()
{
char c;
cin >> s;
ll z = 0;
for (i = 0; i < s.size(); i++)
{
      if (s[i] == '|') { z++; continue;}
 if (!z) s1.pb(s[i]); else s2.pb(s[i]);

}
cin >> s3;
ll k1 = s1.size(), k2 = s2.size(), k3 = s3.size();
n = (k1 + k2 + k3)/2;
if ((s1.size() + s2.size() + s3.size())%2 || k1 + k3 < n || k2 + k3 < n) 
   cout << "Impossible" << endl;
else
{
    j = 0;
    for (i = k1; i < n; i++)
        s1.pb(s3[j++]);
    for (i = k2; i < n; i++)
        s2.pb(s3[j++]);
    cout << s1 << "|" << s2 << endl;
}
return 0;
}
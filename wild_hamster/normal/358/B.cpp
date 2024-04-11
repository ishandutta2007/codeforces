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
ll x,mid,x1,x2,z,max1,i,j,k,n,y,lp,rp,p,l,r,ql,qr,m,M_cnt,k1,k2,ost,ur,a[100500];
string s[100005];
vector <ll> f;
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
int main()
{
ll rez;
string s1,s2,s3;
cin >> n;
for (i = 0; i < n; i++)
    {
    cin >> s[i];
    s[i].pb('<');
    s[i].pb('3');
    }
cin >> s1;
k = 0;
for (i = 0; i < s1.size(); i++)
    {
    if (s1[i] == '<') k = 1;
    if (s1[i] == '3' && k == 1) break;
    }
k = i+1;
for (i = 0; i < n; i++)
    {
         x = 0;
         z = 0;
         for (j = k; j < s1.size(); j++)
         {
             if (s1[j]==s[i][x]) x++;
             if (x == s[i].size()) {z = 1;break;}
         }
    k = j+1;
    if (k >= s1.size()) break;
    }
if (i >= n-1 && z)
   cout << "yes" << endl;
else
    cout << "no" << endl;
return 0;
}
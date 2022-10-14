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
ll sum,max1,i,j,k,x,n,y,m,k1,k2,ost,ur,a[100500],a1[5000],a2[5000],used[100500],pos;
ll Abs(ll a)
{
    if (a<0) return -a; else return a;
}
int main()
{
string s;
cin >> n;
k = 0;
for (i = 0; i < 2*n; i++)
{
    cin >> s;
    for (j = s.size()-3; j < s.size(); j++)
    a[i] = a[i]*10 + (int)s[j] - 48;
    sum += a[i];
    if (a[i] == 0)
       k++;
}
ll rez = (ll) 1e+9;
for (i = (n-k)*1000; i <= n*1000; i+=1000)
    rez = min(rez, Abs(sum-i));
if (rez < 0) rez = -rez;
if (rez % 1000 >= 100)      
   cout << rez/1000 << "." << rez%1000 << endl;
else if (rez % 1000 >= 10)  
   cout << rez/1000 << ".0" << rez%1000 << endl; 
else 
   cout << rez/1000 << ".00" << rez%1000 << endl; 
return 0;
}
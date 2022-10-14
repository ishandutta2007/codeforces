#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll a[100500],b[100500],e[100000],ee[1000],d[1000000],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur;
vector<ll> rez;
string s,t,s2;
map<ll,vector <ll> > f;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
   cin >> n;
   x = 45*18;
   for (i = 0; i < 17; i++)
       x = (x*10LL)%n;
   cout << n-x << " " << n-x+(ll)1e+18-1;
   return 0;
}
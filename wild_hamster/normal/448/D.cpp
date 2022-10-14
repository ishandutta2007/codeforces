#include <iostream>
//#include <cmath>
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
ll a[100500],b[100500],z,cnt,tmp,l,x1,x2,x3,x4,x5,x6,r,n,m,x,y,k,j,p,k1,k2,i,cur;
ll rez;
string s,t,s2;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
   cin >> n >> m >> k;
   l = 1; r = n*m;
   while (l < r)
   {
         ll tmp = 0;
         ll mid = (l+r-1)/2;
         for (i = 1; i <= m; i++)
             tmp += min(n,mid/i);
         if (tmp < k)
            l = mid+1;
         else
             r = mid;
   }
   cout << l << endl;
   return 0;
}
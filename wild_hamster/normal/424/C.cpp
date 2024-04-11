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
ll a[1000500],xors[1000500],z,cnt,tmp,e,l,r,s,n,m,j,p,k1,k2,i,cur,rez;
vector <ll> f,g,primes[100500];
int main()
{   
   //cin >> n;
   rez = 0;
   cin >> n;
   for (i = 0; i < n; i++)
   {
       scanf("%d",&a[i]);
       rez ^= a[i];
   }
   xors [0] = 0;
   for (i = 1; i <= n; i++)
       xors[i] = (xors[i-1]^i);
   for (i = 1; i <= n; i++)
   {
       if ((n/i)%2 == 1)
          rez ^= xors[i-1];
       rez ^= xors[n%i];
   }
   cout << rez << endl;
   return 0;
}
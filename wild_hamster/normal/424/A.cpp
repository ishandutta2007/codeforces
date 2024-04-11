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
ll a[100500],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f,g,primes[100500];
string s;

int main()
{   
   cin >> n;
   cin >> s;
   ll small = 0;
   for (i = 0; i < n; i++)
       if (s[i] == 'x') 
          small++;
   if (small > n/2)
      cout << small-n/2 << endl;
   else
       cout << n/2 - small << endl;
   for (i = 0; i < n; i++)
       if (s[i] == 'x' && small > n/2)
          s[i] = 'X', small--;
       else
       if (s[i] == 'X' && small < n/2)
          s[i] = 'x', small++;
   cout << s << endl;
   return 0;
}
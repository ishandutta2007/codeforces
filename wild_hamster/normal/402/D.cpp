#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll n,m,j,p,l,r,t,x,y,k1,k2,k3,k4,k,i,a[100500],b[100500],prime[33333],part[6000],w,rez;
vector <ll> primes;
map <ll,ll> isbad;
ll gcd(ll a, ll b)
{
 if (a%b == 0)
    return b;
 else
     return gcd(b,a%b);
}
ll f(ll x)
{
 //cout << "lalka" << endl;
 ll rez = 0;
 for (ll i = 0; i < primes.size(); i++)
     while (x%primes[i] == 0)
     {
           if (isbad[primes[i]]) rez--;
              else rez++;
           x/=primes[i];
     }
 if (x > 1)
 {
 if (isbad[x])
    rez--;
 else
     rez++;
 }
 return rez;
}
int main()
{
 for (i = 2; i < 33000; i++)
     prime[i] = 1;
 for (i = 2; i < 33000; i++)
     if (prime[i])
     {
      primes.push_back(i);
      for (j = i*i; j < 33000; j+=i)
          prime[j] = 0;
     }
  cin >> n >> m;
  for (i = 0; i < n; i++)
      cin >> a[i];
  for (j = 0; j < m; j++)
  {
      cin >> b[j];
      isbad[b[j]] = 1;
  }  
  for (i = n-1; i >= 0; i--)
  {
      x = a[0];
      for (j = 1; j <= i; j++)
       x = gcd(x,a[j]);
      if (f(x) < 0)
      for (j = 0; j <= i; j++)
          a[j]/=x;
  }
  rez = 0;
  for (i = 0; i < n; i++)
      rez += f(a[i]);
  cout << rez << endl;
   return 0;
}
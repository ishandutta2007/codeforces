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
ll a[100500],t,b[100500],fact[100500],invalid[100500],prime[100500],z,cnt,tmp,e,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f,g,primes[100500];
ll binpow(ll x, ll n)
{
 if (n == 0) return 1LL;
 ll tmp = binpow(x,n/2);
 if (n%2 == 1)
    return ((ll)x*(((ll)tmp*(ll)tmp)%(ll)tr))%(ll)tr;
 return ((ll)tmp*(ll)tmp)%(ll)tr;
}
ll inv(ll x)
{
 return invalid[x];
}
ll C(ll n, ll k)
{
        if (n < 0||k < 0) return 0;
        if (n < k) return 0LL;
        return ((((ll)fact[n]*(ll)inv(n-k))%tr)*(ll)inv(k))%(ll)tr;
}
int main()
{
   invalid[0] =  fact[0] = 1;
   invalid[1] = fact[1] = 1;
   
   for (i = 2; i < 100005; i++)
   {
       fact[i] = ((ll)fact[i-1]*(ll)i)%(ll)tr;
       invalid[i] = binpow(fact[i],tr-2);
   }
   for (i = 2; i < 100005; i++)
       prime[i] = 1;
   for (i = 2; i < 100005; i++)
       if (prime[i])
       for (j = i; j <100005; j+=i)
       {
       if (j!=i)
           prime[j] = 0;
       primes[j].push_back(i);
       }
   cin >> x;
   for (t = 0; t < x; t++) 
   {
       scanf("%d%d",&n,&y);
       rez = (ll)C(n-1,n-y);
       f.clear();
       //cout << primes[n].size() << endl;
       for (i = 0; i < primes[n].size(); i++)
           {
                //cout << primes[n][i] << endl;
                   rez = ((ll)rez-(ll)C(n/primes[n][i]-1,y-1)+4LL*tr)%(ll)tr;
                   f.push_back(primes[n][i]);                  
           }
       ll cnt = f.size();
       ll z;
       for (i = 0; i < (1<<cnt); i++)
       {
           ll bits = 0;
           ll x = 1;
           for (j = 0; j < cnt; j++)
           if (i&(1<<j)) 
           {
           bits++;
           x*=f[j];
           if (x > 100000) break;
           }
           if (bits%2 == 0) z = -1; else z = 1;
           if (bits > 1 && x <= 100000)
              rez = ((ll)rez-(ll)C(n/x-1,n/x-y)*z+4LL*tr)%(ll)tr;            
       }
       if (y == 1&& n == 1) rez = 1;
       else if (y == 1) rez = 0;
       printf("%I64d\n",rez);
   } 
   return 0;
}
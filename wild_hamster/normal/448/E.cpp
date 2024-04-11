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
void dfs(ll n)
{
// cout << n << endl;
     ll i;
     if (f[n].size() > 0) return;
     ll x = (ll)sqrt(n);
   for (i = 1; i <= x; i++)
   if (n % i == 0)
   {
       if (i == x&& x*x == n) 
       {f[n].push_back(x); 
       dfs(x);
       }else
       {             
             f[n].push_back(i);
             f[n].push_back(n/i);
             dfs(i);
             dfs(n/i);
       }
   }   
   sort(f[n].begin(),f[n].end());
}
int main()
{
   cin >> n >> k;
   if (n == 1)
   {
         cout << 1 << endl;
         return 0;
   }
   x = (ll)sqrt((ll)n);
   z = 1;
   for (i = 2; i <= x; i++)
     if (n % i == 0)
         z = 0;
   if (z)
   {
         if (k >= 100000)
            for (i = 0; i < 100000; i++)
                cout << 1 << " ";
         else
         {
             for (i = 0; i < k; i++)
                 cout << 1 << " ";
             cout << n << endl;
         }
         return 0;
   }
   dfs(n);
   
   {
         a[0] = n;
         for (i = 0; i < min(k,500LL); i++)
         {         
         cnt = 0;
             for (j = 0; j < 100000; j++)
             {
             if (a[j] == 0) break;
                else
                {
                 if (a[j] == 1)
                 b[cnt++] = 1;
                 else
                 for (x = 0; x < f[a[j]].size(); x++)
                 {
                 b[cnt++] = f[a[j]][x];
                 if (cnt > 100000) break;
                 }
                }
              if (cnt > 100000) break;
             }
             for (j = 0; j < 100000; j++)
                 a[j] = b[j];
         }
         if (k < 500)
         {
         for (i = 0; i < 100000; i++)
             if (a[i] == 0) { break;}
                else cout << a[i] << " ";
         return 0;
         }
   } 
   cnt = 0;
   ll prev = 0;
   for (i = 0; i < 100000; i++)
   {
       if (a[i] != 1) e[cnt++] = a[i], ee[cnt-1] = i-prev,prev = i+1;
       
   }
   {
   for (i = k; i >= 0; i--)
   {
    for (j = 0; j < ee[k-i]+(k-500); j++)
    {
        rez.push_back(1);
        if (rez.size()>100000) break;
    }
    rez.push_back(e[k-i]);
    if (rez.size() > 100000) break;
   }
   for (i = 0; i < 100000; i++)
       cout << rez[i] << " ";
   }
   return 0;
}
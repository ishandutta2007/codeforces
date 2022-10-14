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
ll z,cnt,tmp,l,prev,r,a[100500],destroyed[500],n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel,rez;
pair <ll,ll> b[500],c[500];
string s,s1,s2;

int main()
{
   cin >> n >> k >> x;
   for (i = 0; i < n; i++)
       cin >> a[i];
   for (i = 0; i < n; i++)
   if (a[i] == x&&a[i-1]!=x)
   {
       for (j = 0; j < n; j++)
           destroyed[j] = 0;
       j = i;
       cnt = 0;
       while (a[j] == a[j+1]) j++;
       if (j - i + 1 >= 2)
       {
       cnt += j-i+1;
       for (k = i; k <= j; k++)
           destroyed[k] = 1;
       }
       ll can_destroy = 1;
       while (can_destroy)
       {
             k = 0;
             can_destroy = 0;
             ll kokoko = 0;
             prev = a[0];
             for (j = 0; j <= n; j++)
             {
                 if (!destroyed[j])
                 {
                  if (a[j] == prev) k++;
                     else 
                  {
                   if (k > 2) 
                   {
                   cnt += k;
                   can_destroy = 1;
                   for (k = kokoko; k < j; k++)
                       destroyed[k] = 1;
                   }
                   k = 1;
                   kokoko = j;
                  }
                  prev = a[j];
                 }
             }
       }
       rez = max(rez,cnt);
   }
   cout << rez << endl;
   return 0;
}
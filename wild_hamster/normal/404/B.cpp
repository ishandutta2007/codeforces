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
ll a[100500],s,n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,cur,rez,kokoko;
 char c;
 string s1,s2;
ll ht(string s)
{
 ll rez = 0, i = 0;
 while (s[i]!='.' && i < s.size())
 {
       rez = rez*10 + (int)s[i]-(int)'0';
       i++;
 }
 if (i == s.size())
 return rez*10000;
 else
 {
     ll rez1 = 0;
     for (int j = 0; j < 4; j++)
     {
         i++;
         if (i < s.size()) rez1 = rez1*10 + (int)s[i] - (int)'0';
            else rez1 *= 10;
     }
     return rez*10000+rez1;
 }
}
int main()
{
    double x,y;
    cin >> s1 >> s2;
    n = ht(s1);
    m = ht(s2);
    //cout << n << " " << m << endl;
    cin >> k;
    rez = 0;
    for (i = 0; i < k; i++)
    {
        rez += m;
        ll tmp = rez %(4*n); 
        if (tmp <= n) printf("%.4f 0\n",tmp/10000.); else
        if (tmp <= 2*n) printf("%.4f %.4f\n",n/10000.,(tmp-n)/10000.); else
        if (tmp <= 3*n) printf("%.4f %.4f\n",(3*n-tmp)/10000.,n/10000.); else
        printf("0 %.4f\n",(4*n-tmp)/10000.);
    }
   return 0;
}
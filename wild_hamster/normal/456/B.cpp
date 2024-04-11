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
ll t[400500],z[400500],rez,l,r,n,m,k,j,p,k1,k2,i;
pair <ll,ll> a[500000];
string s;
int main()
{
   cin >> s;
   if (s.size() == 1)
   {
    p = (int)s[0]-(int)'0';
    rez = 1;
    if (p%2 == 1) rez += 4; else rez += 1;
    if (p%4 == 1) rez += 5; else if (p%4 == 2) rez += 8; else
    if (p%4 == 3) rez += 5; else rez += 2;
    rez %= 5;
    cout << rez << endl;
   }
   else
   {
       n = s.size();
       p = ((int)s[n-2]-(int)'0')*10 + ((int)s[n-1]-(int)'0');
       rez = 1;
       if (p%2 == 1) rez += 4; else rez += 1;
       if (p%4 == 1) rez += 5; else if (p%4 == 2) rez += 8; else
       if (p%4 == 3) rez += 5; else rez += 2;              
       p = 0;
       cout << rez%5 << endl;
   }    
   return 0;
}
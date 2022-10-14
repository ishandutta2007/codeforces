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
int z,cnt,tmp,l,r,a[100500],b[100500],n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel,rez,color[2005],amnt[2005];

string s,s1,s2;
bool ifdif(ll x)
{
     ll a[10];
     for (int i = 0; i < 10; i++)
         a[i] = 0;
     while (x > 0)
     {
           if (a[x%10] == 1) return false;
           a[x%10] = 1;
           x/=10;
     }
     return true;
}
int main()
{
    cin >> n;
    n++;
    while (!ifdif(n)) n++;
    cout << n << endl;
   return 0;
}
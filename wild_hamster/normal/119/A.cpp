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
int z,cnt,tmp,l,r,a[10],n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel,rez,color[2005],amnt[2005];

string s,s1,s2;
ll gcd(ll a, ll b)
{
 if (a%b == 0) return b;
 else return gcd(b,a%b);
}
int main()
{
    cin >> a[0] >> a[1] >> n;
    rez = 0;
    while (n > 0)
    {
          n -= gcd(a[rez%2],n);
          rez++;
    }
    rez++;
    cout << rez%2 << endl;
   return 0;
}
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
ll gcd(ll a, ll b)
{
 if (a%b == 0) return b;
 else return gcd(b,a%b);
}
int main()
{
    cin >> s;
    for (i = 0; i < s.size(); i++)
        if (s[i] == '4' || s[i] == '7')
           rez++;
           if (rez == 4 || rez == 7)
    cout << "YES" << endl; else cout << "NO" << endl;
   return 0;
}
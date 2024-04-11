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
int z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,maxlevel,rez,color[2005],amnt[2005];

string s,s1,s2;
int miny,maxy,maxx,minx;
int main()
{
   cin >> s1 >> s2;
   for (i = 0; i < s1.size(); i++)
       if (s1[i] < 'a') s1[i] += 'a' - 'A';
   for (i = 0; i < s2.size(); i++)
       if (s2[i] < 'a') s2[i] += 'a' - 'A';
   if (s1 < s2) cout << -1 << endl;
   if (s1 > s2) cout << 1 << endl;
   if (s1 == s2) cout << 0 << endl;
   return 0;
}
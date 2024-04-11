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

string s;
int miny,maxy,maxx,minx;
int main()
{
   cin >> s;
   z = 0;
   for (i = 0; i < s.size(); i++)
       if (s[i] == 'H'||s[i] == 'Q'||s[i] == '9')
          z = 1;
   if (z)
      cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}
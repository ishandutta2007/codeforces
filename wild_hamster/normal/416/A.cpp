#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 100500
#define eps 1e-9
ll a[1000500],b[500500],used[1000500],x,y,i,j,n,m,k,q,max1,min1;
vector <ll> f,g,rez;
int main()
{
string s1,s2;
min1 = 2*(ll)1e+9;
max1 = -2*(ll)1e+9;
cin >> n;
for (i = 0; i < n; i++)
{   
    cin >> s1 >> x >> s2;
    if (s1 == ">")
    {
       if (s2 == "Y") max1 = max(x, max1);
          else min1 = min(x+1, min1);
    }  else
    if (s1 == ">=")
    {
       if (s2 == "Y") max1 = max(x-1, max1);
          else min1 = min(x, min1);
    }  else
    if (s1 == "<")
    {
       if (s2 != "Y") max1 = max(x-1, max1);
          else min1 = min(x, min1);
    }  else
    if (s1 == "<=")
    {
       if (s2 != "Y") max1 = max(x, max1);
          else min1 = min(x+1, min1);
    } 
}
if (min1 - max1 >= 2)
   cout << max1 + 1 << endl;
else
    cout << "Impossible" << endl;
return 0;
}
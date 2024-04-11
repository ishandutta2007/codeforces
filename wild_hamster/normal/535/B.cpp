 #include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,x1,x2,x3,y1,y2,z,w,l,r,i,j,n,x,y,d,m,q,A,B,sz;
ll a[1400500],b[400500];
string s;
int main()
{
    cin >> s;
    n = s.size();
    ll ans = 0;
   for (i = 0; i < n; i++)
   if (s[i] == '4')
      ans = ans*2;
   else
       ans = ans*2+1;
   for (i = 1; i < n; i++)
       ans += (1<<i);
   cout << ans+1 << endl; 
    return 0;
}
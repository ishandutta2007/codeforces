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
ll z[400500],rez,cnt,tmp,l,r,n,m,k,j,p,k1,k2,i;
ll a[500000],dp[500000];


int main()
{
   cin >> n;
   if (n %2 == 1)
      cout << n-9 << " " << 9 << endl;
   else
       cout << 4 << " " << n-4 << endl;
//   cout << maxlevel << endl;   
   return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll n,m,j,p,a[100500],l,r,x,y,k1,k2,k3,k4,k5,k,i,w,rez,b[100500];

int main()
{
   cin >> a[0] >> a[1] >> a[2];
   sort(a,a+3);
   if (2*(a[0]+a[1]) <= a[2]) cout << a[0]+a[1] << endl;
      else cout << (a[0]+a[1]+a[2])/3 << endl;
   return 0;
}
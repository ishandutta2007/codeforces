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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k5,k,i,w,rez,b[100500];

int main()
{
   cin >> k1 >> k2 >> k3 >> k4 >> k5;
   rez = k1+k2+k3+k4+k5;
   if (rez%5 == 0 && rez!=0) cout << rez/5 << endl;
      else cout << -1 << endl;
   return 0;
}
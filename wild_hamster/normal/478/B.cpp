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
   cin >> n >> m;
   if (m == 1)
   cout << ((n-m+1)*(n-m))/2 << " " << ((n-m+1)*(n-m))/2 << endl;
        else
   {
    x = (n-1)/m+1;
    y = (n-1)/m;
    l = n%m;
    r = m - n%m;
    if (n%m == 0) swap(l,r);
    
    cout << (x*(x-1)*l)/2 + (y*(y-1)*r)/2 << " " << ((n-m+1)*(n-m))/2 << endl;
   }
   return 0;
}
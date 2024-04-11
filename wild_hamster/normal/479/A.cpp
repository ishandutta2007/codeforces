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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,b[100500];
ll a[100500];
vector <ll> f;
int main()
{
   cin >> k1 >> k2 >> k3;
   rez = 0;
   f.pb(k1+k2+k3);   
   f.pb(k1+k2*k3);
   f.pb(k1*k2+k3);
   f.pb(k1*k2*k3);
   f.pb((k1+k2)*k3);
   f.pb(k1*(k2+k3));
   for (i = 0; i < 6; i++)
       rez = max(rez,f[i]);
   cout << rez << endl;
   return 0;
}
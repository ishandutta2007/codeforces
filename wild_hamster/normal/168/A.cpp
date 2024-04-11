#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll i,j,x,n,y,m,k,k1,k2,ost,ur,a[100500],b[1300500],pos;
vector <ll> f[100500];
map <ll,ll> g;
int main()
{
cin >> n >> x >> y;
k = 0;
while (n * y > x * 100) 
      {
           x++;
           k++;
      }
cout << k << endl;
return 0;
}
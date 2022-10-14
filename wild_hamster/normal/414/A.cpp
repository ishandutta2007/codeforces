#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
//#include <cmath>
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
ll used[5000],sum,x,y,i,j,n,m,k,q,j1,max1,min1;
pair <ll,ll> b[5000],c[5000];
vector <pair<ll,ll> > f;

int main()
{
cin >> n >> k;
if (k < n/2 || (n == 1&&k) ) cout << "-1" << endl;
else if (n == 1 && k == 0) cout << 150 << endl;
else
{
    x = k - n/2 + 1;
    cout << x <<" " << 2*x << " ";
    y = 0;
    i = 1;
    while (y < n-2)
    {
          while (i == x || i == 2*x) i++;
          cout << i << " ";
          i++;
          y++;
    }
    
}
return 0;
}
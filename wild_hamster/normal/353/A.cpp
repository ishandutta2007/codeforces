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
vector <ll> azaza;
ll sum,max1,i,j,k,x,n,y,m,k1,k2,ost,ur,a[100500],pos;
vector <string> f;
int main()
{
string s;
cin >> n;
m = 0; ost = 0;
for (i = 0; i < n; i++)
{
    cin >> k1 >> k2;
    if (k1%2 != k2%2) 
       x = 1;
    m += k1+k2;
    ost += k1;
}
if (ost % 2 == 0 && m % 2 == 0) 
   cout << 0 << endl;
else
if (ost % 2 == 1 && m % 2 == 0 && x == 1) 
   cout << 1 << endl;
else 
     cout << -1 << endl;
return 0;
}
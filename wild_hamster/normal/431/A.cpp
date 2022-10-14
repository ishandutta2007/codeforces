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
ll c[15],a[1000][1000],sum,x,y,i,j,n,m,k,j1,r1,r2,min1;
string s, s1, gg;
set <ll> f,g;
map <ll,ll> f1,g1;
set<ll>::iterator q,q1;
int main()
{
cin >> c[1] >> c[2] >> c[3] >> c[4];
cin >> s;
k = 0;
for (i = 0; i < s.size(); i++)
    k += c[(int)s[i] - (int)'0'];
cout << k << endl;
return 0;
}
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
ll sum,max1,i,j,k,x,n,y,m,M_cnt,k1,k2,ost,ur,a[100500];
int main()
{
string s;
cin >> s;
n = s.size();
i = 0;
while (s[i] == 'F') i++;
ost = i;
for (i = ost; i < n; i++)
{
if (s[i] == 'F') k2++;
   if (s[i-1] == 'M') k = max((ll)0,k-1); else k++;
if (s[i] == 'F') k1 = k+i-ost+1;
}

//cout << m << endl;
cout << k1-k2 << endl;
return 0;
}
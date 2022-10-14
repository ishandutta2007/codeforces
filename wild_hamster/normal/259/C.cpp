#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll rez,sum,k,m,k1,k2,k3,i,n,j;
ll a[10][10];
vector <vector <ll> > f(100005);
int main()
{
string s;
cin>>s;
for (i=0;i<s.size();i++)
if (s[i]=='0'||i==s.size()-1) {s[i]='-';break;}
for (i=0;i<s.size();i++)
if (s[i]!='-') cout<<s[i];
return 0;
}
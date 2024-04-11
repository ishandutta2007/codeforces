#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000009
ll z,x,y1,y2,m,n,i,j,k,a[100500],b[100500];
int main()
{
string s;
cin>>s;
for (i=0;i<s.size();i++)
if ((int)s[i]<97) s[i]=(char)((int)s[i]+32);
b['a']=1;b['o']=1;b['u']=1;b['y']=1;b['i']=1;b['e']=1;
for (i=0;i<s.size();i++)
if (!b[s[i]]) cout<<'.'<<s[i];
return 0;
}
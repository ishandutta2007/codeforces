#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
ll a[300001],n,m,k,i,j,x1,x2,k1,k2;
int main()
{
string s;
cin>>k;
cin>>s;
n=s.size();
k1=0;
for (i=k;i<n;i+=k)
if (s[i-1]==s[i-2]&&s[i-2]==s[i-3]) k1++;
cout<<k1<<endl;
return 0;
}
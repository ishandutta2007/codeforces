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
ll rez,z,x,y1,y2,m,n,i,j,k,a[100500],b[100500];
map <string,ll> f;
int main()
{
string s;
cin>>n;
for (i=0;i<n;i++)
{
cin>>s;
if (f[s]==0) cout<<"OK"<<endl;
else cout<<s<<f[s]<<endl;
f[s]++;
}
return 0;
}
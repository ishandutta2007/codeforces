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
ll x,y1,y2,m,n,i,j,k,a[100500],b[100500];
int main()
{
string s;
cin>>n>>m;
k=1;ll rez=0;
for (i=0;i<m;i++)
{
cin>>x;
if (x>=k) rez+=x-k; else rez+=n+x-k;
k=x;
}
cout<<rez<<endl;
return 0;
}
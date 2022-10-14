#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>
#include <stdio.h>
typedef long long ll;
using namespace std;
int main()
{
ll k,d,n,s,a[101000],b[100100],k1,k2,k3,k4,m,j,i;
cin>>n>>m;
k1=0;k2=0;
for (i=0;i<n;i++)
{cin>>s;if (s==-1) k1++; else k2++;}
s=min(k1,k2);
for (i=0;i<m;i++)
{
cin>>k3>>k4;
if ((k4-k3)%2==1&&k4-k3+1<=2*s) cout<<1<<endl; else cout<<0<<endl;
}
return 0;
}
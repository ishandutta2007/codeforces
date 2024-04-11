#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
ll s,j,min1,i,m,n,k,k1,o,a[1000][2];
cin>>n;
for (i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
k=0;
for (i=0;i<n;i++)
for (j=0;j<n;j++)
if (a[i][0]==a[j][1]) k++;
cout<<k<<endl;
return 0;
}
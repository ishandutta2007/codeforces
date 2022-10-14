#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,k2,i,n,m,a[105][105],j,azaza,min1,z1,x,z2,yw,xb,yb,z;
vector <ll> a1,b1;
int main()
{
    char t;
cin>>n;
for (i=0;i<100;i++)
for (j=0;j<100;j++)
a[i][j]=0;
k=0;
while ((k*(k+1)*(k+2))/6<=n) k++;
k--;
n-=(k*(k+1)*(k+2))/6;
for (i=0;i<k+1;i++)
for (j=i+1;j<k+2;j++)
a[i][j]=1;
k+=2;
while (n)
{
k1=0;
while ((k1*(k1+1))/2<=n) k1++;
k1--;
n-=(k1*(k1+1))/2;
for (i=k-k1-1;i<k;i++)
a[i][k]=1;
k++;
}
cout<<100<<endl;
for (i=0;i<=99;i++)
{
for (j=0;j<=99;j++) cout<<max(a[i][j],a[j][i]);
cout<<endl;
}
//cout<<k<<" "<<n<<endl;
return 0;
}
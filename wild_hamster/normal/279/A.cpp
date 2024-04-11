#include <iostream>
using namespace std;
int main()
{
    int j,z,i,k,x,y,x1,y1;
    int a[250][250];
cin>>x>>y;
a[125][125]=0;
k=0;z=0;
x1=125;y1=125;
for (i=0;i<230;i++)
{
k=k+1;
if (k%2!=0)
{
 for (j=y1+1;j<=y1+k;j++)
 a[j][x1]=z;
y1=y1+k;
z++;
 for (j=x1+1;j<=x1+k;j++)
 a[y1][j]=z;
x1=x1+k;
z++;
}
else
{
  for (j=y1-1;j>=y1-k;j--)
  a[j][x1]=z;
  y1=y1-k;
  z++;
  for (j=x1-1;j>=x1-k;j--)
  a[y1][j]=z;
  x1=x1-k;
z++;
}
}
cout<<a[x+125][y+125];
return 0;
}
#include <iostream>
using namespace std;
int main(){
char a[25];
char x1[50],x2[700][2];
int k,i1,n,i,j;
int b[750];
for (i=97;i<=122;i++)
{
x1[i-97]=(char)i;
}
for (i=97;i<=122;i++)
for (j=97;j<=122;j++)
{
x2[(i-97)*26+j-97][0]=(char)i;
x2[(i-97)*26+j-97][1]=(char)j;
}
cin>>n;
for (i=0;i<750;i++)
b[i]=0;
for (i1=0;i1<n;i1++)
{
cin>>a;
for (i=0;i<22;i++)
if ((a[i]>=97)&&(a[i]<=122))
{
b[(int)a[i]-97]=1;
if ((a[i+1]>=97)&&(a[i+1]<=122))
{
b[((int)a[i]-96)*26+(int)a[i+1]-97]=1;
}
}
}
k=0;
while (b[k]==1)
k++;
if (k<26) cout<<x1[k];
else cout<<x2[k-26][0]<<x2[k-26][1];
return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
long long n,sum,a[20];
void dfs(int x[20],int k1,int y[20])
{
int i1;
for (i1=1;i1<=n;i1++)
if (x[(k1+i1-2)%n+1]!=1&&y[i1]!=1)
{
if (k1==n) sum++; else {x[(k1+i1-2)%n+1]=1;
y[i1]=1;dfs(x,k1+1,y);x[(k1+i1-2)%n+1]=0;
y[i1]=0;}
}
//return;
}
int main()
{
int t,i,j,k,z,b[20],c[20];
long long d[18]={0,1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0,0};
long long s;
cin>>n;
s=1;
for (i=1;i<=n;i++)
s=(s*i)%1000000007;
sum=0;
//dfs(b,1,c);
cout<<(s*d[n])%1000000007;
//system("pause");
return 0;
}
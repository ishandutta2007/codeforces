#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
long long a[110000],x1,x2,s1,s,t,i,j,n,m;
void dfs(long long k)
{
if (s1>n) {s1=-1;return;}     
if (k==t) return; else
{s1++;dfs(a[k]);}
}
int main()
{
cin>>n>>s>>t;
for (i=1;i<=n;i++)
{
scanf("%I64d",&a[i]);
}
if (s==t) {cout<<0;return 0;}
s1=0;
dfs(s);
cout<<s1;
return 0;
}
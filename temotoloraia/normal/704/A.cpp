#include <bits/stdc++.h>
using namespace std;
int mi[400009];
int z[400009];
int I[400009];
int k[400009];
int n,q,un;
int o=1;
int main()
{cin>>n>>q;
n=0;
for (int i=0; i<q; i++)
{
int a,b;
cin>>a>>b;
if(a==1)
{

n++;
un++;
z[n]=b;

k[b]++;
I[n]=k[b];
}
else
if(a==2)
{
un-=k[b]-mi[b];
mi[b]=k[b];}
else
{
for(int j=o; j<=b; j++)
{if(I[j]>mi[z[j]]) {mi[z[j]]++; un--;}}
o=max(o,b);}

printf("%d\n",un);
}
}
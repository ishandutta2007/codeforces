#include <stdio.h>
const int N=300050;
const int M=20*N;
int time,l[M],r[M],v[M],root[N];
void Set(int sp, int &sc, int ss, int se,int qi)
{
sc=++time;
l[sc]=l[sp];
r[sc]=r[sp];
v[sc]=v[sp]+1;
if(ss==se) return;
int mid=ss+se>>1;
if(qi<=mid) Set(l[sp],l[sc],ss,mid,qi);
else Set(r[sp],r[sc],mid+1,se,qi);
}
int Get(int sp, int sc, int ss, int se, int k)
{
if(v[sc]-v[sp]<=k) return -1;
if(ss==se) return ss;
int mid=ss+se>>1;
int sol=Get(l[sp],l[sc],ss,mid,k);
if(sol>=0) return sol;
else return Get(r[sp],r[sc],mid+1,se,k);
}
int main()
{
int n,q,i,a,le,re,k;
scanf("%i %i",&n,&q);
for(i=1;i<=n;i++)
{
scanf("%i",&a);
Set(root[i-1],root[i],1,n,a);
}
while(q--)
{
scanf("%i %i %i",&le,&re,&k);
printf("%i\n",Get(root[le-1],root[re],1,n,(re-le+1)/k));
}
return 0;
}
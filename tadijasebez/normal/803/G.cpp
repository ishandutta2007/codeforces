#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int L=18;
int rmq[N][L],a[N],n,k;
void BuildSparseTable()
{
for(int i=1;i<=n;i++) rmq[i][0]=a[i];
for(int j=1;j<L;j++)
for(int i=1;i<=n-(1<<j)+1;i++)
rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
}
int RMQ(int l, int r)
{
int k=__builtin_clz(1)-__builtin_clz(r-l+1);
return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
int GetRMQ(int l, int r)
{
int sz=r-l+1;
if(sz>=n) return RMQ(1,n);
l=(l-1)%n+1;
r=l+sz-1;
if(r<=n) return RMQ(l,r);
return min(RMQ(l,n),RMQ(1,r-n));
}
const int M=30*N*4;
const int inf=1e9+7;
int ls[M],rs[M],root,tsz,mn[M],lzy[M];
void Push(int c)
{
if(!lzy[c]) return;
if(!ls[c]) ls[c]=++tsz;
if(!rs[c]) rs[c]=++tsz;
mn[ls[c]]=mn[rs[c]]=lzy[c];
lzy[ls[c]]=lzy[rs[c]]=lzy[c];
lzy[c]=0;
}
void Set(int &c, int ss, int se, int qs, int qe, int f)
{
if(!c) c=++tsz,mn[c]=GetRMQ(ss,se);
if(qs>qe || qs>se || ss>qe) return;
if(qs<=ss && qe>=se){ lzy[c]=mn[c]=f;return;}
int mid=ss+se>>1;
Push(c);
Set(ls[c],ss,mid,qs,qe,f);
Set(rs[c],mid+1,se,qs,qe,f);
mn[c]=min(mn[ls[c]],mn[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
if(qs>qe || qs>se || ss>qe) return inf;
if(!c) c=++tsz,mn[c]=GetRMQ(ss,se);
if(qs<=ss && qe>=se) return mn[c];
int mid=ss+se>>1;
Push(c);
return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main()
{
scanf("%i %i",&n,&k);
for(int i=1;i<=n;i++) scanf("%i",&a[i]);
BuildSparseTable();
int q,t,l,r,f;
scanf("%i",&q);
while(q--)
{
scanf("%i %i %i",&t,&l,&r);
if(t==1) scanf("%i",&f),Set(root,1,inf,l,r,f);
else printf("%i\n",Get(root,1,inf,l,r));
}
return 0;
}
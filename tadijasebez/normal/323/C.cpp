#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=N*22;
int tsz,root[N],ls[M],rs[M],sum[M];
void Set(int p,int &c,int ss,int se,int qi){
c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+1;
if(ss==se)return;
int mid=ss+se>>1;
if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int c,int ss,int se,int qs,int qe){
if(qs>qe || qs>se || ss>qe)return 0;
if(qs<=ss && qe>=se)return sum[c];
int mid=ss+se>>1;
return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int x[N],y[N],p[N],q[N];
int main(){
int n,qu;
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&p[i]),x[p[i]]=i;
for(int i=1;i<=n;i++)scanf("%i",&q[i]),y[q[i]]=i;
for(int i=1;i<=n;i++)Set(root[i-1],root[i],1,n,y[p[i]]);
int ans=0;
auto f=[&](int x){return (x-1+ans)%n+1;};
scanf("%i",&qu);
while(qu--){
int a,b,c,d;
scanf("%i %i %i %i",&a,&b,&c,&d);
a=f(a);
b=f(b);
c=f(c);
d=f(d);
if(a>b)swap(a,b);
if(c>d)swap(c,d);
ans=Get(root[b],1,n,c,d)-Get(root[a-1],1,n,c,d);
printf("%i\n",ans);
ans++;
}
return 0;
}
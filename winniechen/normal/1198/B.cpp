#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n,a[N],b[N],Q;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int mx[N<<2],tag[N<<2];
void PushUp(int rt){mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);}
void upd(int rt,int v){mx[rt]=max(mx[rt],v);tag[rt]=max(tag[rt],v);}
void PushDown(int rt){if(tag[rt]!=-1)upd(rt<<1,tag[rt]),upd(rt<<1|1,tag[rt]),tag[rt]=-1;}
void Update(int p,int v,int l,int r,int rt)
{
	if(l==r)return mx[rt] = v,void();PushDown(rt);int m=(l+r)>>1;
	if(p<=m)Update(p,v,lson);else Update(p,v,rson);PushUp(rt);
}
void print(int l,int r,int rt)
{
	if(l==r)return printf("%d ",mx[rt]),void();PushDown(rt);int m=(l+r)>>1;
	print(lson),print(rson);
}
int main()
{
	scanf("%d",&n);memset(tag,-1,sizeof(tag));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),Update(i,a[i],1,n,1);
	scanf("%d",&Q);
	for(int op,x,y;Q--;op==1?(scanf("%d",&y),Update(x,y,1,n,1)):upd(1,x))scanf("%d%d",&op,&x);
	print(1,n,1);
}
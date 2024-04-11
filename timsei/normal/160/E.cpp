using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#define N 600001
#define r(x) scanf("%d",&x)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D(i,a,b) for(int i=a;i>=b;i--)
#define pk(x) printf("%d ",x)
#define pln(x) printf("%d\n",x)
#define p(x) printf("%d",x)
#define lc no<<1
#define rc no<<1|1
#define getmid int mid=(L[no]+R[no])>>1
#define pushup val[no]=max(val[lc],val[rc])
int n,m,sz[N],tot,L[N],R[N],root,id[N],val[N];
map<int,int>M;
struct dance{int id,l,r,t;}xx[N];
bool cmp(dance x,dance y){return (x.l<y.l||(x.l==y.l&&x.id<y.id));}
void build(int no,int l,int r)
{
	L[no]=l;R[no]=r;
	if(l==r) return;getmid;
	build(lc,l,mid);build(rc,mid+1,r);
}
void add(int no,int num,int c,int pos)
{
	if(L[no]==R[no]){val[no]=c;id[no]=num;return;}getmid;
	if(pos>mid) add(rc,num,c,pos);else add(lc,num,c,pos); 
	pushup;
}
int query(int no,int num,int l,int r)
{
	if(val[no]<num) return -1;
	if(L[no]==R[no]) return id[no];getmid;
	if(l>mid) return query(rc,num,l,r);
	if(r<=mid) return query(lc,num,l,r);
	int lq=query(lc,num,l,mid);
	if(lq!=-1) return lq;
	return query(rc,num,mid+1,r); 
}
int ans[N];
int main()
{
	r(n);r(m);for(int i=1;i<=n;i++){r(xx[i].l);r(xx[i].r);r(xx[i].t);xx[i].id=i;}for(int i=1;i<=m;i++){r(xx[i+n].l);r(xx[i+n].r);r(xx[i+n].t);xx[i+n].id=i+n;}
	sort(xx+1,xx+n+m+1,cmp);
	for(int i=1;i<=n+m;i++){if(!M.count(xx[i].t)){sz[++tot]=xx[i].t,M[xx[i].t]=tot;}}
	sort(sz+1,sz+tot+1);for(int i=1;i<=tot;i++){M[sz[i]]=i;}
	build(1,1,tot);
	for(int i=1;i<=n+m;i++)
	{
		int pos=M[xx[i].t];
		if(xx[i].id<=n){add(1,xx[i].id,xx[i].r,pos);}
		else
		{
			ans[xx[i].id-n]=query(1,xx[i].r,pos,tot);
		}
	}
	F(i,1,m) pk(ans[i]);
}
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int qans[300005];
struct query
{
	int l,r,id;
}q[300005];
int f[300005],n;
void insert(int k,int x)
{
	while(k>=1)
	{
		f[k]=min(f[k],x);
		k-=((k)&(-k));
	}
}
int query(int k)
{
	int ans=1000000000;
	while(k<=n)
	{
		ans=min(ans,f[k]);
		k+=((k)&(-k));
	}
	return ans;
}
int a[300005];
int rt;
int ch[10000005][2],maxn[10000005],cnt;
void modify(int& k,int l,int r,int x,int y)
{
	if(k==0)
	{
		k=++cnt;
		ch[k][0]=ch[k][1]=0;
		maxn[k]=0;
	}
	maxn[k]=max(maxn[k],y);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)modify(ch[k][0],l,mid,x,y);
	else modify(ch[k][1],mid+1,r,x,y);
}
int findmax(int k,int ql,int qr,int l,int r)
{
	if(k==0)return 0;
	if(qr<l||ql>r)return 0;
	if(l>=ql&&r<=qr)return maxn[k];
	int mid=(l+r)>>1;
	return max(findmax(ch[k][0],ql,qr,l,mid),findmax(ch[k][1],ql,qr,mid+1,r));
}
bool bi(struct query x,struct query y)
{
	return x.r<y.r;
}
int main()
{
	int m;
	n=read();
	for(int i=1;i<=n;i++)f[i]=1000000000;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	m=read(); 
	for(int i=1;i<=m;i++)
	{
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
	}for(int i=1;i<=m;i++)qans[i]=1000000000;
	sort(q+1,q+m+1,bi);
	int x;
	for(int i=1;i<=m;i++)
	{
		for(int j=q[i-1].r+1;j<=q[i].r;j++)
		{
			x=findmax(rt,a[j],1000000000,0,1000000000);
			while(x>=1)
			{
				//printf("%d %d\n",x,j);
				insert(x,a[x]-a[j]);
				if(a[j]==a[x])break;
				x=findmax(rt,a[j],(a[j]+a[x])/2,0,1000000000);
			}
			//if(j==4)printf("%d\n",findmax(rt,1,1,0,1000000000));
			modify(rt,0,1000000000,a[j],j);
		}
		qans[q[i].id]=min(qans[q[i].id],query(q[i].l));
	}
	//for(int i=1;i<=m;i++)printf("%d\n",qans[i]);
	for(int i=1;i<=n;i++)a[i]=1000000000-a[i];
	for(int i=1;i<=n;i++)f[i]=1000000000;
	cnt=0;
	rt=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=q[i-1].r+1;j<=q[i].r;j++)
		{
			x=findmax(rt,a[j],1000000000,0,1000000000);
			while(x>=1)
			{
				//printf("%d %d\n",x,j);
				insert(x,a[x]-a[j]);
				if(a[j]==a[x])break;
				x=findmax(rt,a[j],(a[j]+a[x])/2,0,1000000000);
			}
			modify(rt,0,1000000000,a[j],j);
		}
		qans[q[i].id]=min(qans[q[i].id],query(q[i].l));
	}
	for(int i=1;i<=m;i++)printf("%d\n",qans[i]);
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Node
{
	int pos;
	int type;
	int l,r;
}a[1000005];
int t,T,n,m,num,pa[1000005],l[1000005],r[1000005],ans[1000005];
priority_queue<int>ql,dell;
priority_queue<int,vector<int>,greater<int> >qr,delr;
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
bool cmp(Node a,Node b)
{
	return a.pos<b.pos;
}
int main()
{
	scanf("%d%d",&t,&T);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		l[i+n]=0,r[i+n]=1000000000;
		pa[i]=i,pa[i+n]=i+n;
	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
		int u=find(x),v=find(y+n);
		if(u!=v)
		{
			l[u]=max(l[u],l[v]);
			r[u]=min(r[u],r[v]);
			pa[v]=u;
		}
		u=find(x+n),v=find(y);
		if(u!=v)
		{
			l[u]=max(l[u],l[v]);
			r[u]=min(r[u],r[v]);
			pa[v]=u;
		}
	}
	m=0;
	for(int i=1;i<=n;i++)
	{
		int x=find(i),y=find(i+n);
		if(x==i)
		{
			num++;
			int l1=l[x],r1=r[x];
			int l2=l[y],r2=r[y];
			if(l1>l2)
			{
				swap(l1,l2);
				swap(r1,r2);
			}
			if(r1<l2)
			{
				a[++m].l=l2,a[m].r=r2,a[m].pos=l1,a[m].type=1;
				a[++m].l=l2,a[m].r=r2,a[m].pos=r1+1,a[m].type=0;
				a[++m].l=l1,a[m].r=r1,a[m].pos=l2,a[m].type=1;
				a[++m].l=l1,a[m].r=r1,a[m].pos=r2+1,a[m].type=0;
			}
			else
			{
				if(r1<r2)
				{
					a[++m].l=l2,a[m].r=r2,a[m].pos=l1,a[m].type=1;
					a[++m].l=l2,a[m].r=r2,a[m].pos=l2,a[m].type=0;
					a[++m].l=l1,a[m].r=r2,a[m].pos=l2,a[m].type=1;
					a[++m].l=l1,a[m].r=r2,a[m].pos=r1+1,a[m].type=0;
					a[++m].l=l1,a[m].r=r1,a[m].pos=r1+1,a[m].type=1;
					a[++m].l=l1,a[m].r=r1,a[m].pos=r2+1,a[m].type=0;
				}
				else
				{
					a[++m].l=l2,a[m].r=r2,a[m].pos=l1,a[m].type=1;
					a[++m].l=l2,a[m].r=r2,a[m].pos=l2,a[m].type=0;
					a[++m].l=l1,a[m].r=r1,a[m].pos=l2,a[m].type=1;
					a[++m].l=l1,a[m].r=r1,a[m].pos=r2+1,a[m].type=0;
					a[++m].l=l2,a[m].r=r2,a[m].pos=r2+1,a[m].type=1;
					a[++m].l=l2,a[m].r=r2,a[m].pos=r1+1,a[m].type=0;
				}
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	a[m+1].pos=1000000001;
	int now=1,size=0;
	while(now<=m)
	{
		while(!ql.empty()&&!dell.empty()&&ql.top()==dell.top())
		{
			ql.pop();
			dell.pop();
		}
		while(!qr.empty()&&!delr.empty()&&qr.top()==delr.top())
		{
			qr.pop();
			delr.pop();
		}
		if(size==num)
		{
			int l2=ql.top(),r2=qr.top();
			int l1=a[now-1].pos;
			int r1=a[now].pos-1;
			if(l2<=r2&&l1<=r1)
			{
				int minn=l1+l2;
				int maxx=r1+r2;
				minn=max(minn,t);
				maxx=min(maxx,T);
				if(minn<=maxx)
				{
					printf("POSSIBLE\n");
					int v1=l1,v2=minn-v1;
					if(v2>r2)
					{
						v2=r2;
						v1=minn-v2;
					}
					printf("%d %d\n",v1,v2);
					for(int i=1;i<=n;i++)
					{
						int x=find(i),y=find(i+n);
						if(x==i)
						{
							if(l[x]<=v1&&r[x]>=v1&&l[y]<=v2&&r[y]>=v2)ans[x]=1,ans[y]=2;
							else ans[x]=2,ans[y]=1;
						}
					}
					for(int i=1;i<=n;i++)printf("%d",ans[find(i)]);
					printf("\n");
					return 0;
				}
			}
		}
		do
		{
			if(a[now].type==0)
			{
				dell.push(a[now].l);
				delr.push(a[now].r);
				size--;
			}
			else
			{
				ql.push(a[now].l);
				qr.push(a[now].r);
				size++;
			}
			now++;
		}
		while(now<=m&&a[now].pos==a[now-1].pos);
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
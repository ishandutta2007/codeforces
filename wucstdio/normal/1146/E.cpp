#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Segment_Tree
{
	struct Node
	{
		bool val;
		bool flag;
		bool rev;
	}tree[400005];
	void pushdown(int o)
	{
		if(tree[o].flag)
		{
			tree[lson].flag=tree[rson].flag=1;
			tree[lson].val=tree[rson].val=tree[o].val;
			tree[lson].rev=tree[rson].rev=0;
			tree[o].flag=0;
		}
		if(tree[o].rev)
		{
			tree[lson].rev^=tree[o].rev;
			tree[rson].rev^=tree[o].rev;
			tree[o].rev=0;
		}
	}
	void set(int o,int l,int r,int from,int to,bool v)
	{
		if(l>=from&&r<=to)
		{
			tree[o].flag=1;
			tree[o].val=v;
			tree[o].rev=0;
			return;
		}
		pushdown(o);
		if(from<=mid)set(lson,l,mid,from,to,v);
		if(to>mid)set(rson,mid+1,r,from,to,v);
	}
	void rev(int o,int l,int r,int from,int to)
	{
		if(l>=from&&r<=to)
		{
			tree[o].rev^=1;
			return;
		}
		pushdown(o);
		if(from<=mid)rev(lson,l,mid,from,to);
		if(to>mid)rev(rson,mid+1,r,from,to);
	}
	int query(int o,int l,int r,int p)
	{
		if(l==r)return tree[o].val^tree[o].rev;
		pushdown(o);
		if(p<=mid)return query(lson,l,mid,p);
		else return query(rson,mid+1,r,p);
	}
}T;
int n,q,a[100005],maxx;
bool rev;
inline bool read()
{
	char c=(char)getchar();
	while(c!='>'&&c!='<')c=(char)getchar();
	return c=='>';
}
void debug()
{
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i])>maxx)printf("%d ",T.query(1,0,100000,abs(a[i]))?abs(a[i]):-abs(a[i]));
		else printf("%d ",rev?-a[i]:a[i]);
	}
	printf("\n");
}
void work(int type,int x)
{
	if(type==1)
	{
		if(maxx>x)maxx=x;
		T.set(1,0,100000,x+1,100000,0);
	}
	else
	{
		if(maxx>-x)maxx=-x;
		T.set(1,0,100000,-x+1,100000,1);
	}
}
void Rev()
{
	rev^=1;
	T.rev(1,0,100000,maxx+1,100000);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	maxx=100000;
	while(q--)
	{
		int type=read(),x;
		scanf("%d",&x);
		if(type==1)
		{
			if(x<0)
			{
				work(0,x+1);
				Rev();
			}
			else work(1,x);
		}
		else
		{
			if(x>0)
			{
				work(1,x-1);
				Rev();
			}
			else work(0,x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i])>maxx)printf("%d ",T.query(1,0,100000,abs(a[i]))?abs(a[i]):-abs(a[i]));
		else printf("%d ",rev?-a[i]:a[i]);
	}
	printf("\n");
	return 0;
}
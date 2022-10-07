#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int add;
	int minv;
	int maxv;
}tree[4000005];
int n,m;
char s[1000005],res[1000005];
void pushup(int o)
{
	tree[o].maxv=max(tree[lson].maxv,tree[rson].maxv);
	tree[o].minv=min(tree[lson].minv,tree[rson].minv);
}
void pushdown(int o)
{
	if(tree[o].add)
	{
		tree[lson].add+=tree[o].add;
		tree[rson].add+=tree[o].add;
		tree[lson].maxv+=tree[o].add;
		tree[rson].maxv+=tree[o].add;
		tree[lson].minv+=tree[o].add;
		tree[rson].minv+=tree[o].add;
		tree[o].add=0;
	}
}
void add(int o,int l,int r,int from,int to,int v)
{
	if(l>=from&&r<=to)
	{
		tree[o].add+=v;
		tree[o].maxv+=v;
		tree[o].minv+=v;
		return;
	}
	pushdown(o);
	if(from<=mid)add(lson,l,mid,from,to,v);
	if(to>mid)add(rson,mid+1,r,from,to,v);
	pushup(o);
}
int ask(int o,int l,int r,int p)
{
	if(l==r)return tree[o].maxv;
	pushdown(o);
	if(p<=mid)return ask(lson,l,mid,p);
	else return ask(rson,mid+1,r,p);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='L')now--;
		else if(s[i]=='R')now++;
		else if(s[i]=='(')
		{
			if(res[now]==')')add(1,1,n,now,n,2);
			else if(res[now]!='(')add(1,1,n,now,n,1);
			res[now]='(';
		}
		else if(s[i]==')')
		{
			if(res[now]=='(')add(1,1,n,now,n,-2);
			else if(res[now]!=')')add(1,1,n,now,n,-1);
			res[now]=')';
		}
		else
		{
			if(res[now]=='(')add(1,1,n,now,n,-1);
			else if(res[now]==')')add(1,1,n,now,n,1);
			res[now]=s[i];
		}
		now=max(now,1);
		if(tree[1].minv>=0&&ask(1,1,n,n)==0)printf("%d ",tree[1].maxv);
		else printf("-1 ");
	}
	printf("\n");
	return 0;
}
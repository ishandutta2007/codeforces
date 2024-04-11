#include<cstdio>
#include<algorithm>
#include<cstring>
#define lc x<<1
#define rc x<<1|1
#define mid (l+r)/2
using namespace std;
struct Tree
{
	int sum;
	bool tag;
}tree[800005];
int T,n,m,pos[200005],cnt[26],u[200005],v[200005],num;
char s[200005],t[200005];
int st[200005],top;
void pushup(int x)
{
	tree[x].sum=tree[lc].sum+tree[rc].sum;
}
void pushdown(int x,int l,int r)
{
	if(tree[x].tag)
	{
		tree[lc].tag=tree[rc].tag=1;
		tree[lc].sum=mid-l+1;
		tree[rc].sum=r-mid;
		tree[x].tag=0;
	}
}
void build(int x,int l,int r)
{
	tree[x].sum=tree[x].tag=0;
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void update(int x,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)
	{
		tree[x].tag=1;
		tree[x].sum=r-l+1;
		return;
	}
	pushdown(x,l,r);
	if(from<=mid)update(lc,l,mid,from,to);
	if(to>mid)update(rc,mid+1,r,from,to);
	pushup(x);
}
int query(int x,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[x].sum;
	pushdown(x,l,r);
	int ans=0;
	if(from<=mid)ans+=query(lc,l,mid,from,to);
	if(to>mid)ans+=query(rc,mid+1,r,from,to);
	return ans;
}
bool check()
{
	int sum=0,maxx=0;
	for(int i=0;i<26;i++)
	{
		sum+=cnt[i];
		maxx=max(maxx,cnt[i]);
	}
	return maxx*2<=sum;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		m=0;
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[i-1])
			{
				t[++m]=s[i];
				cnt[s[i]-'a']++;
				pos[m]=i;
			}
		}
		t[++m]='\0';
		m--;
		int res=0;
		for(int c=0;c<26;c++)
		  if(cnt[c]>cnt[res])res=c;
		num=0;
		if(cnt[res]*2<=m)
		{
			if(m&1)cnt[t[m]-'a']--,m--;
			top=0;
			for(int i=1;i<=m;i++)
			{
				if(!top||t[i]==t[st[top]])st[++top]=i;
				else
				{
					cnt[t[i]-'a']--;
					cnt[t[st[top]]-'a']--;
					if(check())
					{
						num++;
						u[num]=pos[st[top]],v[num]=pos[i]-1;
						top--;
					}
					else cnt[t[i]-'a']++,cnt[t[st[top]]-'a']++,st[++top]=i;
				}
			}
		}
		else
		{
			top=0;
			for(int i=1;i<=m;i++)
			{
				if(t[i]=='a'+res)
				{
					if(t[st[top]]=='a'+res||!top)st[++top]=i;
					else
					{
						num++;
						u[num]=pos[st[top]],v[num]=pos[i]-1;
						top--;
					}
				}
				else
				{
					if(t[st[top]]=='a'+res&&top)
					{
						num++;
						u[num]=pos[st[top]],v[num]=pos[i]-1;
						top--;
					}
					else st[++top]=i;
				}
			}
		}
		build(1,1,n);
		for(int i=1;i<=num;i++)
		{
			int x=u[i]-query(1,1,n,1,u[i]);
			int y=v[i]-query(1,1,n,1,v[i]);
			update(1,1,n,u[i],v[i]);
			u[i]=x,v[i]=y;
		}
		m=0;
		for(int i=1;i<=n;i++)
		{
			if(query(1,1,n,i,i))continue;
			t[++m]=s[i];
		}
		int last=1;
		for(int i=2;i<=m;i++)
		{
			if(t[i]==t[i-1])
			{
				u[++num]=1;
				v[num]=i-last;
				last=i;
			}
		}
		u[++num]=1;
		v[num]=m+1-last;
		printf("%d\n",num);
		for(int i=1;i<=num;i++)printf("%d %d\n",u[i],v[i]);
	}
	return 0;
}
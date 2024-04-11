#include<iostream>
#include<cstdio>
#include<cstring>
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
int ch[20000005][2],tmp;
void update(int& k,int l,int r,int x)
{
	if(k==0)k=++tmp;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)update(ch[k][0],l,mid,x);
	else update(ch[k][1],mid+1,r,x);
}
int merge(int x,int y,int l,int r)
{
	if(x==0||y==0)return x+y;
	int k=++tmp;
	if(l==r)return k;
	int mid=(l+r)>>1;
	ch[k][0]=merge(ch[x][0],ch[y][0],l,mid);
	ch[k][1]=merge(ch[x][1],ch[y][1],mid+1,r);
	return k;
}
int query(int k,int l,int r,int ql,int qr)
{
	if(k==0||l>qr||r<ql)return 0;
	if(l>=ql&&r<=qr)return 1;
	int mid=(l+r)>>1;
	return (query(ch[k][0],l,mid,ql,qr)||query(ch[k][1],mid+1,r,ql,qr));
}
int rt[2000005];
struct sam
{
	int fa,len,lp;
	int ch[26];
}d[2000005];
int cnt=1,las=1,n;
void add(int c)
{
	int sth=las,p=++cnt;
	las=cnt;
	d[p].len=d[sth].len+1;
	d[p].lp=d[p].len;
	update(rt[p],1,n,d[p].len);
	for(;sth!=0&&d[sth].ch[c]==0;sth=d[sth].fa)d[sth].ch[c]=p;
	if(sth==0)
	{
		d[p].fa=1;
		return;
	}
	int q=d[sth].ch[c];
	if(d[q].len==d[sth].len+1)
	{
		d[p].fa=q;
		return;
	}
	int nq=++cnt;
	d[nq]=d[q];
	d[nq].len=d[sth].len+1;
	d[q].fa=d[p].fa=nq;
	for(;sth!=0&&d[sth].ch[c]==q;sth=d[sth].fa)d[sth].ch[c]=nq;
}
char str[2000005];
int pos[2000005];
bool bi(int x,int y)
{
	return d[x].len<d[y].len;
}
int dp[2000005],la[2000005];
signed main()
{
	n=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
    	add(str[i]-'a');
	}
	for(int i=1;i<=cnt;i++)
	{
		pos[i]=i;
	}
	sort(pos+1,pos+cnt+1,bi);
	for(int i=cnt;i>=2;i--)
	{
		int sth=pos[i];
		rt[d[sth].fa]=merge(rt[d[sth].fa],rt[sth],1,n);
	}
	/*for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%lld",query(rt[i],1,n,j,j));
		}
		printf("\n");
	}*/
	int ans=0;
	for(int i=2;i<=cnt;i++)
	{
		int sth=pos[i];
		if(d[sth].fa==1)
		{
			dp[sth]=1;
			la[sth]=sth;
			ans=max(ans,1);
			continue;
		}
		int gre=la[d[sth].fa];
		if(query(rt[gre],1,n,d[sth].lp-d[sth].len+d[gre].len,d[sth].lp-1))
		{
			dp[sth]=dp[d[sth].fa]+1;
			la[sth]=sth;
		}
		else
		{
			dp[sth]=dp[d[sth].fa];
			la[sth]=la[d[sth].fa];
		}
		//printf("%lld %lld %lld\n",i,sth,dp[sth]);
		ans=max(ans,dp[sth]);
	}
	printf("%d\n",ans); 
    return 0;
}
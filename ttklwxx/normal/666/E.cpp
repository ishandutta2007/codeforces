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
int ch[20000005][2],siz[20000005],mpos[20000005],tmp;
void update(int& k,int l,int r,int x)
{
	if(k==0)k=++tmp;
	if(l==r)
	{
		siz[k]++;
		mpos[k]=l;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)update(ch[k][0],l,mid,x);
	else update(ch[k][1],mid+1,r,x);
	if(siz[ch[k][0]]>=siz[ch[k][1]])
	{
		siz[k]=siz[ch[k][0]];
		mpos[k]=mpos[ch[k][0]];
	}
	else
	{
		siz[k]=siz[ch[k][1]];
		mpos[k]=mpos[ch[k][1]];
	}
}
int merge(int x,int y,int l,int r)
{
	if(x==0||y==0)return x+y;
	int k=++tmp;
	if(l==r)
	{
		siz[k]=siz[x]+siz[y];
		mpos[k]=l;
		return k;
	}
	int mid=(l+r)>>1;
	ch[k][0]=merge(ch[x][0],ch[y][0],l,mid);
	ch[k][1]=merge(ch[x][1],ch[y][1],mid+1,r);
	if(siz[ch[k][0]]>=siz[ch[k][1]])
	{
		siz[k]=siz[ch[k][0]];
		mpos[k]=mpos[ch[k][0]];
	}
	else
	{
		siz[k]=siz[ch[k][1]];
		mpos[k]=mpos[ch[k][1]];
	}
	return k;
}
pair<int,int> query(int k,int l,int r,int ql,int qr)
{
	if(k==0||l>qr||r<ql)return make_pair(0,0);
	if(l>=ql&&r<=qr)return make_pair(siz[k],mpos[k]);
	int mid=(l+r)>>1;
	pair<int,int>lans=query(ch[k][0],l,mid,ql,qr),rans=query(ch[k][1],mid+1,r,ql,qr);
	if(lans.first>=rans.first)return lans;
	else return rans;
}
struct sam
{
	int fa,len;
	int ch[26];
}d[2000005];
int cnt=1;
int n;
int add(int c,int las)
{
	if(d[las].ch[c]!=0)
	{
		int p=las,x=d[las].ch[c];
		if(d[x].len==d[p].len+1)return x;
		int q=++cnt;
		d[q]=d[x];
		d[q].len=d[p].len+1;
    	for(;p!=0&&d[p].ch[c]==x;p=d[p].fa)d[p].ch[c]=q;
        d[q].fa=d[x].fa;
        d[x].fa=q;
        return q;
	}
	int sth=las,p=++cnt;
	las=cnt;
	d[p].len=d[sth].len+1;
	for(;sth!=0&&d[sth].ch[c]==0;sth=d[sth].fa)d[sth].ch[c]=p;
	if(sth==0)
	{
		d[p].fa=1;
		return p;
	}
	int q=d[sth].ch[c];
	if(d[q].len==d[sth].len+1)
	{
		d[p].fa=q;
		return p;
	}
	int nq=++cnt;
	d[nq]=d[q];
	d[nq].len=d[sth].len+1;
	d[q].fa=d[p].fa=nq;
	for(;sth!=0&&d[sth].ch[c]==q;sth=d[sth].fa)d[sth].ch[c]=nq;
	return p;
}
char s[500005];
int en[2000005];
int pos[2000005];
bool bi(int x,int y)
{
	return d[x].len<d[y].len;
}
int fa[2000005][21];
int rt[2000005];
int main()
{
	int len,nl;
	scanf("%s",s+1);
	len=strlen(s+1);
	en[0]=1;
	for(int j=1;j<=len;j++)
	{
		en[j]=add(s[j]-'a',en[j-1]);
	}
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		nl=1;
		for(int j=1;j<=len;j++)
		{
			nl=add(s[j]-'a',nl);
			update(rt[nl],1,n,i);
		}
	}
	for(int i=1;i<=cnt;i++)pos[i]=i;
	sort(pos+1,pos+cnt+1,bi);
	for(int i=1;i<=cnt;i++)
	{
		fa[pos[i]][0]=d[pos[i]].fa;
		for(int j=1;j<=20;j++)
		{
			fa[pos[i]][j]=fa[fa[pos[i]][j-1]][j-1];
		}
	}
	for(int i=cnt;i>=1;i--)
	{
		rt[d[pos[i]].fa]=merge(rt[d[pos[i]].fa],rt[pos[i]],1,n);
	}
	int q;
	q=read();
	int pl,pr,l,r,now;
	for(int i=1;i<=q;i++)
	{
		l=read();
		r=read();
		pl=read();
		pr=read();
		now=en[pr];
		for(int i=20;i>=0;i--)
		{
			if(fa[now][i]!=0&&d[fa[now][i]].len>=pr-pl+1)now=fa[now][i];
		}
		pair<int,int> gre=query(rt[now],1,n,l,r);
		//printf("???%d %d\n",gre.first,gre.second);
		if(gre.first==0)printf("%d 0\n",l);
		else printf("%d %d\n",gre.second,gre.first);
	}
	return 0;
}
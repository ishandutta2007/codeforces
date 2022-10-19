#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct z
{
	int x,y;
	z(){}
	z(int _x,int _y):x(_x),y(_y){}
	inline bool operator<(const z k)const
	{
		return x==k.x?y>k.y:x<k.x;
	}
};
int n,m,q,len,rt[N],lc[N*160],rc[N*160],c,ch[N][26],f[N],l[N],las,sz=1,pi[N*10],di[N*10],fa[N][18];
z tr[N*160];
char s[N*10],t[N];
vector<int>e[N];
void ins(int &k,int l,int r,int x)
{
	if(!k) k=++c;
	if(l==r)
	{
		tr[k].x++;
		tr[k].y=l;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) ins(lc[k],l,mid,x);
	else ins(rc[k],mid+1,r,x);
	tr[k]=max(tr[lc[k]],tr[rc[k]]);
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y) return x|y;
	int k=++c;
	if(l==r)
	{
		tr[k]=tr[x];
		tr[k].x+=tr[y].x;
		return k;
	}
	int mid=l+r>>1;
	lc[k]=merge(lc[x],lc[y],l,mid);
	rc[k]=merge(rc[x],rc[y],mid+1,r);
	tr[k]=max(tr[lc[k]],tr[rc[k]]);
	return k;
}
z query(int k,int l,int r,int a,int b)
{
	if(!k) return z(0,0);
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(lc[k],l,mid,a,b);
	else if(a>mid) return query(rc[k],mid+1,r,a,b);
	else return max(query(lc[k],l,mid,a,mid),query(rc[k],mid+1,r,mid+1,b));
}
void add(int x,int id)
{
	int c=++sz,p=las;
	l[c]=l[p]+1;
	ins(rt[c],1,m,id);
	while(p&&!ch[p][x])
	{
		ch[p][x]=c;
		p=f[p];
	}
	if(!p)
		f[c]=1;
	else
	{
		int q=ch[p][x];
		if(l[p]+1==l[q])
			f[c]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			f[nq]=f[q],l[nq]=l[p]+1;
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[c]=f[q]=nq;
		}
	}
	las=c;
}
void dfs(int u)
{
	for(auto v:e[u])
	{
		dfs(v);
		fa[v][0]=u;
		rt[u]=merge(rt[u],rt[v],1,m);
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		las=1;
		scanf("%s",t+1);
		len=strlen(t+1);
		for(int j=1;j<=len;j++)
			add(t[j]-'a',i);
	}
	for(int i=2;i<=sz;i++)
		e[f[i]].push_back(i);
	int p=1,d=0;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'a';
		while(p!=1&&!ch[p][x])
			p=f[p],d=l[p];
		if(ch[p][x])
		{
			p=ch[p][x];
			d++;
		}
		else
			p=1,d=0;
		pi[i]=p,di[i]=d;
	}
	dfs(1);
	for(int j=1;j<=17;j++)
		for(int i=1;i<=sz;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&q);
	while(q--)
	{
		int tl,tr,pl,pr;
		scanf("%d%d%d%d",&tl,&tr,&pl,&pr);
		if(pr-pl+1>di[pr])
		{
			printf("%d %d\n",tl,0);
			continue;
		}
		int p=pi[pr];
		for(int i=17;i>=0;i--)
			if(fa[p][i]&&l[fa[p][i]]>=pr-pl+1)
				p=fa[p][i];
		z ans=query(rt[p],1,m,tl,tr);
		if(ans.x==0)
			ans.y=tl;
		printf("%d %d\n",ans.y,ans.x);
	}
	return 0;
}
//
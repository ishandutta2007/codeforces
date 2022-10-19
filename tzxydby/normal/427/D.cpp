#include<bits/stdc++.h>
using namespace std;
const int N=20005;
int n,m,ch[N][26],f[N],l[N],sz=1,las,a[N],z[N],tr[N][26],fa[N],fb[N],w,sa[N],sb[N],ans=-1,d[N];
char s[N],t[N];
queue<int>q;
void add(int x,int id)
{
	int c=++sz,p=las;
	l[c]=l[p]+1,d[id]=c,sa[c]=fa[id],sb[c]=fb[id];
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
			l[nq]=l[p]+1,f[nq]=f[q];
			while(p&&ch[p][x]==q)
			{
				ch[p][x]=nq;
				p=f[p];
			}
			f[c]=f[q]=nq;
		}
	}
}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int u;
	u=0;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'a';
		if(!tr[u][x])
			tr[u][x]=++w;
		u=tr[u][x];
		fa[u]=1;
	}
	u=0;
	for(int i=1;i<=m;i++)
	{
		int x=t[i]-'a';
		if(!tr[u][x])
			tr[u][x]=++w;
		u=tr[u][x];
		fb[u]=1;
	}
	d[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			int v=tr[u][i];
			if(!v)
				continue;
			las=d[u];
			add(i,v);
			q.push(v);
		}
	}
	for(int i=1;i<=sz;i++)
		z[l[i]]++;
	for(int i=1;i<=sz;i++)
		z[i]+=z[i-1];
	for(int i=1;i<=sz;i++)
		a[z[l[i]]--]=i;
	for(int i=sz;i>=1;i--)
		sa[f[a[i]]]+=sa[a[i]],sb[f[a[i]]]+=sb[a[i]];
	for(int i=2;i<=sz;i++)
		if(sa[i]==1&&sb[i]==1)
			if(ans==-1||l[f[i]]+1<ans)
				ans=l[f[i]]+1;
	printf("%d\n",ans);
	return 0;
}
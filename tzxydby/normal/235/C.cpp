#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int ch[N][26],f[N],l[N],las=1,sz=1,a[N],t[N],dp[N],vis[N];
void add(int x)
{
	int c=++sz,p=las;
	dp[c]=1,l[c]=l[p]+1;
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
			f[q]=f[c]=nq;
		}
	}
	las=c;
}
char s[N],r[N];
int n,m,q,ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		add(s[i]-'a');
	for(int i=1;i<=sz;i++)
		t[l[i]]++,vis[i]=-1;
	for(int i=1;i<=sz;i++)
		t[i]+=t[i-1];
	for(int i=1;i<=sz;i++)
		a[t[l[i]]--]=i;
	for(int i=sz;i>=1;i--)
		dp[f[a[i]]]+=dp[a[i]];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",r+1);
		m=strlen(r+1),ans=0;
		int u=1,g=0;
		for(int i=1;i<=m;i++)
		{
			int x=r[i]-'a';
			while(u!=1&&!ch[u][x])
				u=f[u],g=l[u];
			if(!ch[u][x])
				continue;
			u=ch[u][x];
			g++;
		}
		if(g==m)
		{
			ans+=dp[u];
			vis[u]=q;
		}
		for(int i=1;i<m;i++)
		{
			int x=r[i]-'a';
			if(g==m)
			{		
				if(g==l[f[u]]+1)
					u=f[u],g=l[u];
				else
					g--;
			}
			while(u!=1&&!ch[u][x])
				u=f[u],g=l[u];
			if(!ch[u][x])
				continue;
			u=ch[u][x];
			g++;
			if(g==m&&vis[u]!=q)
			{
				ans+=dp[u];
				vis[u]=q;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
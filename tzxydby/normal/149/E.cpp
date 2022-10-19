#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct sam
{
	int ch[N][26],f[N],l[N],las,sz,a[N],t[N],mn[N],cnt;
	void init()
	{
		las=sz=1;
	}
	int newnode()
	{
		sz++;
		mn[sz]=1e9;
		return sz;
	}
	void add(int x)
	{
		cnt++;
		int c=newnode(),p=las;
		l[c]=l[p]+1,mn[c]=cnt;
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
				int nq=newnode();
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
		las=c;	
	}
	void sol()
	{
		for(int i=1;i<=sz;i++)
			t[l[i]]++;
		for(int i=1;i<=sz;i++)
			t[i]+=t[i-1];
		for(int i=1;i<=sz;i++)
			a[t[l[i]]--]=i;
		for(int i=sz;i>=1;i--)
			mn[f[a[i]]]=min(mn[f[a[i]]],mn[a[i]]);
	}
}s1,s2;
char s[N],t[N];
int n,m,q,mp[N],ms[N],ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	s1.init(),s2.init();
	for(int i=1;i<=n;i++)
		s1.add(s[i]-'A');
	for(int i=n;i>=1;i--)
		s2.add(s[i]-'A');
	s1.sol(),s2.sol();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",t+1);
		m=strlen(t+1);
		int u;
		u=1;
		for(int i=1;i<=m;i++)
		{
			int x=t[i]-'A';
			u=s1.ch[u][x];
			if(u)
				mp[i]=s1.mn[u];
			else
				mp[i]=0;
		}
		u=1;
		for(int i=m;i>=1;i--)
		{
			int x=t[i]-'A';
			u=s2.ch[u][x];
			if(u)
				ms[i]=n-s2.mn[u]+1;
			else
				ms[i]=0;
		}
		int fl=0;
		for(int i=1;i<m;i++)
			if(mp[i]&&ms[i+1]&&mp[i]<ms[i+1])
				fl=1;
		ans+=fl;
	}
	printf("%d\n",ans);
	return 0;
}
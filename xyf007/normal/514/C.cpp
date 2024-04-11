#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
int trie[300001][3],n,m,tot=0;
bool f[300001];
char s[600001];
inline void insert(char s[600001])
{
	int root=0;
	for(register int i=0,sz=strlen(s);i<sz;i++)
	{
		int id=s[i]-'a';
		if(!trie[root][id])
		{
			trie[root][id]=++tot;
		}
		root=trie[root][id];
	}
	f[root]=1;
}
inline bool dfs(int u,int now,int root)
{
	int id=s[now]-'a';
	if(s[now])
	{
		if(trie[root][id])
		{
			if(dfs(u,now+1,trie[root][id]))
			{
				return 1;
			}
		}
		if(!u)
		{
			for(int i=0;i<3;i++)
			{
				if(i==id||!trie[root][i])
				{
					continue;
				}
				if(dfs(u+1,now+1,trie[root][i]))
				{
					return 1;
				}
			}
		}
	}
	else
	{
		return u&&f[root];
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",s);
		insert(s);
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if(dfs(0,0,0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
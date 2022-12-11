#include<bits/stdc++.h>
using namespace std;
namespace Trie
{
	const int max_tot=6e6+5;
	int son[max_tot][2],tot;
	inline void insert(int x)
	{
		int cur=0;
		for(int i=29;i>=0;--i)
		{
			int v=(x>>i)&1;
			if(!son[cur][v])
				son[cur][v]=++tot;
			cur=son[cur][v];
		}
	}
	int f[max_tot];
	inline int solve()
	{
		for(int i=tot;i>=0;--i)
		{
			if(son[i][0])
			{
				if(son[i][1])
					f[i]=max(f[son[i][0]],f[son[i][1]])+1;
				else
					f[i]=f[son[i][0]];
			}
			else
			{
				if(son[i][1])
					f[i]=f[son[i][1]];
				else
					f[i]=1;
			}
		}
		return f[0];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		Trie::insert(a);
	}
	printf("%d\n",n-Trie::solve());
    return 0;
}
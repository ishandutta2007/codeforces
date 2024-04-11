#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int b[max_n][max_n],deg[max_n],que[max_n];
bitset<max_n> ans[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				scanf("%1d",&b[i][j]);
				deg[j]+=b[i][j];
			}
		for(int i=1;i<=n;++i)
			ans[i][i]=true;
		int sz=0;
		for(int i=1;i<=n;++i)
		{
			if(!deg[i])
				que[++sz]=i;
		}
		for(int t=1;t<=sz;++t)
		{
			int x=que[t];
			for(int y=1;y<=n;++y)
			{
				if(!b[x][y])
					continue;
				ans[y]|=ans[x];
				if(!--deg[y])
					que[++sz]=y;
			}
		}
		assert(sz==n);
		for(int i=1;i<=n;++i)
		{
			vector<int> Ans;
			for(int j=1;j<=n;++j)
			{
				if(ans[i][j])
					Ans.push_back(j);
			}
			int s=Ans.size();
			printf("%d ",s);
			for(int j=0;j<s;++j)
				printf("%d%c",Ans[j]," \n"[j+1==s]);
		}
		for(int i=1;i<=n;++i)
			deg[i]=0;
		for(int i=1;i<=n;++i)
			ans[i].reset();
	}
	return 0;
}
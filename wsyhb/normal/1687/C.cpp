//
#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
long long s[max_n];
vector<int> I[max_n];
bool mark[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%lld",s+i);
		for(int i=1;i<=n;++i)
		{
			int b;
			scanf("%d",&b);
			s[i]+=s[i-1]-b;
		}
		for(int i=0;i<=n;++i)
		{
			I[i].clear();
			mark[i]=false;
		}
		for(int i=1;i<=m;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			I[l-1].push_back(r);
			I[r].push_back(l-1);
		}
		set<int> S;
		queue<int> que;
		for(int i=0;i<=n;++i)
		{
			if(!s[i])
			{
				mark[i]=true;
				que.push(i);
			}
			else
				S.insert(i);
		}
		while(!que.empty())
		{
			int x=que.front();
			que.pop();
			for(int i=0;i<int(I[x].size());++i)
			{
				int y=I[x][i];
				if(mark[y])
				{
					int L=x,R=y;
					if(L>R)
						swap(L,R);
					set<int>::iterator it=S.upper_bound(L);
					while(it!=S.end()&&*it<R)
					{
						mark[*it]=true;
						que.push(*it);
						it=S.erase(it);
					}
				}
			}
		}
		puts(S.empty()?"YES":"NO");
	}
	return 0;
}
/*
1
5 1
5 2 4 3 10
2 1 6 3 12
1 2
---
NO
*/
#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int ca[max_n],cb[max_n],nxt[max_n];
bool vis[max_n];
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",ca+i);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",cb+i);
			nxt[ca[i]]=cb[i];
			vis[i]=false;
		}
		vector<int> S;
		for(int i=1;i<=n;++i)
		{
			if(vis[i])
				continue;
			vis[i]=true;
			int now=nxt[i],sz=1;
			while(!vis[now])
			{
				vis[now]=true;
				++sz;
				now=nxt[now];
			}
			S.push_back(sz);
		}
		sort(S.begin(),S.end());
		int L=1,R=n;
		long long ans=0;
		for(int i=0;i<int(S.size());++i)
		{
			int sz=S[i];
			vector<int> num;
			for(int j=1;j<=sz;++j)
			{
				if(j&1)
					num.push_back(L++);
				else
					num.push_back(R--);
			}
			num.push_back(num[0]);
			for(int j=0;j<sz;++j)
				ans+=num[j]>=num[j+1]?num[j]-num[j+1]:num[j+1]-num[j];
			if(sz&1)
				--L;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
10
3 1  7 8 4 10 2 6 9 5
2 10 6 7 5 1  9 8 4 3
---
48
*/
/*
1
8
7 2 4 3 6 8 5 1
8 6 2 1 3 7 5 4
---
30
*/
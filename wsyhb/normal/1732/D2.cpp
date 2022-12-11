#include<bits/stdc++.h>
using namespace std;
int q,R;
const int max_q=2e5+5;
char op[max_q];
long long k[max_q],Hash[max_q],ans[max_q];
vector<int> Query[max_q],Time[max_q];
inline int id(long long x)
{
	int res=lower_bound(Hash+1,Hash+R+1,x)-Hash;
	return res<=R&&Hash[res]==x?res:-1;
}
int main()
{
	scanf("%d",&q);
	for(int t=1;t<=q;++t)
	{
		char s[5];
		scanf("%s%lld",s,k+t);
		op[t]=s[0];
		Hash[t]=k[t];
	}
	sort(Hash+1,Hash+q+1);
	R=unique(Hash+1,Hash+q+1)-Hash-1;
	for(int i=1;i<=R;++i)
		Time[i].push_back(1);
	for(int t=1;t<=q;++t)
	{
		int v=lower_bound(Hash+1,Hash+R+1,k[t])-Hash;
		if(op[t]=='?')
			Query[v].push_back(t);
		else if(op[t]=='+')
			Time[v].push_back(t-1);
		else
			Time[v].push_back(t);
	}
	for(int i=1;i<=R;++i)
	{
		if(Time[i].size()&1)
			Time[i].push_back(q);
	}
	for(int i=1;i<=R;++i)
	{
		if(Query[i].empty())
			continue;
		long long k=Hash[i];
		set<int> S;
		for(int t:Query[i])
			S.insert(t);
		long long now=k;
		while(!S.empty())
		{
			int x=id(now);
			if(x==-1)
				break;
			int sz=Time[x].size();
			for(int i=0;i<sz&&!S.empty();i+=2)
			{
				int l=Time[x][i];
				int r=Time[x][i+1];
				set<int>::iterator it=S.lower_bound(l);
				if(it==S.end())
					break;
				while(it!=S.end()&&*it<=r)
				{
					ans[*it]=now;
					it=S.erase(it);
				}
			}
			now+=k;
		}
		for(long long x:S)
			ans[x]=now;
	}
	for(int i=1;i<=q;++i)
	{
		if(op[i]=='?')
			printf("%lld\n",ans[i]);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,ans[N],q[N],l=-1,r;
set<int>s;
set<pair<int,int>>t;
map<int,vector<int>>e;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		t.insert({a,b});
		e[a].push_back(b);
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(!t.count({a,b}))
		{
			e[a].push_back(-i);
			q[i]=b;
		}
	}
	t.insert({0,0});
	for(auto &v:e)
	{
		for(int i=l+1;i<v.first;)
		{
			while(s.count(r))
				r++;
			auto it=s.upper_bound(r);
			int k=min(v.first-i,it==s.end()?INT_MAX:(*it)-r);
			r+=k;
			i+=k;
		}
		while(s.count(r))
			r++;
		int k=INT_MAX;
		for(auto i:v.second)
			if(i>=0)
				k=min(k,i);
		if(r<k)
			s.insert(r);
		for(auto i:v.second)
		{
			if(i>=0)
				s.insert(i);
			else
				ans[-i]=(q[-i]!=min(k,r));
		}
		l=v.first;
	}
	for(int i=1;i<=m;i++)
		puts(ans[i]?"WIN":"LOSE");
	return 0;
}
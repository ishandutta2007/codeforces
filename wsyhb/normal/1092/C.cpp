#include<bits/stdc++.h>
using namespace std;
int n,cnt;
const int max_n=100+5;
const int max_cnt=200+5;
struct Node
{
	string s;
	int id;
}cur;
vector<Node> a[max_n];
char ans[max_cnt];
inline void solve()
{
	string now="";
	for(int i=1;i<=n-2;++i)
	{
		now+=a[n-1][0].s[i-1];
		if(now!=a[i][0].s)
		{
			if(now!=a[i][1].s)
				return;
			swap(a[i][0],a[i][1]);
		}
	}
	now="";
	for(int i=1;i<=n-2;++i)
	{
		now=a[n-1][1].s[n-i-1]+now;
		if(now!=a[i][1].s)
			return;
	}
	if(a[n-1][0].s.substr(1,n-2)!=a[n-1][1].s.substr(0,n-2))
		return;
	for(int i=1;i<=n-1;++i)
	{
		ans[a[i][0].id]='P';
		ans[a[i][1].id]='S';
	}
	printf("%s\n",ans+1);
	exit(0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cnt=2*n-2;
	for(int i=1;i<=cnt;++i)
	{
		cin>>cur.s;
		cur.id=i;
		a[cur.s.size()].push_back(cur);
	}
	for(int i=1;i<=n-1;++i)
		assert(int(a[i].size())==2);
	solve();
	swap(a[n-1][0],a[n-1][1]);
	solve();
	puts("No solution!");
	assert(false);
	return 0;
}
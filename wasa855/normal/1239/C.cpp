#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
struct Node
{
	int tim,id;
	bool operator < (const Node &x) const
	{
		if(tim!=x.tim) return tim>x.tim;
		return id>x.id;
	}
};
priority_queue<Node> a;
queue<int> q;
set<int> s;
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int u=read();
		a.push((Node){u,i});
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(q.empty()&&s.empty()) cur=a.top().tim;
		cur+=m;
		while(!a.empty()&&a.top().tim<=cur)
		{
			if(q.empty()||a.top().id<q.back()) q.push(a.top().id);
			else s.insert(a.top().id);
			a.pop();
		}
		ans[q.front()]=cur;
		q.pop();
		if(q.empty()&&!s.empty())
		{
			q.push(*s.begin());
			s.erase(s.begin());
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
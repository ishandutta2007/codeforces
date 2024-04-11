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
#define N 200005
vector<int> v[N];
priority_queue<int,vector<int>,greater<int> >q;
void work()
{
	int n=read();
	for(int i=0;i<=n;i++) v[i].clear();
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		v[x].pb(y);
	}
	int ans=0;
	for(int i=n;i>=0;i--)
	{
		int ss=v[i].size();
		for(int j=0;j<ss;j++) q.push(v[i][j]);
		while(q.size()>n-i)
		{
			ans+=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
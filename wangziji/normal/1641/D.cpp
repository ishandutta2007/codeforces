#include <bits/stdc++.h>
using namespace std;
const int B=500;
bitset <100005> s[500000/B+5],t;
int id[500005];
int a[100005][7],cnt[500005],A[100005][7];
pair <int,int> w[100005],b[500005];
vector <int> v[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			b[i*m+j-m]={a[i][j],i*m+j-m};
		}
		cin >> w[i].first;
		w[i].second=i;
	}
	sort(b+1,b+n*m+1);
	int Nw=0;
	for(int i=1;i<=n*m;i++)
	{
		if(b[i].first!=b[i-1].first) ++Nw;
		a[(b[i].second-1)/m+1][(b[i].second-1)%m+1]=Nw;
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			A[i][j]=a[w[i].second][j];
	}
	swap(a,A);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			++cnt[a[i][j]];
	}
	int nowid=0;
	for(int i=1;i<=n*m;i++)
	{
		if(cnt[i]>B)
			id[i]=++nowid;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(id[a[i][j]])
				s[id[a[i][j]]][i]=1;
			else v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) t[i]=1;
	for(int i=1;i<=nowid;i++) s[i].flip();
	int ans=2.1e9;
	for(int i=1;i<=n;i++)
	{
		t.set();
		for(int j=1;j<=m;j++)
		{
			if(id[a[i][j]]) t&=s[id[a[i][j]]];
			else for(auto x:v[a[i][j]]) t[x]=0;
		}
		int p=t._Find_next(i);
		if(p<=n) ans=min(ans,w[i].first+w[p].first);
	}
	if(ans>2000000000) ans=-1;
	cout << ans;
	return 0;
}
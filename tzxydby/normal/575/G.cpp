#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+9;
vector<pair<int,int> > e[MAX];
int mark[MAX],pre[MAX],n,m;
char ch[MAX];
vector<int> av;
queue<int> qq;
queue<vector<int> > q;	
vector<int> ans(1,0);
int main() 
{
	cin>>n>>m;
	for (int i=0,a,b,c;i<m;i++)	cin>>a>>b>>c,e[a].push_back(make_pair(c, b)),e[b].push_back(make_pair(c, a));
	mark[n-1]=1;
	qq.push(n-1);
	while (qq.size()) 
	{
		int v=qq.front();
		qq.pop();
		av.push_back(v);
		for (int i=0;i<e[v].size();i++) 
		{
			int co=e[v][i].first,to=e[v][i].second;
			if (!co && !mark[to]) qq.push(to),mark[to]=1,pre[to]=v,ch[to]='0';
		}
	}
	q.push(av);
	while (q.size()) 
	{
		vector<int> v=q.front();
		q.pop();
		vector<pair<int,int> > w[10];
		for (int i=0;i<v.size();i++) 
		{
			int a=v[i];
			for (int j=0;j<e[a].size();j++) 
			{
				int co=e[a][j].first,to=e[a][j].second;
				if (!mark[to]) w[co].push_back({to, a});
			}
		}
		for (int i=0;i<10;i++)
		{
			vector<int> t;
			for (int j=0;j<w[i].size();j++) 
			{
				int to=w[i][j].first,p=w[i][j].second;
				if (!mark[to]) t.push_back(to),mark[to]=1,pre[to]=p,ch[to]='0'+i;
			}
			if (t.size()) q.push(t);
		}
	}
	pre[n-1]=n-1;
	int g=0,z=1;
	while (g!=n-1) g=pre[g],ans.push_back(g);
	for (int i=ans.size()-2;i>=0;i--) if (ch[ans[i]]!='0') cout<<ch[ans[i]],z=0; else if (!z) cout<<'0';
	if (z) cout<<0;
	cout<<'\n'<<ans.size()<<'\n';
	for (auto i:ans) cout<<i<<" ";
	return 0;
}
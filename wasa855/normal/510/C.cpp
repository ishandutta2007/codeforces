#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int to;
	int nxt;
};
Edge edge[105];
int fir[130];
int dfn[130];
string a[105];
int ss;
int dgr[130];
int ans[130];
void add(int u,int v)
{
//	printf("%c %c\n",u,v);
	ss++;
	edge[ss].to=v;
	edge[ss].nxt=fir[u];
	fir[u]=ss;
	dgr[v]++;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int x=min(a[i].length(),a[i+1].length());
		bool ok=false;
		for(int j=0;j<x;j++)
		{
			if(a[i][j]!=a[i+1][j])
			{
				add(a[i][j],a[i+1][j]);
				ok=true;
				break;
			}
		}
		if(ok==false)
		{
			if(a[i].length()>a[i+1].length())
			{
				cout<<"Impossible\n";
				return 0;
			}
		}
	}
	queue<int> q;
	for(int i='a';i<='z';i++)
	{
		if(dgr[i]==0)
		{
			q.push(i);
		}
	}
//	cout<<"ZHI\n";
	int cnt=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cnt++;
		ans[cnt]=x;
		for(int i=fir[x];i!=0;i=edge[i].nxt)
		{
			int to=edge[i].to;
			dgr[to]--;
			if(dgr[to]==0)
			{
				q.push(to);
			}
		}
	}
	if(cnt!=26)
	{
		cout<<"Impossible\n";
		return 0;
	}
	for(int i=1;i<=26;i++)
	{
		printf("%c",ans[i]);
	}
	return 0;
}
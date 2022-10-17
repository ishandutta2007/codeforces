#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
int m,x,y;
vector<ii>e[10020];
int c[10020];
void dfs(int x, int y)
{
	if(~c[x])
		return;
	c[x]=y;
	for(ii i:e[x])
		dfs(i.X,y);
}
void quit()
{
	puts("-1");
	exit(0);
}
bool v[10020];
int ct[10020];
vector<int>p;
void dfs(int u)
{
	while(ct[u]<e[u].size())
	{
		int X=e[u][ct[u]].X;
		int Y=e[u][ct[u]++].Y;
		if(!v[Y])
		{
			v[Y]=true;
			dfs(X);
			p.push_back(Y);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		e[x].push_back(ii(y,i));
		e[y].push_back(ii(x,i));
	}
	memset(c,-1,sizeof c);
	vector<int>cs;
	for(int i=0;i<10010;i++)
		if(c[i]==-1&&e[i].size())
			dfs(i,i),cs.push_back(i);
	if(cs.size()>2)
		quit();
	vector<int>os;
	for(int i=0;i<10010; ++i)
		if(e[i].size()&1)
			os.push_back(i);
	if(os.size()>4)
		quit();
	vector<int>z1,z2;
	if(cs.size()==2)
	{
		vector<int>o1,o2;
		for(int i:os)
			if(c[i]==cs[0])
				o1.push_back(i);
			else
				o2.push_back(i);
		if(o1.size()>2||o2.size()>2)
			quit();
		o1.push_back(cs[0]);
		o2.push_back(cs[1]);
		dfs(o1[0]),z1=p;
		p.clear();
		dfs(o2[0]),z2=p;
		p.clear();
	}
	else
	{
		if(os.size()<=2)
		{
			os.push_back(cs[0]);
			dfs(os[0]);
			z1=p;
			if(z1.size()<2)
				quit();
			z2.push_back(z1.back());
			z1.pop_back();
		}
		else
		{
			int x=os[2],y=os[3];
			e[x].push_back(ii(y,10010));
			e[y].push_back(ii(x,10010));
			dfs(os[0]);
			int t=0;
			for(int i:p)
				if(i==10010)
					t=1;
				else if(t)
					z1.push_back(i);
				else
					z2.push_back(i);
		}
	}
	cout<<z1.size()<<endl;
	for(int i:z1)
		cout<<i+1<<" ";
	cout<<endl;
	cout<<z2.size()<<endl;
	for(int i:z2)
		cout<<i+1<<" ";
	cout<<endl;
	return 0;
}
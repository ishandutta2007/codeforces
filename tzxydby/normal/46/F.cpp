#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int parent[N],rnk[N];
struct UnionFind
{
	UnionFind(int n)
	{
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			rnk[i]=1;
		}
	}
	int root(int x)
	{
		if(parent[x]!=x)
			parent[x]=root(parent[x]);
		return parent[x];
	}
	void connect(int x,int y)
	{
		int rx=root(x),ry=root(y);
		if(rx==ry)
			return;
		if(rx>ry)
		{
			parent[ry]=rx;
			rnk[rx]+=rnk[ry];	
		} 
		if(rx<=ry)
		{
			parent[rx]=ry;
			rnk[ry]+=rnk[rx];
		}
	}
};
map<string,int>mp;
int n,m,k;
int key[2][N],people[2][N];
bool connected[2][N][N];
int s[N],t[N];
char buf[100];
void func(int id)
{
	UnionFind uf(n);
	for(int iter=0;iter<n+10;iter++)
	{
		for(int i=0;i<m;i++)
		{
			int room=uf.root(key[id][i]);
			if(uf.root(s[i])==room||uf.root(t[i])==room)
				uf.connect(s[i],t[i]);
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			connected[id][i][j]=(uf.root(i)==uf.root(j));
}
bool can()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(connected[0][i][j]!=connected[1][i][j])
				return false;
	for(int i=0;i<m;i++)
		if(!connected[0][key[0][i]][key[1][i]])
			return false;
	for(int i=0;i<k;i++)
		if(!connected[0][people[0][i]][people[1][i]])
			return false;
	return true;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&s[i],&t[i]);
		s[i]--;
		t[i]--;
	}
	for(int i=0;i<k;i++)
	{
		scanf("%s",buf);
		string str=buf;
		mp[str]=i;
		int room;
		scanf("%d",&room);
		room--;
		people[0][i]=room;
		int c;
		scanf("%d",&c);
		for(int j=0;j<c;j++)
		{
			int e;
			scanf("%d",&e);
			e--;
			key[0][e]=room;
		}
	} 
	for(int i=0;i<k;i++)
	{
		scanf("%s",buf);
		string str=buf;
		int p=mp[buf];
		int room;
		scanf("%d",&room);
		room--;
		people[1][p]=room;
		int c;
		scanf("%d",&c);
		for(int j=0;j<c;j++)
		{
			int e;
			scanf("%d",&e);
			e--;
			key[1][e]=room;
		}
	}
	func(0);
	func(1);
	bool ans=can();
	cout<<(ans?"YES":"NO")<<endl;
	return 0;
}
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <bitset>
using namespace std;
#define N 200005
int a[N],ans[N],n,vis[N],p[N];vector<int >v[N];
void add(int x,int y){v[x].push_back(y);}
bool cmp(const int &x,const int &y){return a[x]<a[y];}
void bfs()
{
	queue<int >q;q.push(1);vis[1]=1;
	while(!q.empty())
	{

		int x=q.front();q.pop();ans[++ans[0]]=x;sort(v[x].begin(),v[x].end(),cmp);
		for(int i=0;i<v[x].size();i++)if(!vis[v[x][i]])q.push(v[x][i]),vis[v[x][i]]=1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d %d",&x,&y),add(x,y),add(y,x);
	for(int i=1,x;i<=n;i++)scanf("%d",&p[i]),a[p[i]]=i;bfs();
	for(int i=1;i<=n;i++)if(p[i]!=ans[i]){puts("No");return 0;}
	puts("Yes");
}
/*
5
1 2
1 3
2 4
3 5
1 3 5 2 5
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define N 100005
map<int ,int >mp[N];
set<int >s[N];
set<int >::iterator it;
int fa[N],n,m,Q;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void uni(int x,int y)
{
	x=find(x),y=find(y);if(x==y)return ;
	if(s[x].size()<s[y].size())swap(x,y);
	fa[y]=x;for(it=s[y].begin();it!=s[y].end();it++)s[x].insert(*it);
}
void add(int x,int y,int z)
{
	s[find(x)].insert(y),s[find(y)].insert(x);
	if(mp[y].find(z)!=mp[y].end())uni(mp[y][z],x);else mp[y][z]=x;
	if(mp[x].find(z)!=mp[x].end())uni(mp[x][z],y);else mp[x][z]=y;
}
void query(int x,int y)
{
	if(find(x)==find(y))return puts("Yes"),void();
	if(s[find(x)].find(y)!=s[find(x)].end())return puts("Yes"),void();
	puts("No");
}
char op[10];
int main()
{
	scanf("%d%d%*d%d",&n,&m,&Q);for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),add(x,y,z);
	for(int x,y,z;Q--;op[0]=='+'?scanf("%d",&z),add(x,y,z):query(x,y))scanf("%s%d%d",op,&x,&y);
}
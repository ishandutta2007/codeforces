#include <stdio.h>
#include <map>
using namespace std;
#define mp make_pair
bool vis[5000][5000];
int sol;
pair<int,int> l(pair<int,int> cur)
{
	if(cur==mp(-1,0)) return mp(-1,-1);
	if(cur==mp(-1,-1)) return mp(0,-1);
	if(cur==mp(-1,1)) return mp(0,1);
	if(cur==mp(0,-1)) return mp(1,-1);
	if(cur==mp(0,1)) return mp(-1,1);
	if(cur==mp(1,0)) return mp(1,1);
	if(cur==mp(1,-1)) return mp(1,0);
	if(cur==mp(1,1)) return mp(0,1);
}
pair<int,int> r(pair<int,int> cur)
{
	if(cur==mp(-1,0)) return mp(-1,1);
	if(cur==mp(-1,-1)) return mp(-1,0);
	if(cur==mp(-1,1)) return mp(-1,0);
	if(cur==mp(0,-1)) return mp(-1,-1);
	if(cur==mp(0,1)) return mp(1,1);
	if(cur==mp(1,0)) return mp(1,-1);
	if(cur==mp(1,-1)) return mp(0,-1);
	if(cur==mp(1,1)) return mp(1,0);
}
int t[50],n;
bool was[500][500][50][3][3];
void DFS(int x, int y, int depth, pair<int,int> cur)
{
	if(was[x][y][depth][cur.first+1][cur.second+1]) return;
	was[x][y][depth][cur.first+1][cur.second+1]=1;
	int i;
	for(i=0;i<t[depth];i++)
	{
		x+=cur.first;
		y+=cur.second;
		if(!vis[x][y]) sol++;
		vis[x][y]=1;
	}
	if(depth==n) return;
	DFS(x,y,depth+1,l(cur));
	DFS(x,y,depth+1,r(cur));
}
int main()
{
	int i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&t[i]);
	DFS(250,250,1,mp(-1,0));
	printf("%i\n",sol);
	return 0;
}
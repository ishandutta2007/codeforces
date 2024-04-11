#include <bits/stdc++.h>
using namespace std;
const int x=999,y=999,k=666;
bool vis[1005][1005];
int cnt[5];
struct point
{
	int x,y;
}king,rook[k+5];
void move(int dx,int dy)
{
	king.x+=dx,king.y+=dy;
	if(vis[king.x][king.y]) king.x-=dx;
	printf("%d %d\n",king.x,king.y);
	fflush(stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==-1&&b==-1&&c==-1) exit(0);
	vis[rook[a].x][rook[a].y]=false;
	rook[a].x=b,rook[a].y=c;
	vis[rook[a].x][rook[a].y]=true;
}
int main()
{
	scanf("%d%d",&king.x,&king.y);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&rook[i].x,&rook[i].y),vis[rook[i].x][rook[i].y]=true;
	while(king.x>500) move(-1,0);
	while(king.x<500) move(1,0);
	while(king.y>500) move(0,-1);
	while(king.y<500) move(0,1);
	for(int i=1;i<=k;i++)
		cnt[(rook[i].x<500)*2+(rook[i].y<500)]++;
	int mini=0x3f3f3f3f,pnt;
	for(int i=0;i<=3;i++)
		if(mini>cnt[i]) mini=cnt[i],pnt=i;
	while(1) move(pnt/2?1:-1,pnt%2?1:-1);
	return 0;
}
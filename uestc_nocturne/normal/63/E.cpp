#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
bool vis[(1<<19)+10],can[(1<<19)+10];
int dir[20][10];
void Out(int x,bool flag)
{
	int po=x;while(po>0){printf("%d ",po%2);po/=2;}if(flag)puts("win");else puts("lose");
}
bool dfs(int x)
{
	if(vis[x])return can[x];
	vis[x]=true;bool flag=false;
	for(int i=0;i<19;i++)
	{
		int st=(1<<i);
		if((st&x)==0)continue;
		if(!dfs(x-st))flag=true;
		for(int j=0;j<6;j++)
		{
			int now=i;
			st=x-(1<<i);
			while(1)
			{
				now=dir[now][j];
			//	printf("%d %d %d %d   ",x,i,j,now);
				if(now==-1)break;
				if((st&(1<<now))==0)break;
				st=st-(1<<now);
				if(!dfs(st))flag=true;
			//	Out(st,dfs(st));
			}
		}
	}
//	Out(x,flag);
	can[x]=flag;
	return can[x];
}
void init()
{
	dir[0][0]=-1;dir[0][1]=-1;dir[0][2]=1;dir[0][3]=4;dir[0][4]=3;dir[0][5]=-1;
	dir[1][0]=-1;dir[1][1]=-1;dir[1][2]=2;dir[1][3]=5;dir[1][4]=4;dir[1][5]=0;
	dir[2][0]=-1;dir[2][1]=-1;dir[2][2]=-1;dir[2][3]=6;dir[2][4]=5;dir[2][5]=1;
	dir[3][0]=-1;dir[3][1]=0;dir[3][2]=4;dir[3][3]=8;dir[3][4]=7;dir[3][5]=-1;
	dir[4][0]=0;dir[4][1]=1;dir[4][2]=5;dir[4][3]=9;dir[4][4]=8;dir[4][5]=3;
	dir[5][0]=1;dir[5][1]=2;dir[5][2]=6;dir[5][3]=10;dir[5][4]=9;dir[5][5]=4;
	dir[6][0]=2;dir[6][1]=-1;dir[6][2]=-1;dir[6][3]=11;dir[6][4]=10;dir[6][5]=5;
	dir[7][0]=-1;dir[7][1]=3;dir[7][2]=8;dir[7][3]=12;dir[7][4]=-1;dir[7][5]=-1;
	dir[8][0]=3;dir[8][1]=4;dir[8][2]=9;dir[8][3]=13;dir[8][4]=12;dir[8][5]=7;
	dir[9][0]=4;dir[9][1]=5;dir[9][2]=10;dir[9][3]=14;dir[9][4]=13;dir[9][5]=8;
	dir[10][0]=5;dir[10][1]=6;dir[10][2]=11;dir[10][3]=15;dir[10][4]=14;dir[10][5]=9;
	dir[11][0]=6;dir[11][1]=-1;dir[11][2]=-1;dir[11][3]=-1;dir[11][4]=15;dir[11][5]=10;
	dir[12][0]=7;dir[12][1]=8;dir[12][2]=13;dir[12][3]=16;dir[12][4]=-1;dir[12][5]=-1;
	dir[13][0]=8;dir[13][1]=9;dir[13][2]=14;dir[13][3]=17;dir[13][4]=16;dir[13][5]=12;
	dir[14][0]=9;dir[14][1]=10;dir[14][2]=15;dir[14][3]=18;dir[14][4]=17;dir[14][5]=13;
	dir[15][0]=10;dir[15][1]=11;dir[15][2]=-1;dir[15][3]=-1;dir[15][4]=18;dir[15][5]=14;
	dir[16][0]=12;dir[16][1]=13;dir[16][2]=17;dir[16][3]=-1;dir[16][4]=-1;dir[16][5]=-1;
	dir[17][0]=13;dir[17][1]=14;dir[17][2]=18;dir[17][3]=-1;dir[17][4]=-1;dir[17][5]=16;
	dir[18][0]=14;dir[18][1]=15;dir[18][2]=-1;dir[18][3]=-1;dir[18][4]=-1;dir[18][5]=17;
}
char ch[120];
int main()
{
	int st=0;init();
	memset(vis,false,sizeof(vis));
	can[0]=false;vis[0]=true;
	for(int i=0;i<19;i++)
	{
		scanf("%s",ch);
		if(ch[0]=='O')st+=(1<<i);
	}
	if(dfs(st))puts("Karlsson");
	else puts("Lillebror");
}
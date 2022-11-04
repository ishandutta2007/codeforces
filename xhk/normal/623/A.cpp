#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct edge
{int u,v,next;
};
struct edge e[2000010];

int n,m,num,x,y,flag;
int head[1010],used[1010],ga[510][510];

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=head[u];
 head[u]=num;
 num++;
}

void dfs(int i,int col)
{int j;
 used[i]=col;
 j=head[i];
 while(j!=-1)
 {	if(used[e[j].v]==used[i])
 	{	flag=0;
 		return;
    }
    if(used[e[j].v]==-1) dfs(e[j].v,col^1);
    j=e[j].next;
 }
}

int main()
{int i,j;
 
 scanf("%d%d",&n,&m);
 for(i=1;i<=m;i++)
 {	scanf("%d%d",&x,&y);
 	ga[x][y]=1;
 	ga[y][x]=1;
 }
 memset(head,-1,sizeof(head));
 for(i=1;i<=n;i++)
 	for(j=1;j<=n;j++)
 		if(i!=j && ga[i][j]==0)
 			add(i,j);
 memset(used,-1,sizeof(used));
 flag=1;
 for(i=1;i<=n;i++)
 	if((head[i]!=-1) && used[i]==-1)
	 	dfs(i,0);
 for(i=1;i<=n;i++)
 	for(j=1;j<=n;j++)
 		if(i!=j && ga[i][j]==1)
 		{	if((used[i]==1 && used[j]==0) || (used[i]==0 && used[j]==1))
 				flag=0;
 		}
 if(!flag)
 {	printf("No\n");
 	return 0;
 }
 printf("Yes\n");
 for(i=1;i<=n;i++)
 	if(used[i]==0)
 		printf("a");
 	else if(used[i]==1)
	 	printf("c");
	else
		printf("b");
 printf("\n");
 return 0;
}
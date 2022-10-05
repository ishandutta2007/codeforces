#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
char choose[][2]={{0,0},{'A','G'},{'A','C'},{'A','T'},{'C','T'},{'G','T'},{'C','G'}};
int pos[3][Maxn][7],n,now[3],m,tot[3][Maxn];
string str[Maxn],T[Maxn];
void print(pair <int,int> way)
{
	if(!way.first)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",choose[(way.second+(i&1)*3-1)%6+1][(j&1)!=(pos[0][i][way.second]-1)]);
			printf("\n");
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				T[j]+=choose[(way.second+(i&1)*3-1)%6+1][(j&1)!=(pos[1][i][way.second]-1)];
		for(int i=1;i<=n;i++)
			cout<<T[i]<<endl;
	}
}
int main()
{
//	freopen("sys.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=6;j++)
		{
			now[1]=now[2]=0;
			for(int k=1;k<=m;k++)
			{
				now[1]+=choose[(j+(i&1)*3-1)%6+1][k&1]!=str[i][k-1];
				now[2]+=choose[(j+(i&1)*3-1)%6+1][!(k&1)]!=str[i][k-1];
			}
			pos[0][i][j]=now[1]<now[2]?1:2;
			tot[0][j]+=min(now[1],now[2]);
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=6;j++)
		{
			now[1]=now[2]=0;
			for(int k=1;k<=n;k++)
			{
				now[1]+=choose[(j+(i&1)*3-1)%6+1][k&1]!=str[k][i-1];
				now[2]+=choose[(j+(i&1)*3-1)%6+1][!(k&1)]!=str[k][i-1];
			}
			pos[1][i][j]=now[1]<now[2]?1:2;
			tot[1][j]+=min(now[1],now[2]);
		}
	int ans=0x3f3f3f3f;
	pair <int,int> way;
	for(int i=0;i<=1;i++)
		for(int j=1;j<=6;j++)
			if(tot[i][j]<ans) ans=tot[i][j],way=make_pair(i,j);
	print(way);
//	printf("%d\n",ans);
	return 0;
}
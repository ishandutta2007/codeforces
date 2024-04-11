#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int dis[100100][2];

queue<int> hei,which;

bool field[100100][2];

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<=1;i++)
	{
		char ch[100100];
		scanf("%s",ch);
		for(int j=0;j<N;j++)
		{
			if(ch[j]=='-') field[j][i]=true;
			else field[j][i]=false;
		}
	}
	for(int i=0;i<N;i++)
	{
		dis[i][0]=10*N;
		dis[i][1]=10*N;
	}
	dis[0][0]=0;
	hei.push(0);
	which.push(0);
	const int nxt1[]={K,1,-1};
	const int nxt2[]={1,0,0};
	while(!hei.empty())
	{
		int h=hei.front();
		int f=which.front();
		hei.pop();which.pop();
		int t=dis[h][f];
		for(int i=0;i<3;i++)
		{
			int nh=h+nxt1[i];
			int nf=f^nxt2[i];
			if(nh>=N)
			{
				printf("YES\n");
				return 0;
			}
			if(nh<0) continue;
			if(field[nh][nf]==false) continue;
			if(t+1>nh) continue;
			if(dis[nh][nf]<=t+1) continue;
			dis[nh][nf]=t+1;
			hei.push(nh);
			which.push(nf);
		}
	}
	printf("NO\n");
	return 0;
}
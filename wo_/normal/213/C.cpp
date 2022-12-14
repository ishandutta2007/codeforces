#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[610][310][310];//[i+j][1-j-axis][2-j-axis]

int data[330][330];

//bool visited[700][330][330];

int rec(int s,int j1,int j2)
{
	//if(visited[s][j1][j2]==true) return dp[s][j1][j2];
	if(s<j1||s<j2||j1<0||j2<0) return -(1<<30);
	if(dp[s][j1][j2]!=-(1<<30)) return dp[s][j1][j2];
	int M=max(rec(s-1,j1,j2),max(rec(s-1,j1-1,j2),max(rec(s-1,j1,j2-1),rec(s-1,j1-1,j2-1))));
	int i1=s-j1,i2=s-j2;
	if(j1==j2) M+=data[i1][j1];
	else M+=(data[i1][j1]+data[i2][j2]);
	dp[s][j1][j2]=M;
	return M;
}

int main()
{
	int N;
	scanf("%d",&N);
	//memset(visited,false,sizeof(visited));
	for(int i=0;i<2*N;i++)
	{
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<N;k++) dp[i][j][k]=-(1<<30);
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	dp[0][0][0]=data[0][0];
	printf("%d\n",rec(2*N-2,N-1,N-1));
	return 0;
}
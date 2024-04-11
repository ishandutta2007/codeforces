#include<cstdio>

using namespace std;

int main()
{
	int sum[3][2];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			scanf("%d",&(sum[i][j]));
		}
	}
	int x[4];
	bool flg=true;
	x[0]=sum[0][0]+sum[1][0]-sum[2][1];
	x[1]=sum[0][0]+sum[1][1]-sum[2][0];
	x[2]=sum[0][1]+sum[1][0]-sum[2][0];
	x[3]=sum[0][1]+sum[1][1]-sum[2][1];
	for(int i=0;i<4;i++)
	{
		if(x[i]%2!=0) flg=false;
		x[i]/=2;
	}
	for(int i=0;i<4;i++)
	{
		if(x[i]<1||x[i]>9) flg=false;
		for(int j=0;j<4;j++)
		{
			if(i!=j&&x[i]==x[j]) flg=false;
		}
	}
	if(flg)
	{
		printf("%d %d\n%d %d\n",x[0],x[1],x[2],x[3]);
	}
	else printf("-1\n");
	return 0;
}
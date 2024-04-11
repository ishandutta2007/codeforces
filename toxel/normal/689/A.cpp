#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
int main()
{
	int n,i,j,x;
	char c;
	bool flag[6][5],flag1[6][5],flag2=true;
	memset(flag,false,sizeof(flag));
	memset(flag1,false,sizeof(flag1));
	for (i=1;i<=3;i++)
		for (j=1;j<=3;j++)
			flag[i][j]=true;
	flag[4][2]=true;
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;i++)
	{
		c=getchar();
		x=c-'0';
		if (x)
			flag1[(x-1)/3+1][(x-1)%3+1]=true;
		else
			flag1[4][2]=true;
	}
	for (i=0;i<6;i++)
		for (j=0;j<5;j++)
			if (flag1[i][j])
				if (!flag[i+1][j])
				{
					flag2=false;
					break;
				} 
	if (flag2)
	{
		printf("NO");
		return 0;
	}
	flag2=true;
	for (i=0;i<6;i++)
		for (j=0;j<5;j++)
			if (flag1[i][j])
				if (!flag[i-1][j])
				{
					flag2=false;
					break;
				} 
	if (flag2)
	{
		printf("NO");
		return 0;
	}flag2=true;
	for (i=0;i<6;i++)
		for (j=0;j<5;j++)
			if (flag1[i][j])
				if (!flag[i][j+1])
				{
					flag2=false;
					break;
				} 
	if (flag2)
	{
		printf("NO");
		return 0;
	}
	flag2=true;
	for (i=0;i<6;i++)
		for (j=0;j<5;j++)
			if (flag1[i][j])
				if (!flag[i][j-1])
				{
					flag2=false;
					break;
				} 
	if (flag2)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}
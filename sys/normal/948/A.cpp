#include <bits/stdc++.h>
using namespace std;
char mat[505][505];
int r,c;
int main()
{
	scanf("%d%d",&r,&c);
	getchar();
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			scanf("%c",&mat[i][j]);
		getchar();
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			if(mat[i][j]=='W')
			{
				if(mat[i-1][j]=='S'){printf("No");return 0;}
				else if(i-1>=1&&j>=1&&i-1<=r&&j<=c) mat[i-1][j]=mat[i-1][j]=='.'?'D':mat[i-1][j];
				if(mat[i][j-1]=='S'){printf("No");return 0;}
				else if(i>=1&&j-1>=1&&i<=r&&j-1<=c) mat[i][j-1]=mat[i][j-1]=='.'?'D':mat[i][j-1];
				if(mat[i][j+1]=='S'){printf("No");return 0;}
				else if(i>=1&&j+1>=1&&i<=r&&j+1<=c) mat[i][j+1]=mat[i][j+1]=='.'?'D':mat[i][j+1];
				if(mat[i+1][j]=='S'){printf("No");return 0;}
				else if(i+1>=1&&j>=1&&i+1<=r&&j<=c) mat[i+1][j]=mat[i+1][j]=='.'?'D':mat[i+1][j];
			}
		}
	printf("Yes\n");
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			printf("%c",mat[i][j]);
		printf("\n");
	}
	return 0;
}
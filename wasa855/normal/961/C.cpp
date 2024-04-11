#include<bits/stdc++.h>
using namespace std;
bool std1[205][205];
bool std2[205][205];
bool a[5][105][105];
bool used[5];
bool ans[205][205];
int minn=0x7fffffff;
int m;
void print()
{
	for(int i=1;i<=m*2;i++)
	{
		for(int j=1;j<=m*2;j++)
		{
			printf("%d ",ans[i][j]);
		}
		cout<<"\n";
	}
	cout<<"\n";
}
void judge()
{
//	print();
	int tmp=0;
	for(int i=1;i<=m*2;i++)
	{
		for(int j=1;j<=m*2;j++)
		{
			if(ans[i][j]!=std1[i][j])
			{
				tmp++;
			}
		}
	}
	if(minn>tmp)
	{
		minn=tmp;
	}
	tmp=0;
	for(int i=1;i<=m*2;i++)
	{
		for(int j=1;j<=m*2;j++)
		{
			if(ans[i][j]!=std2[i][j])
			{
				tmp++;
			}
		}
	}
	if(minn>tmp)
	{
		minn=tmp;
	}
}
void find(int x)
{
//	print();
	if(x==5)
	{
		judge();
		return ;
	}
	for(int i=1;i<=4;i++)
	{
		if(used[i]==false)
		{
			used[i]=true;
			if(x==1)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=m;k++)
					{
						ans[j][k]=a[i][j][k];
					}
				}
			}
			if(x==2)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=m+1;k<=m*2;k++)
					{
						ans[j][k]=a[i][j][k-m];
					}
				}
			}
			if(x==3)
			{
				for(int j=m+1;j<=m*2;j++)
				{
					for(int k=1;k<=m;k++)
					{
						ans[j][k]=a[i][j-m][k];
					}
				}
			}
			if(x==4)
			{
				for(int j=m+1;j<=m*2;j++)
				{
					for(int k=m+1;k<=m*2;k++)
					{
						ans[j][k]=a[i][j-m][k-m];
					}
				}
			}
			find(x+1);
			used[i]=false;
		}
	}
}
int main()
{
	cin>>m;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=m;k++)
			{
				scanf("%1d",&a[i][j][k]);
			}
		}
	}
	for(int i=1;i<=2*m;i++)
	{
		for(int j=1;j<=2*m;j++)
		{
			if((i%2+j%2)==1)
			{
				std1[i][j]=1;
				std2[i][j]=0;
			}
			else
			{
				std1[i][j]=0;
				std2[i][j]=1;
			}
		}
	}
	find(1);
	cout<<minn<<endl;
	return 0;
}
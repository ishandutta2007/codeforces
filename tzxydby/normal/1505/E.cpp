#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,m;
char s[N][N];
pair<int,int>a[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			if(a[i+1][j].first-i+a[i+1][j].second-j<a[i][j+1].first-i+a[i][j+1].second-j)
				a[i][j]=a[i+1][j];
			else
				a[i][j]=a[i][j+1];
			if(a[i][j+1].first==0)
				a[i][j]=a[i+1][j];
			if(a[i+1][j].first==0)
				a[i][j]=a[i][j+1];
			if(s[i][j]=='*')
				a[i][j]=make_pair(i,j);
		}
	}
	int x=1,y=1,t=0;
	while(1)
	{
		if(s[x][y]=='*')
			t++;
		if(x==n&&y==m)
			break;
		if(x==n)
			y++;
		else if(y==m)
			x++;
		else
		{
			if(a[x][y+1].first==0)
				x++;
			else if(a[x+1][y].first==0)
				y++;
			else if(a[x+1][y].first-x+a[x+1][y].second-y<a[x][y+1].first-x+a[x][y+1].second-y)
				x++;
			else
				y++;
		}
	}
	printf("%d\n",t);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 45
int a[N][N];
int b[N][N];
int ans[N][N][N][N];
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%1d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==0) b[i][j]=b[i][j-1]+1;
		}
	}
	for(int c=1;c<=n;c++)
	{
		for(int d=1;d<=m;d++)
		{
			for(int e=c;e<=n;e++)
			{
				for(int f=d;f<=m;f++)
				{
					ans[c][d][e][f]=ans[c][d][e-1][f]+ans[c][d][e][f-1]-ans[c][d][e-1][f-1];
                    int tmp=f-d+1;
                    for(int i=e;i>=c;i--)
                    {
                        tmp=min(tmp,b[i][f]);
                        ans[c][d][e][f]+=tmp;
                    }
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",ans[read()][read()][read()][read()]);
	}
	return 0;
}
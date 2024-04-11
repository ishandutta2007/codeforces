#include <stdio.h>
int Matrix[105][105];
char c[105];
int main()
{
	int n,m,i,j;
	scanf("%i%i",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",&c);
		for(j=0;j<m;j++)
		{
			if(c[j]=='R') Matrix[i][j]=1;
			if(c[j]=='G') Matrix[i][j]=2;
			if(c[j]=='B') Matrix[i][j]=3;
		}
	}
	if(n%3==0)
	{
		int col=Matrix[0][0];
		bool ok=true;
		int col1=col;
		for(i=0;i<n/3;i++)
		{
			for(j=0;j<m;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		col=Matrix[n/3][0];
		int col2=col;
		for(i=n/3;i<2*n/3;i++)
		{
			for(j=0;j<m;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		col=Matrix[2*n/3][0];
		int col3=col;
		for(i=2*n/3;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		if(col1==col2 || col2==col3 || col1==col3) ok=false;
		if(ok)
		{
			printf("YES\n");
			return 0;
		}
	}
	if(m%3==0)
	{
		int col=Matrix[0][0];
		bool ok=true;
		int col1=col;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m/3;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		col=Matrix[0][m/3];
		int col2=col;
		for(i=0;i<n;i++)
		{
			for(j=m/3;j<2*m/3;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		col=Matrix[0][2*m/3];
		int col3=col;
		for(i=0;i<n;i++)
		{
			for(j=2*m/3;j<m;j++)
			{
				if(col!=Matrix[i][j]) ok=false;
			}
		}
		if(col1==col2 || col2==col3 || col1==col3) ok=false;
		if(ok)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
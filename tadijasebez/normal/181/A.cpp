#include <stdio.h>
char base[105][105];
int x[4],y[4],c;
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",base[i]+1);
		for(j=1;j<=m;j++)
		{
			if(base[i][j]=='*')
			{
				x[++c]=i;
				y[c]=j;
			}
		}
	}
	if(x[1]==x[2] && y[1]==y[3]) return printf("%i %i\n",x[3],y[2]),0;
	if(y[1]==y[2] && x[1]==x[3]) return printf("%i %i\n",x[2],y[3]),0;
	if(x[2]==x[1] && y[2]==y[3]) return printf("%i %i\n",x[3],y[1]),0;
	if(y[2]==y[1] && x[2]==x[3]) return printf("%i %i\n",x[1],y[3]),0;
	if(x[3]==x[2] && y[3]==y[1]) return printf("%i %i\n",x[1],y[2]),0;
	if(y[3]==y[2] && x[3]==x[1]) return printf("%i %i\n",x[2],y[1]),0;
	return 0;
}
#include <stdio.h>
const int N=105;
int y[N],x[N],cnt1,cnt2;
char s[N][N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=n;j++)
		{
			if(s[i][j]=='.')
			{
				if(!y[j]) y[j]=i,cnt1++;
				if(!x[i]) x[i]=j,cnt2++;
			}
		}
	}
	if(cnt1==n)
	{
		for(i=1;i<=n;i++) printf("%i %i\n",y[i],i);
	}
	else if(cnt2==n)
	{
		for(i=1;i<=n;i++) printf("%i %i\n",i,x[i]);
	}
	else printf("-1\n");
	return 0;
}
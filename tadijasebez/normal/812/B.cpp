#include <stdio.h>
const int N=15;
int fir[N],las[N];
int min(int a, int b){ return a>b?b:a;}
int sol=1e9+7;
int main()
{
	int n,m,add,i,j,mask;char s[120];
	scanf("%i %i",&n,&m);add=n;int tmp=0;
	for(j=0;j<n;j++)
	{
		if(j==0) add--;
		scanf("%s",s);
		fir[j]=las[j]=0;
		for(i=1;i<=m;i++)
		{
			if(s[i]=='1')
			{
				if(!fir[j]) fir[j]=i;
				las[j]=i;
			}
		}
		if(!las[j])
		{
			j--,n--;
		}
	}
	//for(i=0;i<n;i++) printf("%i %i\n",fir[i],las[i]);
	int side=0;
	for(mask=0;mask<(1<<n);mask+=2)
	{
		int ans=0;side=0;
		for(i=n-1;i>=1;i--)
		{
			if((mask>>i)&1)
			{
				ans+=m+1;
				side^=1;
			}
			else
			{
				if(side) ans+=2*(m+1-fir[i]);
				else ans+=2*las[i];
			}
			//printf("%i %i\n",mask,ans);
		}
		if(side) ans+=m+1-fir[0];
		else ans+=las[0];
		//printf("%i %i\n",mask,ans);
		ans+=add;
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}
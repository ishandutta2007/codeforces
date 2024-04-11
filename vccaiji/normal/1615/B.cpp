#include<bits/stdc++.h>
using namespace std;
int a[21][210000];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int j=0;j<=20;j++)
	{
		a[j][0]=1;
		for(int i=1;i<=201000;i++)
		{
			a[j][i]=a[j][i-1];
			if((i&(1<<j))==0) a[j][i]++;
		}
	}
    int t,l,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	scanf("%d%d",&l,&r);
    	int minn=10000000;
    	for(int j=0;j<=20;j++)
    	{
    		int k=0;
    		k=a[j][r]-a[j][l-1];
    		if(minn>k) minn=k;
		}
		printf("%d",minn);
    	if(i<t) printf("\n");
	}
	return 0;
}
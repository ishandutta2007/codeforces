#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,ans=999999999,a[20],sf[20],f=0;
		scanf("%d%d",&n,&k);
		if(n==1000000000)
		{
			if(k==1)
				puts("1111111111");
			else
				puts("1000000000");
			continue;
		}
		a[0]=0;
		while(n)
		{
			f++;
			a[f]=n%10;
			n/=10;
		}
		sf[0]=0,sf[1]=a[1];
		for(int i=2;i<=f;i++)
			sf[i]=max(sf[i-1],a[i]);
		for(int s=1;s<1024;s++)
		{
			if(__builtin_popcount(s)>k)
				continue;
			int mx=0,mn=10,v=0;
			for(int i=0;i<10;i++)
				if(s>>i&1)
					mx=max(mx,i),mn=min(mn,i);
			if(mx<a[f])
				continue;
			int fl=0,ok=1;
			for(int i=f;i>=1;i--)
			{
				if(fl)
				{
					v=v*10+mn;
					continue;
				}
				ok=0;
				for(int j=a[i];j<10;j++)
				{
					if(!(s>>j&1))
						continue;
					if(j==a[i])
					{
						int sy=1;
						for(int k=i-1;k;k--)
						{
							if(mx>a[k])
								break;
							if(mx<a[k])
							{
								sy=0;
								break;
							}
						}
						if(!sy)
							continue;
					}
					v=v*10+j;
					if(j>a[i])
						fl=1;
					ok=1;
					break;
				}
				if(!ok)
					break;
			}
			if(ok)
				ans=min(ans,v);
		}
		printf("%d\n",ans);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int vis[1100000];
int n,m,fl,po,dx,dy,dr,ans,i;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(vis,0,sizeof(vis));
		if(m>n)swap(n,m);ans=0;
		for(i=0;i<n;i++)
		{
			if(!vis[i])
			{
				ans++;vis[i]=1;
				if(i!=n-1)
				{
					po=i;dr=1;fl=1;
					while(1)
					{
						if(dr==1)dx=n-po-1;
						else dx=po;
						dy=m-1;
					//	printf("R: %d %d %d %d %d\n",i,fl,po,dr,dx);
						if(dx==dy)
						{
							if(dr==1)po=po+dy;
							else po=po-dy;
							if(fl==-1)vis[po]=1;
							break;
						}
						if(dx>dy)
						{
							if(dr==1)po=po+dy;
							else po=po-dy;
							dx-=dy;
						}
						else
						{
							if(dr==1)po=n-1-(dy-dx);
							else po=dy-dx;
							dr=-dr;
						}
						fl=-fl;
						if(fl==1&&vis[po])break;
						if(fl==1)vis[po]=1;
					}
				}
				if(i!=0)
				{
					po=i;dr=-1;fl=1;
					while(1)
					{
						if(dr==1)dx=n-po-1;
						else dx=po;
						dy=m-1;
					//	printf("L: %d %d %d %d %d\n",i,fl,po,dr,dx);
						if(dx==dy)
						{
							if(dr==1)po=po+dy;
							else po=po-dy;
							if(fl==-1)vis[po]=1;
							break;
						}
						if(dx>dy)
						{
							if(dr==1)po=po+dy;
							else po=po-dy;
							dx-=dy;
						}
						else
						{
							if(dr==1)po=n-1-(dy-dx);
							else po=dy-dx;
							dr=-dr;
						}
						fl=-fl;
						if(fl==1&&vis[po])break;
						if(fl==1)vis[po]=1;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
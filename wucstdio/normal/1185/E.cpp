#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m;
char s[2005][2005];
int r1[35],c1[35],r2[35],c2[35];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		  scanf("%s",s[i]+1);
		bool flag=0,ans=1;
		int k=0;
		for(int c=25;c>=0;c--)
		{
			if(!ans)break;
			int fx=0,fy=0,to=0,minn=2000,maxx=0;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(!ans)break;
				if(s[i][j]==c+'a')
				{
					if(!fx)fx=i,fy=j;
					else if(i!=fx&&j!=fy)
					{
						ans=0;
						break;
					}
					else if((i!=fx&&to==1)||(j!=fy&&to==2))
					{
						ans=0;
						break;
					}
					else
					{
						if(i==fx)
						{
							to=1;
							minn=min(minn,fy);
							maxx=max(maxx,fy);
							minn=min(minn,j);
							maxx=max(maxx,j);
						}
						else
						{
							to=2;
							minn=min(minn,fx);
							maxx=max(maxx,fx);
							minn=min(minn,i);
							maxx=max(maxx,i);
						}
					}
				}
			}
			if(fx==0&&flag==0)continue;
			flag=1;
			k=max(k,c+1);
			if(fx==0)
			{
				r1[c]=r1[c+1],r2[c]=r2[c+1],c1[c]=c1[c+1],c2[c]=c2[c+1];
				continue;
			}
			if(minn==2000&&maxx==0)
			{
				r1[c]=r2[c]=fx;
				c1[c]=c2[c]=fy;
				continue;
			}
			if(to==1)
			{
				for(int i=minn;i<=maxx;i++)
				{
					if(s[fx][i]=='.'||s[fx][i]<'a'+c)
					{
						ans=0;
						break;
					}
				}
				r1[c]=r2[c]=fx;
				c1[c]=minn,c2[c]=maxx;
			}
			else
			{
				for(int i=minn;i<=maxx;i++)
				{
					if(s[i][fy]=='.'||s[i][fy]<'a'+c)
					{
						ans=0;
						break;
					}
				}
				r1[c]=minn,r2[c]=maxx;
				c1[c]=c2[c]=fy;
			}
		}
		if(!ans)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%d\n",k);
		for(int i=0;i<k;i++)
		  printf("%d %d %d %d\n",r1[i],c1[i],r2[i],c2[i]);
	}
	return 0;
}
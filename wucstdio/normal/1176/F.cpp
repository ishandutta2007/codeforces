#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
ll f[200005][15],maxx[5][5];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	  for(int j=0;j<10;j++)
	    f[i][j]=-1000000000000;
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		memset(maxx,0,sizeof(maxx));
		while(m--)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==1)
			{
				if(d>maxx[1][1])
				{
					maxx[1][3]=maxx[1][2];
					maxx[1][2]=maxx[1][1];
					maxx[1][1]=d;
				}
				else if(d>maxx[1][2])
				{
					maxx[1][3]=maxx[1][2];
					maxx[1][2]=d;
				}
				else if(d>maxx[1][3])maxx[1][3]=d;
			}
			if(c==2)
			{
				if(d>maxx[2][1])
				  maxx[2][1]=d;
			}
			if(c==3)
			{
				if(d>maxx[3][1])
				  maxx[3][1]=d;
			}
		}
		for(int last=0;last<=9;last++)
		{
			f[i][last]=max(f[i][last],f[i-1][last]);
			if(last<=6)
			{
				if(maxx[1][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[1][1]);
				if(maxx[2][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[2][1]);
				if(maxx[3][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[3][1]);
				if(maxx[1][2])f[i][last+2]=max(f[i][last+2],f[i-1][last]+maxx[1][1]+maxx[1][2]);
				if(maxx[1][1]&&maxx[2][1])f[i][last+2]=max(f[i][last+2],f[i-1][last]+maxx[1][1]+maxx[2][1]);
				if(maxx[1][3])f[i][last+3]=max(f[i][last+3],f[i-1][last]+maxx[1][1]+maxx[1][2]+maxx[1][3]);
			}
			if(last==7)
			{
				if(maxx[1][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[1][1]);
				if(maxx[2][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[2][1]);
				if(maxx[3][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[3][1]);
				if(maxx[1][2])f[i][last+2]=max(f[i][last+2],f[i-1][last]+maxx[1][1]+maxx[1][2]);
				if(maxx[1][1]&&maxx[2][1])f[i][last+2]=max(f[i][last+2],f[i-1][last]+maxx[1][1]+maxx[2][1]);
				if(maxx[1][3])f[i][0]=max(f[i][0],f[i-1][last]+2*maxx[1][1]+maxx[1][2]+maxx[1][3]);
			}
			if(last==8)
			{
				if(maxx[1][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[1][1]);
				if(maxx[2][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[2][1]);
				if(maxx[3][1])f[i][last+1]=max(f[i][last+1],f[i-1][last]+maxx[3][1]);
				if(maxx[1][2])f[i][0]=max(f[i][0],f[i-1][last]+2*maxx[1][1]+maxx[1][2]);
				if(maxx[1][1]&&maxx[2][1])f[i][0]=max(f[i][0],f[i-1][last]+maxx[1][1]+maxx[2][1]+max(maxx[1][1],maxx[2][1]));
				if(maxx[1][3])f[i][1]=max(f[i][1],f[i-1][last]+2*maxx[1][1]+maxx[1][2]+maxx[1][3]);
			}
			if(last==9)
			{
				if(maxx[1][1])f[i][0]=max(f[i][0],f[i-1][last]+2*maxx[1][1]);
				if(maxx[2][1])f[i][0]=max(f[i][0],f[i-1][last]+2*maxx[2][1]);
				if(maxx[3][1])f[i][0]=max(f[i][0],f[i-1][last]+2*maxx[3][1]);
				if(maxx[1][2])f[i][1]=max(f[i][1],f[i-1][last]+2*maxx[1][1]+maxx[1][2]);
				if(maxx[1][1]&&maxx[2][1])f[i][1]=max(f[i][1],f[i-1][last]+maxx[1][1]+maxx[2][1]+max(maxx[1][1],maxx[2][1]));
				if(maxx[1][3])f[i][2]=max(f[i][2],f[i-1][last]+2*maxx[1][1]+maxx[1][2]+maxx[1][3]);
			}
		}
	}
	ll ans=0;
	for(int i=0;i<10;i++)ans=max(ans,f[n][i]);
	printf("%I64d\n",ans);
	return 0;
}
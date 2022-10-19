#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[2][200005];
int hzd[2][200005],hzx[2][200005];
int main()
{
	int t,n,ans,now,nx,ny;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<=1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=read()+1;
			}
		}
		a[0][1]=0;
		hzd[0][n+1]=hzx[0][n+1]=hzd[1][n+1]=hzx[1][n+1]=-2000000000;
		hzd[0][n]=a[0][n]+n;
		hzx[0][n]=a[0][n]-n;
		hzd[1][n]=a[1][n]+n;
		hzx[1][n]=a[1][n]-n;
		for(int i=n-1;i>=1;i--)
		{
			hzx[0][i]=max(a[0][i]-i,hzx[0][i+1]);
			hzd[0][i]=max(a[0][i]+i,hzd[0][i+1]);
			hzx[1][i]=max(a[1][i]-i,hzx[1][i+1]);
			hzd[1][i]=max(a[1][i]+i,hzd[1][i+1]);
		}
		ans=2000000000;
		now=0;
		ans=min(ans,max(max(hzx[0][1]+1,hzd[1][1]-2*n),0)+2*n-1);
		nx=0;
		ny=1;
		for(int i=1;i<=2*n-1;i++)
		{
			if(i%4==1)nx++;
			else if(i%4==2)ny++;
			else if(i%4==3)nx--;
			else ny++;
			now=max(now,a[nx][ny]-i);
			//printf("%d %d %d %d\n",i,nx,ny,now);
			if(i%4==3)ans=min(ans,2*n-1+max(max(now,hzx[0][i/2+1]-i/2),hzd[1][i/2+2]-i/2-2-(2*n-1)));
			else if(i%4==1)ans=min(ans,2*n-1+max(max(now,hzx[1][i/2+1]-i/2),hzd[0][i/2+2]-i/2-2-(2*n-1)));
		}
		printf("%d\n",ans);
	}
	return 0;
}
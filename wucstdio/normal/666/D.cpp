#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[4][2],b[4][2],x[4],y[4],xx[4],yy[4],t1,t2,ans,res[4],tmp1[4],tmp2[4];
bool flag[4];
void dfs(int step)
{
	if(step>=4)
	{
		int sum=0;
		for(int i=0;i<4;i++)
		  sum=max(sum,abs(a[i][0]-b[res[i]][0])+abs(a[i][1]-b[res[i]][1]));
		if(sum<ans)
		{
			ans=sum;
			for(int i=0;i<4;i++)xx[i]=b[res[i]][0],yy[i]=b[res[i]][1];
		}
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(flag[i])continue;
		if(a[step][0]!=b[i][0]&&a[step][1]!=b[i][1])continue;
		flag[i]=1;
		res[step]=i;
		dfs(step+1);
		flag[i]=0;
	}
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<4;i++)
		  scanf("%d%d",&a[i][0],&a[i][1]);
		ans=1000000000;
		for(int s=0;s<(1<<4);s++)
		{
			t1=t2=0;
			for(int i=0;i<4;i++)
			{
				if((1<<i)&s)y[t2++]=a[i][1];
				else x[t1++]=a[i][0];
			}
			sort(x,x+t1);
			sort(y,y+t2);
			for(int i=0;i<t1-1;i++)
			  if(x[i]==x[i+1])x[i]=1000000000;
			for(int i=0;i<t2-1;i++)
			  if(y[i]==y[i+1])y[i]=1000000000;
			sort(x,x+t1);
			sort(y,y+t2);
			while(t1&&x[t1-1]==1000000000)t1--;
			while(t2&&y[t2-1]==1000000000)t2--;
			if(t1>2||t2>2)continue;
			if(t1<=1&&t2<=1)continue;
			bool rev=0;
			if(t1<t2)
			{
				swap(t1,t2);
				for(int i=0;i<4;i++)swap(x[i],y[i]);
				rev=1;
			}
			if(t1==2&&t2==2)
			{
				int xa=x[0],xb=x[1],ya=y[0],yb=y[1];
				if(xb-xa!=yb-ya)continue;
				b[0][rev]=xa,b[0][1^rev]=ya;
				b[1][rev]=xa,b[1][1^rev]=yb;
				b[2][rev]=xb,b[2][1^rev]=ya;
				b[3][rev]=xb,b[3][1^rev]=yb;
				dfs(0);
			}
			if(t1==2&&t2==1)
			{
				int xa=x[0],xb=x[1],ya=y[0];
				b[0][rev]=xa,b[0][1^rev]=ya;
				b[1][rev]=xa,b[1][1^rev]=ya+xb-xa;
				b[2][rev]=xb,b[2][1^rev]=ya;
				b[3][rev]=xb,b[3][1^rev]=ya+xb-xa;
				dfs(0);
				b[0][rev]=xa,b[0][1^rev]=ya;
				b[1][rev]=xa,b[1][1^rev]=ya-xb+xa;
				b[2][rev]=xb,b[2][1^rev]=ya;
				b[3][rev]=xb,b[3][1^rev]=ya-xb+xa;
				dfs(0);
			}
			if(t1==2&&t2==0)
			{
				int xa=x[0],xb=x[1];
				int c1=0,c2=0;
				for(int j=0;j<4;j++)
				{
					if(a[j][rev]==xa)tmp1[c1++]=a[j][1^rev];
					else tmp2[c2++]=a[j][1^rev];
				}
				if(c1!=2||c2!=2)continue;
				if(tmp1[0]>tmp1[1])swap(tmp1[0],tmp1[1]);
				if(tmp2[0]>tmp2[1])swap(tmp2[0],tmp2[1]);
				y[0]=tmp1[0],y[1]=tmp1[1]-x[1]+x[0];
				y[2]=tmp2[0],y[3]=tmp2[1]-x[1]+x[0];
				sort(y,y+4);
				int ya=(y[0]+y[3])/2;
				int yb=ya+x[1]-x[0];
				b[0][rev]=xa,b[0][1^rev]=ya;
				b[1][rev]=xa,b[1][1^rev]=yb;
				b[2][rev]=xb,b[2][1^rev]=ya;
				b[3][rev]=xb,b[3][1^rev]=yb;
				dfs(0);
			}
		}
		if(ans==1000000000)printf("-1\n");
		else
		{
			printf("%d\n",ans);
			for(int i=0;i<4;i++)printf("%d %d\n",xx[i],yy[i]);
		}
	}
	return 0;
}
#include<cstdio>
#include<algorithm>

using namespace std;

int x[300],y[300];

int ans[1100100];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",x+i,y+i);
	}
	for(int i=0;i<1100100;i++) ans[i]=1;
	for(int i=0;i<M;i++) for(int j=i+1;j<M;j++)
	{
		int dx=x[i]-x[j],dy=y[i]-y[j];
		if(dy<0) dx*=-1,dy*=-1;
		long long tmp=(long long)y[i]*dx;
		if(dy==0||tmp%dy!=0) continue;
		long long d=tmp/dy;
		long long xx=(long long)x[i]-d;
		if(xx<=0||xx>N) continue;
		int a=2;
		for(int k=j+1;k<M;k++)
		{
			int dx2=x[i]-x[k],dy2=y[i]-y[k];
			if((long long)dx2*dy==(long long)dy2*dx) a++;
		}
		ans[xx]=max(ans[xx],a);
	}
	int res=0;
	for(int i=1;i<=N;i++) res+=ans[i];
	printf("%d\n",res);
	return 0;
}
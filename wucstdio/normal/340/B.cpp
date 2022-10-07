#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double x[305],y[305],ans;
int n;
double f(double x){return x>0?x:-x;}
double calc(int i,int j,int k)
{
	double x1=x[i]-x[j],y1=y[i]-y[j];
	double x2=x[j]-x[k],y2=y[j]-y[k];
	return f(x1*y2-x2*y1)/2;
}
bool judge(int i,int j,int k)
{
	double x1=x[i]-x[j],y1=y[i]-y[j];
	double x2=x[i]-x[k],y2=y[i]-y[k];
	return x1*y2-x2*y1>0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		double max1=0,max2=0;
		for(int k=1;k<=n;k++)
		{
			if(k==i||k==j)continue;
			if(judge(i,j,k))max1=max(max1,calc(i,j,k));
			else max2=max(max2,calc(i,j,k));
		}
		if(max1>0&&max2>0)ans=max(ans,max1+max2);
	}
	printf("%lf\n",ans);
	return 0;
}
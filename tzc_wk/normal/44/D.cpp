#include <iostream>
#include <cmath>
using namespace std;
struct node
{
	double a,b,c;
};
double max(double a,double b)
{return a<b?b:a;}
double min(double a,double b)
{return a>b?b:a;}
node tm[5005];
double one_2[5005]; 
const double inf= 2147483647.0;
int main()
{
	double a,b,c;
	int n;
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&tm[i].a,&tm[i].b,&tm[i].c);
	}
	double a1=tm[1].a;
	double b1=tm[1].b;
	double c1=tm[1].c;
	double dis_pow2;
	for (j=2;j<=n;j++)
	{ 
		double a2=tm[j].a;
		double b2=tm[j].b;
		double c2=tm[j].c;
		dis_pow2=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2)+(c1-c2)*(c1-c2));
		one_2[j]=dis_pow2;
	}
	double  ans=inf;
	int id;
	double dis2;
	for (id=2;id<=n;id++)
	{
		double dis1=one_2[id];
		a1=tm[id].a;
		b1=tm[id].b;
		c1=tm[id].c;
		for (j=2;j<=n;j++)
		{ 
			if (j==id) continue;
			double a2=tm[j].a;
			double b2=tm[j].b;
			double c2=tm[j].c;
			dis2=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2)+(c1-c2)*(c1-c2));
			double cha=fabs(dis1-one_2[j]);
			ans=min(ans,dis1+(cha+dis2)/2);
		}
	} 
	printf("%.16lf\n",ans);
	return 0;
	
}
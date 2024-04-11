#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

double x, y;

void add(double a, double d)
{
	while(d!=0)
	{
		//printf("%lf, %lf\n", x, y);
		if(d!=0 && y==a)
		{
			if(x>d)
			{
				x-=d;
				d=0;
			}
			else
			{
				d-=x;
				x=0;
			}
		}
		if(d!=0 && y==0)
		{
			if(a-x>d)
			{
				x+=d;
				d=0;
			}
			else
			{
				d-=(a-x);
				x=a;
			}
		}
		if(d!=0 && x==0)
		{
			if(y>d)
			{
				y-=d;
				d=0;
			}
			else
			{
				d-=y;
				y=0;
			}
		}
		if(d!=0 && x==a)
		{
			if(a-y>d)
			{
				y+=d;
				d=0;
			}
			else
			{
				d-=(a-y);
				y=a;
			}
		}
	}
}

int main()
{
	double a, d;
	int n;
	scanf("%lf%lf%d", &a, &d, &n);
	while(d>4*a) d-=4*a;
	for(int i=0; i<n; i++)
	{
		//printf("d=%lf, a=%lf\n", d, a);
		add(a, d);
		printf("%lf %lf\n", x, y);
	}
	return 0;
}
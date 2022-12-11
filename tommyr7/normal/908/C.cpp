#include <bits/stdc++.h>
#define Maxn 1007
using namespace std;
int n,r;
int a[Maxn];
double mn;
pair<double,double> p[Maxn];
void check(int u,int v)
{
	double d=fabs(1.0*a[u]-1.0*a[v]);
	if (d>2.0*r) return;
	double del=(double)sqrt(4.0*r*r-1.0*d*d);
	mn=max(mn,p[v].second+del);
}
int main()
{
	scanf("%d%d",&n,&r);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		mn=1.0*r;
		for (int j=1;j<i;j++)
			check(i,j);
		p[i]=make_pair(1.0*a[i],mn);
	}
	for (int i=1;i<=n;i++)
		printf("%.8lf ",p[i].second);
	printf("\n");
	return 0;
}
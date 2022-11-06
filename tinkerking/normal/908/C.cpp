#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,R;
double d[10010];
int off = 2010;

int main()
{
	scanf("%d%d",&N,&R);
	for (int i=0;i<=10000;i++)d[i] = -R;
	for (int i=1;i<=N;i++)
	{
		int X;
		scanf("%d",&X);
		X += off;
		double ans = R;
		for (int j=X-2*R;j<=X+2*R;j++)
		{
			double tmp = d[j] + sqrt(fabs(4*R*R - (X-j)*(X-j)));
			ans = max(ans,tmp);
		}
		printf("%.10lf%c",d[X] = ans," \n"[i==N]);
	}
}
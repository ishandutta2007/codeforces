#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define D double
const double eps=1e-10;

int n;
bool bo=0;
D mini=1000000000000000000.0, maxi=0, ap, bp, a, b;
D a1, b1;

D dist(D x, D y)
{
	return (x-a)*(x-a)+(y-b)*(y-b);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%lf%lf", &n, &a, &b);
	for(int i=0; i<=n; i++)
	{
		D x, y;
		if(i<n)
			scanf("%lf%lf", &x, &y);
		else
		{
			x=a1;
			y=b1;
		}
		if(bo)
		{
			D xx=x, yy=y;
			D qwe=(xx+ap)/2;
			D asd=(yy+bp)/2;
			for(int j=0; j<70; j++)
			{
				if(abs(dist(xx, yy)-dist(ap, bp))<eps)
					break;
				if(dist(xx, yy)>dist(ap, bp))
				{
					xx=qwe;
					yy=asd;
				}
				else
				{
					ap=qwe;
					bp=asd;
				}
				qwe=(xx+ap)/2;
				asd=(yy+bp)/2;
			}
			//printf("%lf %d\n", dist(qwe, asd), i);
			mini=min(mini, dist(qwe, asd));
		}
		else
		{
			a1=x;
			b1=y;
		}
		if(i==n)
			break;
		D c=(x-a)*(x-a)+(y-b)*(y-b);
		mini=min(mini, c);
		maxi=max(maxi, c);
		ap=x, bp=y;
		bo=1;
	}
	//printf("%lf\n", mini);
	printf("%.10lf\n", (D)(maxi-mini)*3.14159265358979323846);
	return 0;
}
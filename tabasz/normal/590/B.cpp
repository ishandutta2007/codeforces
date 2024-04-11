#include<bits/stdc++.h>
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
const D eps=1e-13;

LL x1, x2, y11, y2, v, t, v1, v2, w1, w2;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &x1, &y11, &x2, &y2, &v, &t, &v1, &v2, &w1, &w2);
	x2-=x1;
	y2-=y11;
	LL xx=x2-v1*t, yy=y2-v2*t;
	if(sqrt((D)(xx*xx+yy*yy))<=sqrt(((D)v*v))*t)
	{
		double p=0, k=t, mid=(p+k)/2, x3=x2, y3=y2, res=t;
		for(int i=0; i<70; i++)
		{
			if(abs(k-p)<eps)
				break;
			D xt=x3-v1*mid;
			D yt=y3-v2*mid;
			if(sqrt(xt*xt+yt*yt)<=sqrt((D)v*(D)v)*mid)
			{
				res=min(res, mid);
				k=mid;
			}
			else
				p=mid;
			mid=(p+k)/2;
		}
		printf("%lf\n", res);
		return 0;
	}
	x2-=v1*t;
	y2-=v2*t;
	double p=0, k=1000000000.0, mid=(p+k)/2, x3=x2, y3=y2, res=1000000000.0;
	for(int i=0; i<70; i++)
	{
		if(abs(k-p)<eps)
			break;
		//printf("%lf\n", mid);
		D xt=x3-w1*mid;
		D yt=y3-w2*mid;
		//printf("%lf %lf %lf %lf\n", xt, yt, sqrt(xt*xt+yt*yt), sqrt((D)v*(D)v)*(mid+(D)t));
		if(sqrt(xt*xt+yt*yt)<=sqrt((D)v*(D)v)*(mid+(D)t))
		{
			res=min(res, mid);
			k=mid;
		}
		else
			p=mid;
		mid=(p+k)/2;
	}
	printf("%.9lf\n", res+t);
	return 0;
}
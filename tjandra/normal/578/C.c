#include<stdio.h>
#include<time.h>
#define eps (ld)(1e-14)
typedef unsigned u;
typedef long double ld;
typedef double d;
d N[222222];
int main()
{
	d st=clock();
	u n,i=-1;ld lo,hi,md,s,mi,ma,min,man;
	for(scanf("%u",&n);++i<n;scanf("%lf",N+i));
	lo=0.0;hi=20002.0;
	while((md=(lo+hi)/2.0)-lo>eps)
	{
		s=md-10001.0;
		mi=ma=min=man=0.0;
		for(i=-1;++i<n;)
		{
			min+=N[i]+s;
			man+=N[i]+s;
			if(min>0.0)min=0.0;
			if(man<0.0)man=0.0;
			if(mi>min)mi=min;
			if(ma<man)ma=man;
		}
		mi=-mi;
		if(mi>ma)lo=md;
		else hi=md;
		if((clock()-st)/CLOCKS_PER_SEC>1.8)break;
	}
	printf("%.15lf\n",(d)(ma>mi?ma:mi));
	return 0;
}
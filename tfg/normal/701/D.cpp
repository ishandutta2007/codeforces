#include <cstdio>
#include <iostream>
#include <utility>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

int main()
{
	int n, l, v1, v2, k;
	n=readint();
	l=readint();
	v1=readint();
	v2=readint();
	k=readint();
	int v=(n+k-1)/k;
	//printf("%i trips.\n",v);
	double max=((double)l)/v1;
	double normal=((double)l)/v1;
	double min=0.0;
	double bus_t;
	for(int i=0;i<100;i++)
	{
		bus_t=(max+min)/2;
		double back_t=(bus_t*(v2-v1))/(v2+v1);
		//printf("testing bus_t %.5lf, back_t %.5lf, totaldist=%.5lf.\n",bus_t,back_t,l-((v)*(v1)*(bus_t+back_t)-v1*back_t));
		//printf("dist by bus=%.5lf.\n",v2*bus_t);
		if(l-((v-1)*(v1)*(bus_t+back_t))<v2*bus_t)
		{
			//printf("limiting max\n");
			max=bus_t;
		}
		else
		{
			//printf("limiting min\n");
			min=bus_t;
		}
		//}
	}
	double dist=l-(bus_t*v2);
	double total_time=bus_t+dist/v1;
	printf("%.20lf\n",total_time);
}
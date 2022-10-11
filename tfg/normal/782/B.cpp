#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

const int ms=100100;
const double eps=1e-6;

int n;
int x[ms];
int v[ms];

double aabs(double x)
{
	if(x<0)
		return -x;
	else
		return x;
}

double f(double pos)
{
	double tim=0.0;
	for(int i=0;i<n;i++)
		tim=std::max(tim, ((double)(aabs(pos-(double)x[i])))/(double)(v[i]));
	//std::cout << "at " << pos << ", ans is " << tim << '\n';
	return tim;
}

double ts(double l, double r)
{
	if(r-l<=eps) return (l+r)/2.0;
	//std::cout << "ts(" << l << ", " << r << ")\n";
	double leftThird=(2*l+r)/3;
	double rightThird=(l+2*r)/3;
	if(f(leftThird)>=f(rightThird))
		return ts(leftThird, r);
	else
		return ts(l, rightThird);
}

int main()
{
	double l, r;
	l=1e10;
	r=-1e10;
	std::cin >> n;
	for(int i=0;i<n;i++)
		scanf("%i",x+i);
	for(int i=0;i<n;i++)
		scanf("%i",v+i);
	for(int i=0;i<n;i++)
	{
		l=std::min(l, double(x[i]));
		r=std::max(r, double(x[i]));
	}
	std::cout << std::fixed << std::setprecision(20);
	std::cout << f(ts(l, r)) << '\n';
	//std::cout << ts(l, r) << '\n';
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double l,h;
	scanf("%lf%lf",&h,&l);
	printf("%.10lf\n",(l*l-h*h)/2/h);
	return 0;
}
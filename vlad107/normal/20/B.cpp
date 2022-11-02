#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

double a,b,c,x1,x2,d;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%lf%lf%lf",&a,&b,&c);
	if (a==0){
		if (b==0){
			if (c==0)
				printf("-1\n");
			else printf("0\n");
			return 0;
		}
		printf("1\n%.10lf\n",-c/b);
		return 0;
	}
	d=b*b-4*a*c;
	if (d<0)printf("0\n");else
	if (d==0)printf("1\n%.11lf\n",-b/(2*a));else{
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		if (x1>x2)std::swap(x1,x2);
		printf("2\n%.11lf\n%.11lf",x1,x2);
	}
	return 0;
}
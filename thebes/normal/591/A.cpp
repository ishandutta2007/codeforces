#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	double t = (double)n/(double)(a+b);
	printf("%.5lf\n",t*a);
	return 0;
}
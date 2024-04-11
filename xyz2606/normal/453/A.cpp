#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int m, n;
double ans;
double pow(double x, int n) {
	double tmp(x), rtn(1);
	while(n) {
		if(n & 1)
			rtn *= tmp;
		n /= 2;
		tmp *= tmp;
	}
	return rtn;
}
int main()
{
	scanf("%d%d", &m, &n);
	ans = m;
	for(int i = 1; i <= m; i++) {
		ans -= pow((double)(i - 1) / m, n);
	}
	printf("%.10f\n", ans);
	fclose(stdin);
	return 0;
}
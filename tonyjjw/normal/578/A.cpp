//*

#include<stdio.h>
#include<vector>
#include<algorithm>
#define eps (1e-9)

using namespace std;

int main(){
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	double a, b;
	scanf("%lf%lf", &a, &b);
	if (b > a){
		puts("-1");
		return 0;
	}
	else if (a == b){
		printf("%.10lf", a);
		return 0;
	}
	int l = 1, r = 1e9, m;
	double k = a / b + 1.0;
	double y;
	int p;
	while (l <= r){
		m = (l + r) >> 1;
		if (2.0*m > k){
			r = m - 1;
		}
		else{
			p = m;
			l = m + 1;
		}
	}
	y = (2.0*p) / k;
	printf("%.10lf", b*k / (2.0*p));
	return 0;
}

//*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const double eps = 1e-9;

struct Cir {
	double x , y;
}C[N];

int n , m , x , y , r , X[N];

#define sqr(x) ((x) * (x))

void push(int x) {
	if(x == 1) {
		C[1].y = r; C[1].x = X[1]; return;
	}
	C[x].y = r;
	for(int i = 1;i < x;++ i) {
		double dis = fabs(X[i] - X[x]);
		if(dis > 2 * r) continue;
		C[x].y = max(C[x].y , sqrt(sqr(2 * r) - sqr(dis)) + C[i].y);
	}
}

int main(void) {
	scanf("%d%d" , &n , &r);
	for(int i = 1;i <= n;++ i) scanf("%d" , &X[i]);
	for(int i = 1;i <= n;++ i) push(i) , printf("%.10lf " , C[i].y);
}
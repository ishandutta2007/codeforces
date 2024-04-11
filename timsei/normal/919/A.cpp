#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n , m , x , y;
double ans;

int main(void) {
	ans = 1e50;
	for(int i = scanf("%d%d" , &n , &m) / 2;i <= n;++ i) {
		cin >> x >> y;
		ans = min(ans , (double) x/ (double) y);
	}
	printf("%.12lf\n" , ans * m);
}
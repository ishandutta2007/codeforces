#include<bits/stdc++.h>

using namespace std;

double a[100010];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int l, r;
		scanf("%d%d", &l ,&r);
		int p = (r - l) + 1;
		int q = (r / m) - (l - 1) / m;
		a[i] = (p - q) * 1.0 / p;
	}
	a[0] = a[n];
	double ans = 0;
	for(int i = 1; i <= n; i++){
		ans += 1 - a[i] * a[i-1];
	}
	printf("%.10lf\n", ans * 2000);
	return 0;
}
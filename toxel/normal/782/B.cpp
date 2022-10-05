#include<bits/stdc++.h>

const int N = 60010;
const double eps = 1e-8;

int n;
int x[N], v[N];

bool check(__float128 time){
	__float128 left = -1e100, right = 1e100;
	for (int i = 0; i < n; ++ i){
		left = std::max(left, x[i] - v[i] * time);
		right = std::min(right, x[i] + v[i] * time);
		if (left- right > eps){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &v[i]);
	}
	__float128 left = 0, right = 1e9;
	while (right - left > eps){
		__float128 mid = (left + right) / 2;
		if (check(mid)){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	return printf("%.10lf\n", (double) left), 0;
}
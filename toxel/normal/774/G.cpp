#include<bits/stdc++.h>

int a, h, w;

int extended_euclid(int a, int b, int &x, int &y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int ans = extended_euclid(b, a % b, x, y);
	int p = y;
	y = x - a / b * y;
	x = p;
	if (x < 0){
		y += (x / b - 1) * a;
		x -= (x / b - 1) * b;
	}
	if (x > b){
		y += x / b * a;
		x %= b;
	}
	return ans;
}

int main(){
	scanf("%d%d%d", &a, &w, &h);
	if (h < a || w < a){
		return printf("-1\n"), 0;
	}
	if (h < w){
		std::swap(h, w);
	}
	int u = a + h, b = h - w, v = a + w, x, y;
	int gcd = extended_euclid(-u, v, x, y);
	if (b % gcd){
		return printf("-1\n"), 0;
	}
	x *= b / gcd, y *= b / gcd;
	int c = std::abs(v / gcd);
	x = (x % c + c) % c;
	int max = w / a / c + 1;
	int p = max * c + x;
	while (1ll * p * a > w){
		p -= c;
	}
	if (p > 0){
		return printf("%.10lf\n", 1.0 * (w - 1ll * p * a) / (p + 1)), 0;
	}
	return printf("-1\n"), 0;
}
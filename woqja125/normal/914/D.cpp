#include<cstdio>
int IT[1050000];
int _b;
int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}

void set(int x, int v) {
	IT[x += _b] = v;
	while (x/=2) {
		IT[x] = gcd(IT[x * 2], IT[x * 2 + 1]);
	}
}

int getRMost(int st, int g) {
	int x = st + _b;
	while (IT[x] % g == 0) {
		if (x % 2 == 1) x++;
		x /= 2;
	}
	while (x < _b) {
		if (IT[x * 2] % g == 0) x = x * 2 + 1;
		else x = x * 2;
	}
	return x - _b - 1;
}

int getLMost(int st, int g) {
	int x = st + _b;
	while (IT[x] % g == 0) {
		if (x % 2 == 0) x--;
		x /= 2;
	}
	while (x < _b) {
		if (IT[x * 2 + 1] % g == 0) x = x * 2;
		else x = x * 2 + 1;
	}
	return x - _b + 1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (_b = 1; _b <= n; _b *= 2);
	IT[_b] = IT[_b + n + 1] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", IT + _b + i);
	}
	for (int i = _b; i >= 1; i--) {
		IT[i] = gcd(IT[i * 2], IT[i * 2 + 1]);
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int t, x, y, u;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			scanf("%d", &u);
			if (u == 1) {
				printf("YES\n");
				continue;
			}
			int r = getRMost(x, u);
			int l = getLMost(y, u);
			if (l - r <= 2) printf("YES\n");
			else printf("NO\n");
		}
		else {
			set(x, y);
		}
	}
	return 0;
}
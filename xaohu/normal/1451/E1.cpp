#include <bits/stdc++.h>
using namespace std;

int n, a[1 << 20], b[1 << 20], c[1 << 20], d[1 << 20];

//~ vector <int> ans = {0, 0, 2, 3, 3, 3, 0, 3, 0};
vector <int> ans;

int AND(int x, int y) {
	//~ return (ans[x] & ans[y]);
	printf("AND %d %d\n", x, y);
	fflush(stdout);
	int z;
	scanf("%d", &z);
	return z;
}

int XOR(int x, int y) {
	//~ return (ans[x] ^ ans[y]);
	printf("XOR %d %d\n", x, y);
	fflush(stdout);
	int z;
	scanf("%d", &z);
	return z;
}

int B(int x, int k) {
	return ((x >> k) & 1);
}

int e[4][4];

int main() {
	srand(time(0));
	scanf("%d", &n);
	//~ n = 1 << 16;
	//~ ans = {1};
	//~ for (int i = 0; i < n; ++i)
		//~ ans.push_back(rand() % 2);
	for (int i = 2; i <= n; ++i) {
		a[i] = XOR(i - 1, i);
		b[i] = b[i - 1] ^ a[i];
	}
	
	e[1][2] = AND(1, 2);
	e[1][3] = AND(1, 3);
	e[2][3] = AND(2, 3);
	
	for (int bit = 0; (1 << bit) < n; ++bit) {
		int p, q;
		if (!B(b[2], bit)) {
			 p = 1;
			 q = 2;
		}
		else if (!B(b[3], bit)) {
			p = 1;
			q = 3;
		}
		else {
			p = 2;
			q = 3;
		}
		c[p] = B(e[p][q], bit);
		for (int j = 1; j <= n; ++j) {
			c[j] = c[p] ^ (B(b[j], bit) != B(b[p], bit));
			d[j] += c[j] * (1 << bit);
		}
	}
	printf("! ");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", d[i]);
		//~ if (d[i] != ans[i])
			//~ cout << "BAD";
	}
	fflush(stdout);
	return 0;
}
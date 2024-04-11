#include<stdio.h>
#include<vector>
int a[1001][5];


struct vec {
	int a, b, c, d, e;
	vec(int *x, int *y){
		a = y[0] - x[0];
		b = y[1] - x[1];
		c = y[2] - x[2];
		d = y[3] - x[3];
		e = y[4] - x[4];
	}
};

long long dot(const vec &a, const vec &b) {
	return  1ll * a.a*b.a + 1ll * a.b*b.b + 1ll * a.c*b.c + 1ll * a.d*b.d + 1ll * a.e*b.e;
}
using namespace std;
vector<int> ans;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
	if (n >= 20) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		bool f;
		f = true;
		for (int j = 1; j <= n; j++) for (int k = j + 1; k <= n; k++)if (j != i && k != i) {
			vec x(a[i], a[j]), y(a[i], a[k]);
			long long d = dot(x, y);
			if (d > 0) f = false;
		}
		if (f) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (auto x : ans) printf("%d ", x);
	return 0;
}
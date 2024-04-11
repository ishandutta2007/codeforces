#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct f {
	int d, x, c;
	f(int D, int X, int C):d(D), x(X), c(C){}
	bool operator<(const f &A) const { return d < A.d; }
};

vector<f> in, out;

long long inc[1000010];
int ninc[100001], noutc[100001];


int main() {
	int n, m, k;
	int x, y, z, w;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &x, &y, &z, &w);
		if (y == 0) out.emplace_back(x, z, w);
		else in.emplace_back(x, y, w);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	long long s = -n;
	for (int i = 1; i <= n; i++) {
		ninc[i] = noutc[i] = -1;
	}
	z = 0;
	int j = 0;
	for (int i = 0; i <= 1000000; i++) {
		for (; j < in.size() && in[j].d <= i; j++) {
			x = in[j].x, y = in[j].c;
			s -= ninc[x];
			if (ninc[x] == -1) {
				z++;
				ninc[x] = y;
			}
			else if (ninc[x] > y) ninc[x] = y;
			s += ninc[x];
		}
		if (z == n) inc[i] = s;
		else inc[i] = -1;
		
	}

	j = out.size() - 1;
	z = 0;
	s = -n;
	long long ans = 1000000000000000ll;
	for (int i = 1000000; i - k - 1 >= 0; i--) {
		if (inc[i - k - 1] == -1) break;
		for (; j >= 0 && out[j].d >= i; j--) {
			x = out[j].x; y = out[j].c;
			s -= noutc[x];
			if (noutc[x] == -1) {
				z++;
				noutc[x] = y;
			}
			else if (noutc[x] > y) noutc[x] = y;
			s += noutc[x];
		}
		if (z == n && ans > s + inc[i - k - 1])
			ans = s + inc[i - k - 1];
	}
	if (ans == 1000000000000000ll) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}
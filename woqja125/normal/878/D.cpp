#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long x[100100][64];
pair<int, int> ord[100100][13];

int main() {
	int n, k, q, t, a, b;
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < k; i++) for (int j = 1; j <= n; j++)
	{
		scanf("%d", &ord[j][i].first);
		ord[j][i].second = i;
	}
	for (int i = 1; i <= n; i++) sort(ord[i], ord[i] + k);
	int K = 1 << k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < K; j++) x[i][j >> 6] |= ((j >> (i)) & 1llu) << (j & 0x3f);
	}
	int nk = k;
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d", &t, &a, &b);
		if (t == 3) {
			a--;
			int bf = 0;
			for (int j = k-1; j >= 0; j--) {
				bf |= (1 << ord[b][j].second);
				if ((x[a][bf >> 6] >> (bf & 63)) & 1) {
					printf("%d\n", ord[b][j].first);
					break;
				}
			}
		}
		if (t == 1) {
			a--; b--;
			for (int j = 0; j <= ((K-1)>>6); j++) x[nk][j] = x[a][j] | x[b][j];
			nk++;
		}
		if (t == 2) {
			a--; b--;
			for (int j = 0; j <= ((K - 1) >> 6); j++) x[nk][j] = x[a][j] & x[b][j];
			nk++;
		}
	}
	return 0;
}
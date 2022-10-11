#include <bits/stdc++.h>
using namespace std;

int N, M;
int c[1<<18], cnt[1<<18];
int nvalid;
int k[1<<18], ksm;
int mn = 2e9;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%d", c+i), c[i]--;
	for (int i = 0; i < M; ++i) scanf("%d", k+i), ksm += k[i], nvalid += !k[i];

	int r = 0;
	for (int i = 0; i < N; ++i) {
		while (r <= i || (r < N && nvalid < M)) {
			if (++cnt[c[r]] == k[c[r]]) nvalid++;
			r++;
		}
		if (nvalid >= M) mn = min(mn, r - i - ksm);
		if (cnt[c[i]]-- == k[c[i]]) nvalid--;
	}

	if (mn == 2e9) printf("-1\n");
	else printf("%d\n", mn);
}
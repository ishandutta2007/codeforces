#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int, int> gn;

int a[101];

vector<int> P;

int getgn(int x) {
	int fg = 0;
	if (gn.count(x) == 1) return gn[x];
	for (int j = 1; x >> (j - 1); j++) {
		int t = x&((1 << (j - 1)) - 1);
		t |= x >> j;
		fg |= (1<<getgn(t));
	}
	for (int r = 0; ; r++) if (((fg >> r) & 1) == 0) return gn[x] = r;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		int t = a[i];
		for (int j = 2; j*j <= t; j++) {
			if (t%j != 0) continue;
			P.push_back(j);
			while (t%j == 0) t /= j;
		}
		if (t != 1) P.push_back(t);
	}
	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	gn[0] = 0;
	int G = 0;
	for (auto p : P) {
		int x = 0;
		for (int i = 1; i <= n; i++) {
			int t = a[i];
			if (t % p != 0) continue;
			int j = 0;
			for (; t%p == 0; t /= p, j++);
			x |= (1 << (j-1));
		}
		G ^= getgn(x);
	}
	if (G) printf("Mojtaba\n");
	else printf("Arpa\n");
	return 0;
}
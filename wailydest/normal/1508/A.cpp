#include <cstdio>
#include <cassert>
#include <algorithm>
#include <utility>
#include <cstring>

const int N = 100005;
int t, n, amt[3][2], amt_k[2][2 * N];
char s[3][2 * N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s%s%s", &n, s[0], s[1], s[2]);
		memset(*amt, 0, 24);
		for (int i = 0; i < 2 * n; ++i) for (int j = 0; j < 3; ++j) ++amt[j][s[j][i] - '0'];
		bool p[3];
		for (int j = 0; j < 3; ++j) p[j] = amt[j][0] < amt[j][1];
		if (p[0] != p[1]) {
			if (p[0] == p[2]) std::swap(s[1], s[2]);
			else {
				std::swap(s[0], s[2]);
				p[0] = !p[0];
			}
		}
		int k = p[0], size = 0;
		for (int j = 0; j < 2; ++j) for (int i = 0; i <= 2 * n; ++i) amt_k[j][i] = 0;
		for (int j = 0; j < 2; ++j) {
			int i, ind;
			for (i = 0, ind = 0; i < 2 * n; ++i) {
				if (s[j][i] - '0' == k) ++ind;
				else ++amt_k[j][ind];
			}
			size = std::max(size, ind);
		}
		assert(size >= n);
		for (int i = 0; i <= size; ++i) {
			for (int j = 0; j < std::max(amt_k[0][i], amt_k[1][i]); ++j) printf("%d", (int)!k);
			if (i != size) printf("%d", k);
		}
		printf("\n");
	}
	return 0;
}
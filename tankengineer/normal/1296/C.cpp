#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 200005;

int n;

char s[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s);
		map<pair<int, int>, int> mem;
		int x = 0, y = 0;
		mem[make_pair(x, y)] = 0;
		int ansl = -1, ansr = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') {
				--x;
			} else if (s[i] == 'R') {
				++x;
			} else if (s[i] == 'U') {
				--y;
			} else if (s[i] == 'D') {
				++y;
			}
			pair<int, int> pos = make_pair(x, y);
			if (mem.count(pos)) {
				int nl = mem[pos], nr = i;
				if (ansl == -1 || ansr - ansl > nr - nl) {
					ansl = nl, ansr = nr;
				}
			}
			mem[pos] = i + 1;
		}
		if (ansl == -1) {
			printf("%d\n", -1);
		} else {
			printf("%d %d\n", ansl + 1, ansr + 1);
		}
	}
	return 0;
}
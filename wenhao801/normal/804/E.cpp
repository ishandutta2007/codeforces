#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second

vector <pii> op4 = {{1, 2}, {1, 3}, {2, 4}, {1, 4}, {2, 3}, {3, 4}};
vector <pii> op5 = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 5}, {3, 5}, {1, 5}, {3, 4}, {2, 4}, {4, 5}};
vector <pii> op44 = {{1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 4}, {1, 4}, {2, 3}, {3, 1}, {4, 2}, {3, 2}, {2, 2}, {3, 3}, {4, 1}, {4, 4}, {3, 4}, {4, 3}};
vector <pii> op45 = {{1, 5}, {1, 1}, {2, 1}, {2, 4}, {1, 2}, {4, 5}, {1, 3}, {3, 1}, {4, 4}, {4, 2}, {2, 5}, {2, 3}, {4, 1}, {3, 2}, {1, 4}, {3, 5}, {3, 4}, {2, 2}, {4, 3}, {3, 3}};

int n;
void out (int x, int y) {
	if (x > y) swap(x, y);
	printf("%d %d\n", x, y);
}

int main () {
	n = read();
	if (n % 4 > 1) { puts("NO"); return 0; }
	puts("YES"); int i, j;
	if (n % 4 == 0) {
		for (i = 0; i < n; i += 4) for (auto j: op4) out(j.fr + i, j.se + i);
		for (i = 0; i < n; i += 4) for (j = i + 4; j < n; j += 4) for (auto k: op44)
			out(k.fr + i, k.se + j);
	}
	else if (n > 1) {
		for (auto i: op5) out(i.fr, i.se);
		for (i = 5; i < n; i += 4) {
			for (auto j: op4) out(j.fr + i, j.se + i);
			for (auto j: op45) out(j.fr + i, j.se);
		}
		for (i = 5; i < n; i += 4) for (j = 5; j < i; j += 4) for (auto k: op44)
			out(k.fr + i, k.se + j);
	}
	return 0;
}
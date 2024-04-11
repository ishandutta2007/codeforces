#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

int main () {
	int n = read();
	if (n <= 3) { puts("NO"); return 0; }
	puts("YES");
	if (n % 4 == 0) {
		cout << R"(1 * 2 = 2
2 * 3 = 6
6 * 4 = 24
)";
	}
	else if (n % 4 == 1) {
		cout << R"(5 - 1 = 4
4 - 2 = 2
2 * 3 = 6
6 * 4 = 24
)";
	}
	else if (n % 4 == 2) {
		cout << R"(5 * 1 = 5
5 - 4 = 1
3 + 2 = 5
5 - 1 = 4
4 * 6 = 24
)";
	}
	else {
		cout << R"(2 + 3 = 5
5 + 4 = 9
7 - 5 = 2
2 * 9 = 18
18 + 6 = 24
24 * 1 = 24
)";
	}
	for (int i = n % 4 + 4 + 1; i <= n; i += 4) printf("%d + %d = %d\n%d + %d = %d\n%d - %d = 0\n0 + 24 = 24\n", i, i + 3, i + i + 3, i + 1, i + 2, i + i + 3, i + i + 3, i + i + 3, 0);
	return 0;
}
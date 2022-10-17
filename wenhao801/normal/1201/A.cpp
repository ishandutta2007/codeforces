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

int n, m;

int bucket[1010][10] = {};
int pt[1010] = {};

int main () {
	n = read(), m = read();
	int i, j;
	for (i = 1; i <= n; i++) {
		string x;
		cin >> x;
		for (j = 1; j <= m; j++) 
			bucket[j][x[j - 1] - 'A' + 1]++;
	}
	for (i = 1; i <= m; i++)
		pt[i] = read();
	int ans = 0;
	for (i = 1; i <= m; i++) {
		int Max = 0;
		for (j = 1; j <= 5; j++)
			Max = max(Max, bucket[i][j]);
		ans += Max * pt[i];
	}
	cout << ans << endl;
	return 0;
}
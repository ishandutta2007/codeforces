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

int l;
char a[100100] = {};
int hotel[15] = {};

int main () {
	cin >> l;
	cin >> a;
	for (int i = 0; i < l; i++) {
		if (a[i] == 'L') {
			for (int j = 0; j < 10; j++)
				if (!hotel[j]) { hotel[j] = 1; break; }
		}
		else if (a[i] == 'R') {
			for (int j = 9; j >= 0; j--)
				if (!hotel[j]) { hotel[j] = 1; break; }
		}
		else {
			int t = a[i] - '0';
			hotel[t] = 0;
		}
	}
	for (int i = 0; i <= 9; i++)
		cout << hotel[i];
	return 0;
}
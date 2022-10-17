#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int main () {
	int n = read();
	string x;
	cin >> x;
	int i, l = 0, r = 0;
	for (i = 0; i < n; i++)
		if (x[i] == 'L') l--;
		else r++;
	cout << r - l + 1 << endl;
	return 0;
}
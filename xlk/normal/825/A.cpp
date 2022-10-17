#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, l;
	string s;
	cin >> n >> s;
	for (int i = l = 0; i < n; i++) {
		if (s[i] == '0') {
			printf("%d", i - l);
			l = i + 1;
		}
	}
	printf("%d\n", n - l);
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cnt(m);
	int res = 0;
	scanf/*..*/("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf("%c", &c);
			if (c == 'Y') ++cnt[j];
		}
		if (i + 1 < n)scanf("\n");
	}
	for (int i = 0; i < m; i++) res += (cnt[i] >= k);
	cout << res << endl;
	int kitten = 0;
}
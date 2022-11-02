#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 1e3;

char r[6];
string s[MAXN];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", r);
		s[i] = string(r);
	}
	
	int k = 6;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int cnt = 0;
			for (int p = 0; p < 6; p++)
				if (s[i][p] != s[j][p])
					cnt++;
			k = min(k, (cnt - 1) / 2);
		}
	
	printf("%d\n", k);
	
	return 0;
}
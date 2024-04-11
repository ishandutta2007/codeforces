#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char map[305];
	bool flag = true;
	char ch1 = ' ', ch2 = ' ';
	for (int i = 0; i < n; ++i) {
		scanf("%s", map);
		if (i == 0) {
			ch1 = map[0];
			ch2 = map[1];
			flag = ch1 != ch2;
		}
		for (int j = 0; j < n; ++j) {
			if (i == j || i + j == n - 1) {
				flag = flag && map[j] == ch1;
			} else {
				flag = flag && map[j] == ch2;
			}
		}
	}
	puts(flag ? "YES" : "NO");
	return 0;
}
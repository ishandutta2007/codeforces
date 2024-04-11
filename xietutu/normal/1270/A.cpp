#include <bits/stdc++.h>
using namespace std;

int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		bool flag1 = false, flag2 = false;
		for (int i = 1; i <= a; ++ i) {
			int x; scanf("%d", &x);
			if (x == n) flag1 = true;
		}
		for (int i = 1; i <= b; ++ i) {
			int x; scanf("%d", &x);
			if (x == n) flag2 = true;
		}
		printf("%s\n", flag1 ? "YES" : "NO");
	}
	
	return 0;
}
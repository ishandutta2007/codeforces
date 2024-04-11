#include <bits/stdc++.h>
using namespace std;
int s, v1, v2, t1, t2;
int main() {
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int f1 = s * v1 + 2 * t1;
	int f2 = s * v2 + 2 * t2;
	if (f1 == f2) {
		printf("Friendship\n");
	} else if (f1 < f2) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}
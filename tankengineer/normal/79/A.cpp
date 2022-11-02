#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int choose[3][2] = {2, 2, 1, 12, 0, 22};

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	while (true) {
		int c1 = -1;
		for (int i = 0; i < 3; ++i) {
			if (a >= choose[i][0] && b >= choose[i][1]) {
				c1 = i;
				break;
			}
		}
		if (c1 == -1) {
			puts("Hanako");
			return 0;
		} 
		a -= choose[c1][0], b -= choose[c1][1];
		int c2 = -1;
		for (int i = 2; i >= 0; --i) {
			if (a >= choose[i][0] && b >= choose[i][1]) {
				c2 = i;
				break;
			}
		}
		if (c2 == -1) {
			puts("Ciel");
			return 0;
		}
		a -= choose[c2][0], b -= choose[c2][1];
	}
	return 0;
}
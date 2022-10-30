#include <bits/stdc++.h>
using namespace std;

char grid[10][10];

int main() {
	for (int i=0;i<8;i++) scanf(" %s",&grid[i]);
	int a = 100;
	int b = 100;
	for (int j=0;j<8;j++) {
		bool has = 0;
		for (int i=0;i<8;i++) {
			if (grid[i][j]=='W' && !has) a = min(a,i);
			if (grid[i][j]=='B') has = 1;
		}
		has = 0;
		for (int i=7;i>=0;i--) {
			if (grid[i][j]=='B' && !has) b = min(b,7-i);
			if (grid[i][j]=='W') has = 1;
		}
	}
	printf("%s\n",(a<=b) ? "A" : "B");

	return 0;
}
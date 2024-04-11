#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

char map[3][105];

bool isTrain(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < 3; ++i) {
			scanf("%s", map[i]);
		}
		bool up = map[0][0] == 's', mid = map[1][0] == 's', down = map[2][0] == 's', dead = false;
		int cur = 0;
		while (cur < n && !dead) {
			bool nup = false, nmid = false, ndown = false;
			if (isTrain(map[0][cur + 1])) {
				up = false;
			}
			if (isTrain(map[1][cur + 1])) {
				mid = false;
			}
			if (isTrain(map[2][cur + 1])) {
				down = false;
			}
			nup = up || mid;
			nmid = up || mid || down;
			ndown = mid || down;
			if (isTrain(map[0][cur + 1])) {
				nup = false;
			}
			if (isTrain(map[1][cur + 1])) {
				nmid = false;
			}
			if (isTrain(map[2][cur + 1])) {
				ndown = false;
			}
			if (isTrain(map[0][cur + 2]) || isTrain(map[0][cur + 3])) {
				nup = false;
			}
			if (isTrain(map[1][cur + 2]) || isTrain(map[1][cur + 3])) {
				nmid = false;
			}
			if (isTrain(map[2][cur + 2]) || isTrain(map[2][cur + 3])) {
				ndown = false;
			}
			up = nup, mid = nmid, down = ndown;
			dead = !(up || mid || down);
			cur += 3;
		}
		puts(dead ? "NO" : "YES");
	}
	return 0;
}
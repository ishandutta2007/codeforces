#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int pos[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
int n, b[11], v[11][2];
bool check(int st) {
	int x = pos[st][0], y = pos[st][1];
	for (int i = 1; i < n; ++i) {
		int xx = x + v[i][0], yy = y + v[i][1];
		if (xx >= 0 && xx < 3) {
			if (!(yy >= 0 && yy <= 2)) return false;
		}
		else if (!(xx == 3 && yy == 1)) return false;
		x = xx; y = yy;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	char s[12];
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		b[i] = s[i] - '0';
	for (int i = 1; i < n; ++i)
		v[i][0] = pos[b[i]][0] - pos[b[i - 1]][0],
		v[i][1] = pos[b[i]][1] - pos[b[i - 1]][1];
	bool flag = true;
	for (int i = 0; i < 10; ++i)
		if (check(i) && i != b[0]) flag = false;
	if (flag) printf("YES\n");
	else printf("NO\n");
}
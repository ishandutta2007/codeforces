#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int c[3];
	scanf("%d %d %d", &c[0], &c[1], &c[2]);
	sort(c, c + 3);
	int ts = c[0];
	int a = c[1] - c[0];
	int b = c[2] - c[0];
	int mn = min(a, b / 2);
	ts += mn;
	a -= mn;
	if(a)
		ts += (a + (b & 1)) / 3;
	else
		ts += min((b - mn * 2) / 3, c[0]);
	printf("%d\n", ts);
	return 0;
}
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int a, ta, b, tb, ans = 0;
	scanf("%d%d%d%d", &a, &ta, &b, &tb);
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	int sstart = hh * 60 + mm, send = sstart + ta;
	for (int t = 5 * 60 + 0; t <= 23 * 60 + 59; t += b) {
		int tstart = t, tend = tstart + tb;
		if (max(sstart, tstart) < min(send, tend)) {
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
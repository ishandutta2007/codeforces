#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int h, m, a;
int main() {
	scanf("%d:%d", &h, &m);
	scanf("%d", &a);
	int t = h * 60 + m;
	t += a; t %= (24 * 60);
	printf("%02d:%02d\n", t / 60, t % 60);
}
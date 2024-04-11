#include <cstdio>
#include <algorithm>	
typedef long long ll;
int A,B,n,l,t,m;
bool check(int x) {
	return 1LL * (A + 1LL * (l - 1) * B + A + 1LL * (x - 1) * B) * (x - l + 1) / 2 <= 1LL * t * m;
}
void work() {
	scanf("%d%d%d", &l, &t, &m);
	ll min = A + 1LL * (l - 1) * B;
	if (min > t) {
		printf("-1\n");
		return;
	}
	int r1 = (t - A) / B + 1;
	int ll = l - 1,rr = 1000001;
	while (ll + 1 < rr) {
		int mid = (ll + rr) / 2;
		if (check(mid)) ll = mid;
		else rr = mid;
	}
	int r2 = std::max(l, ll);
	printf("%d\n",std::min(r1,r2));
}
int main() {
	scanf("%d%d%d",&A,&B,&n);
	for (int i = 1; i <= n; ++i) work();
}
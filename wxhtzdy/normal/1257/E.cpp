#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int k1, k2, k3, a[200005], cl[5], cr[5];

int main()
{
	scanf("%d%d%d", &k1, &k2, &k3);
	rep(i, k1) { int id; scanf("%d", &id); a[id] = 1; }
	rep(i, k2) { int id; scanf("%d", &id); a[id] = 2; }
	rep(i, k3) { int id; scanf("%d", &id); a[id] = 3; }
	int ans = 0;
	rep1(i, k1 + k2 + k3) { cr[a[i]] ++; if(a[i] != 3) ans ++; }
	int d = 0;
	rep1(i, k1 + k2 + k3) {
		cl[a[i]] ++; cr[a[i]] --;
		d = max(d, cl[1] - cl[2]);
		ans = min(ans, cr[1] + cr[2] + cl[3] + cl[1] - d);
	}
	printf("%d\n", ans);
	return 0;
}
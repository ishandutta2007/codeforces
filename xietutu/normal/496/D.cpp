#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 100005;
int n,l,r,tot,v[maxn],a[maxn],b[maxn];
struct arr {
	int t,s;
} ans[maxn];
bool operator<(const arr& lhs,const arr& rhs) {
	return lhs.s < rhs.s || (lhs.s == rhs.s && lhs.t < rhs.t);
}
int main() {
	scanf("%d",&n);
	l = 0; r = 0;
	memset(a,63,sizeof(a));
	memset(b,63,sizeof(b));
	for (int i = 1; i <= n; ++i) { 
		scanf("%d",v + i);
		if (v[i] == 1) a[++l] = i;
		if (v[i] == 2) b[++r] = i;
	}
	for (int t = 1; t <= n; ++t) {
		int last1 = 0, last2 = 0, s1 = 0, s2 = 0;
		while (last1 + t <= l || last2 + t <= r) {
			if (a[last1 + t] < b[last2 + t]) {
				last2 = a[last1 + t] - (last1 + t);
				last1 = last1 + t;
				++s1;
			}
			else {
				last1 = b[last2 + t] - (last2 + t);
				last2 = last2 + t;
				++s2;
			}
			if (last1 == n || last2 == n) break;
		}
		if (last1 == l || last2 == r) {
			if (last1 == l && v[n] == 1 && s1 > s2) {
				++tot; ans[tot].t = t; ans[tot].s = s1;
			}
			if (last2 == r && v[n] == 2 && s2 > s1) {
				++tot; ans[tot].t = t; ans[tot].s = s2;
			}
		}
	}
	std::sort(ans + 1,ans + tot + 1);
	printf("%d\n",tot);
	for (int i = 1; i <= tot; ++i)
		printf("%d %d\n",ans[i].s,ans[i].t);
}
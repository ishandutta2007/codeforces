#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int maxn = 100005;
int n,r,avg,need;
ll tot,s;
struct arr {
	int a,b;
} v[maxn];
bool operator<(const arr& lhs,const arr& rhs) {
	return lhs.b < rhs.b;
}
int main() {
	scanf("%d%d%d",&n,&r,&avg);
	tot = static_cast<long long>(n) * avg;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d",&v[i].a,&v[i].b);
		tot -= v[i].a;
	}
	if (tot <= 0) printf("0\n");
	else {
		std::sort(v + 1,v + n + 1);
		for (int i = 1; i <= n; ++i) {
			ll t = r - v[i].a;
			if (t > tot) t = tot;
			s = s + t * v[i].b;
			tot -= t;
			if (tot == 0) break;
		}
		printf("%I64d\n",s);
	}
}
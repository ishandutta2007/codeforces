#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 100005;
typedef long long ll;
const ll M = 100000;
ll sum[maxn];
int v[maxn],x[maxn],type[maxn],f[maxn],c[maxn],n,m;
void makesq() {
	int tot = 0;
	for (int i = 1; i <= m; ++i) {
		if (tot >= M) return;
		if (type[i] == 1) v[++tot] = x[i];
		else {
			for (int j = 1; j <= c[i]; ++j) {
				for (int k = 1; k <= f[i]; ++k) { 
					v[++tot] = v[k];
					if (tot >= M) return;
				}
			}
		}
	}
} 
int main() {

	scanf("%d",&m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&type[i]);
		if (type[i] == 1) 
			scanf("%d",x + i),sum[i] = 1;
		else {
			scanf("%d%d",&f[i],&c[i]);
			sum[i] = f[i] * c[i];
		}
	}
	for (int i = 1; i <= m; ++i) sum[i] += sum[i - 1];
	makesq();
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		ll t; scanf("%I64d",&t);
		if (t <= M) printf("%d ",v[t]);
		else {
			int l = 1,r = m;
			while (l + 1 < r) {
				int mid = (l + r) / 2;
				if (sum[mid] >= t) r  = mid;
				else l = mid;
			}
			if (type[r] == 1) printf("%d ",x[r]);
			else {
				t -= sum[r - 1];
				if (t % f[r] == 0) t = f[r];
				else t -= t / f[r] * f[r];
				printf("%d ",v[t]);
			}
		}
	}

}
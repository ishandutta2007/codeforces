#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1000005, seed = 197, M = 1000000007;
char s[maxn];
typedef long long ll;
ll ans, pre[maxn], suf[maxn];
int p,n,m,x[maxn];
bool can;
int Pow(int a,int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = static_cast<long long>(s) * a % M;
		b = b / 2;
		a = static_cast<long long>(a) * a % M;
	}
	return s;
}
void prepare() {
	ll now = 0;
	for (int i = 1; i <= p; ++i) {
		now = (now * seed + s[i] - 'a') % M;
		pre[i] = now;	
	}
	
	now = 0; ll base = 1;
	for (int i = p; i >= 1; --i) {
		now = (now + (s[i] - 'a') * base) % M;
		suf[i] = now;
		base = base * seed % M;
	}
	for (int i = 1; i <= m; ++i) scanf("%d",x + i);
	for (int i = 2; i <= m; ++i) 
		if (x[i] - x[i - 1] < p) {
			int d = x[i] - x[i - 1];
			if (pre[p - d] != suf[d + 1]) {
				can = false; break;
			}
		}
}
void work() {
	if (!can) {
		printf("0\n");
		return;
	}
	if (!m) {
		printf("%d\n",Pow(26,n));
		return;
	}
	x[m + 1] = n + 1;
	int now = x[1] - 1;
	for (int i = 2; i <= m + 1; ++i)
		if (x[i] - x[i - 1] > p)
			now += x[i] - x[i - 1] - p;
	printf("%d\n",Pow(26,now));
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",s + 1);
	p = strlen(s + 1);
	can = true;
	prepare();
	work();
}
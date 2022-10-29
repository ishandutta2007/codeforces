#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
const int maxn = 100005,M = 1000000007;
char a[maxn],b[maxn];
int n,m,P[maxn],last[maxn];
long long summ[maxn],f[maxn],sum[maxn];
bool can[maxn];
void prepare() {
	n = strlen(a + 1);
	m = strlen(b + 1);
	int j = 0;
	for (int i = 2; i <= m; ++i) {
		while (j > 0 && b[j + 1] != b[i]) j = P[j];
		if (b[j + 1] == b[i]) ++j;
		P[i] = j;
	}
	
	j = 0;
	for (int i = 1; i <= n; ++i) {
		while (j > 0 && b[j + 1] != a[i]) j = P[j];
		if (b[j + 1] == a[i]) ++j;
		if (j == m) {
			can[i] = true;
			j = P[j];
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (can[i]) last[i] = i;
		else last[i] = last[i - 1];
	}
}
void dp() {
	int first = 0;
	for (int i = 1; i <= n; ++i) 
		if (can[i]) {
			first = i;
			break;
		}
	if (!first) {
		printf("0\n"); return;
	}
	f[first] = sum[first] = first - m + 1;
	summ[first] = f[first] * first % M;
	for (int i = first + 1; i <= n; ++i) {
		int pos = last[i] - m;
		f[i] = (sum[pos] * (pos + 1) % M - summ[pos] + pos + 1 + M) % M;
		//printf("%d\n",f[i]);
		sum[i] = (sum[i - 1] + f[i]) % M;
		summ[i] = (summ[i - 1] + f[i] * i % M) % M;
	}
	//for (int i = 1; i <= n; ++i) printf("%d\n",f[i]);
	printf("%d\n",sum[n]);
}
int main() {
	scanf("%s%s",a + 1,b + 1);
	prepare();
	dp();
}
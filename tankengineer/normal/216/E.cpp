#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

const int N = 100005;

int k, b, n, s[N], t1, t2; 
long long zero, ans, sum, cnt;
map<int, int> tr;

int main() {
	scanf("%d %d %d", &k, &b, &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
	t1 = 1;
	while (t1 <= n) {
	  if (s[t1] == 0) {
		  t2 = t1;
		  while (t2 < n && s[t2 + 1] == 0) ++t2;
		  zero += (long long)(t2 - t1 + 2) * (t2 - t1 + 1) / 2;
		  t1 = t2;
		}
		++t1;
	}
	if (b == 0) {
	  ans = zero;
	} else {
	  if (b == k - 1) {
		  b = 0;
		  ans = -zero;
		}
		tr.insert(make_pair(0, 1));
		sum = 0;
		for (int i = 1; i <= n; ++i) {
		  sum += s[i];
		  sum %= k - 1;
		  cnt = 0;
		  if (tr.count(b - sum)) cnt += tr[b - sum];
		  if (tr.count(b + k - 1 - sum)) cnt += tr[b + k - 1 - sum];
		  ans += cnt;
		  if (sum == 0) sum = k - 1;
		  if (tr.count(k - 1 - sum)) tr[k - 1 - sum]++; else tr.insert(make_pair(k - 1 - sum, 1));
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
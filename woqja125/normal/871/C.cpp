#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;
vector<int> x, y;
int in[100001][2];
int p[200001];
int c[200001];
int s[200001];
int chk[200001];
int R(int x) {
	if (x == p[x]) return x;
	else return p[x] = R(p[x]);
}
void uni(int x, int y) {
	x = R(x); y = R(y);
	if (x == y) {
		c[y]++;
	}
	else {
		c[y] += c[x] + 1;
		p[x] = y;
		s[y] += s[x];
	}
}
int tp[200010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &in[i][0], &in[i][1]);
		x.push_back(in[i][0]);
		y.push_back(in[i][1]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	int N = x.size() + y.size();
	for (int i = 0; i < N; i++) p[i] = i, s[i] = 1;

	for (int i = 1; i <= n; i++) {
		uni(lower_bound(x.begin(), x.end(), in[i][0]) - x.begin(), 
			lower_bound(y.begin(), y.end(), in[i][1]) - y.begin() + x.size());
	}
	tp[0] = 1;
	for (int i = 1; i <= N; i++) tp[i] = tp[i - 1] * 2 % MOD;
	long long ans = 1, t = 0;
	for (int i = 0; i < N; i++) {
		if (p[i] != i) continue;
		t = tp[s[i]];
		if (s[i] - 1 == c[i]) t = (t + MOD - 1) % MOD;
		ans = ans * t % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
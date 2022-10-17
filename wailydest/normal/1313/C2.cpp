#include <cstdio>
#include <map>
using namespace std;

const int N = 500000;

int a[N], rev[N];
int dp[N], dprev[N];
long long dp2[N], dprev2[N];
int n;

void get(int *a, int *dp, int n) 
{
	map<int, int> m;
	map<int, int>::iterator it;
	for (int i = 0; i < n; ++i) {
		if (m.count(a[i])) {
			it = m.find(a[i]);
			dp[i] = it->second;
			it->second = i;
			while (next(it) != m.end()) m.erase(next(it));

		}
		else {
			it = m.insert(make_pair(a[i], i)).first;
			if (it == m.begin()) dp[i] = -1;
			else dp[i] = prev(it)->second;
			while (next(it) != m.end()) m.erase(next(it));
		}
	}
}
void get2(int *a, long long *dp2, int *dp, int n) 
{
	for (int i = 0; i < n; ++i) {
		dp2[i] = (long long)a[i] * (i - dp[i]) + (dp[i] != -1 ? dp2[dp[i]] : 0);
	}
}
inline long long ansi(int i) { return dp2[i] + dprev2[n - i - 1] - a[i]; }

int ans[N];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		rev[n - i - 1] = a[i];
	}
	get(a, dp, n);
	get(rev, dprev, n);
	get2(a, dp2, dp, n);
	get2(rev, dprev2, dprev, n);
	int ind = 0;
	for (int i = 1; i < n; ++i) if (ansi(i) > ansi(ind)) ind = i;
	ans[ind] = a[ind];
	for (int i = ind - 1; i >= 0; --i) ans[i] = min(a[i], ans[i + 1]);
	for (int i = ind + 1; i < n; ++i) ans[i] = min(a[i], ans[i - 1]);
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
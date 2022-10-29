#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
#include <map> 
typedef long long ll;
using namespace std;
ll sum,S,p[30],a[30],b[30];
bool can[30];
int n,m,k,now;
long long ans;
map<pair<int,ll>,int> M;
void dfs(int step) {
	if (sum > S) return;
	if (step == m + 1) {
		++M[make_pair(now,sum)];
		return;
	}
	dfs(step + 1);
	sum = sum + a[step];
	dfs(step + 1);
	sum = sum - a[step];
	if (can[step] && now < k) {
		++now;
		sum = sum + b[step];
		dfs(step + 1);
		--now;
		sum = sum - b[step];
	}
}
void dfs2(int step) {
	if (sum > S) return;
	if (step == n + 1) {
		for (int i = k - now; i >= 0; --i)
			ans += M[make_pair(i, S - sum)];
		return;
	}
	dfs2(step + 1);
	sum = sum + a[step];
	dfs2(step + 1);
	sum = sum - a[step];
	if (can[step] && now < k) {
		++now;
		sum = sum + b[step];
		dfs2(step + 1);
		--now;
		sum = sum - b[step];
	}
}
int main() {
	cin >> n >> k >> S;
	p[0] = 1;
	for (int i = 1; i <= 19; ++i) p[i] = p[i - 1] * i;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) 
		if (a[i] <= 19 && p[a[i]] <= S) {
			can[i] = true;
			b[i] = p[a[i]];
		}
	m = n - n / 2; 
	dfs(1);	
	dfs2(m + 1);
	printf("%I64d\n",ans);
}
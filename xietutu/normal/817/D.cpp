#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
typedef long long LL;
typedef pair<LL, LL> pLL;
int n, a[maxn];
pLL Q[maxn];
int dcmp(LL x) { return (x > 0) - (x < 0);} 
LL solve(int p) {
	LL ret = 0, sum = 0;
	int t = 0;
	for (int i = 1; i <= n; ++i) {
		while (t > 0 && dcmp(a[i] - Q[t].first) * p >= 0) {
			sum -= (Q[t].second - Q[t - 1].second) * Q[t].first; 
			--t;
		}
		
		Q[++t] = pLL(a[i], i);
		sum += (Q[t].second - Q[t - 1].second) * Q[t].first;
		ret += sum;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	
	LL ans = solve(1) - solve(-1);	
	cout << ans << endl;
}
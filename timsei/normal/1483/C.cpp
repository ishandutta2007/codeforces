#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int Lg = 21;

multiset < long long > S;

int h[N], val[N], n, stk[N], top, Log[N];
long long dp[N], st[N][Lg];

void Set(int x) {
	st[x][0] = dp[x];
	for(int i = 1; i < 20; ++ i) {
		st[x][i] = 
		max(st[x][i - 1], st[max(0, x - (1 << (i - 1)))][i - 1]);
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &h[i]);
	for(int i = 2; i <= n; ++ i) Log[i] = Log[i >> 1] + 1;
	h[n + 1] = n + 1;
	stk[0] = -1;
	for(int i = 1; i <= n; ++ i)
	scanf("%d", &val[i]);
	for(int i = 1; i <= n + 1; ++ i) {
		dp[i] = ((S.size()) ? *S.rbegin() : 0) + val[i];
		while(top && h[stk[top]] > h[i]) S.erase(S.find(dp[stk[top]])), -- top;
		int lst = stk[top];
		stk[++ top] = i;
		// [lst + 1, i - 1]
		if(i <= lst + 1); else {
			int now = Log[i - lst - 1];
			dp[i] = max(dp[i], val[i] + max(st[lst + (1 << now)][now], st[i - 1][now]));
		}
		Set(i);
		S.insert(dp[i]);
	}
	cout << dp[n + 1] << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
int n, m, l[105], a[105], vis[105];
bool flag = true;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> l[i];
	}
	
	memset(vis, 0, sizeof vis);
	memset(a, 255, sizeof a);
	for (int i = 1; i < m; ++i) {
		int t = (l[i + 1] - l[i] + n) % n;
		int now = l[i];
		if (a[now] == -1) {
			if (vis[t]) {
				flag = false; break;
			}
			vis[t] = 1;
			
			a[now] = t;
		}
		else if (t != a[now]) flag = false;
	}
	
	if (!flag) puts("-1");
	else {
		for (int i = 1, j = 0; i <= n; ++i)
			if (a[i] == -1) {
				while (vis[j]) ++j;
				a[i] = j++;
			}
		for (int i = 1; i <= n; ++i)
			printf("%d ", a[i] == 0 ? n : a[i]);
	}
}
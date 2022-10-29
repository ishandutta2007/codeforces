#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
const int maxn = 5005;
int n, t[maxn], cnt[maxn], ans[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", t + i);
	}
	
	for (int i = 1; i <= n; ++i) {
		memset(cnt, 0, sizeof cnt);
		int maxv = 0, color = 0;
		for (int j = i; j <= n; ++j) {
			++cnt[t[j]];
			if (cnt[t[j]] > maxv || (cnt[t[j]] == maxv && t[j] < color)) {
				color = t[j]; 
				maxv = cnt[t[j]];
			}
			++ans[color];
		}
	}
	
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
}
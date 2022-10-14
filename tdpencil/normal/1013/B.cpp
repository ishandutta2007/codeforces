#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
#define pb push_back
int a[100000];

void go() {
	int n, k; scanf("%d%d", &n, &k);
	map<int, int> cnt, mcnt;
	int ans = INF;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a+n, greater<>());
	
	for(int i = 0; i < n; i++) {
		
		
		if(cnt[a[i]]) {
			ans = min(0, ans);
		} else if(mcnt[a[i]]) {
			ans = min(1, ans);
		} else if(mcnt[a[i]&k]) {
			ans = min(2, ans);
		}
		
		++cnt[a[i]];
		++mcnt[a[i]&k];
		
	}
	
	if(ans == INF) puts("-1");
	else printf("%d", ans);
}

int main() {
	int t = 1; // scanf("%d", &t);
	while(t--) go();
}
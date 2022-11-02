#include <bits/stdc++.h>

const int N = 2000;

int query(int l1, int r1, int l2, int r2) {
	printf("? %d %d\n", r1 - l1 + 1, r2 - l2 + 1);
	for(int i=l1;i<=r1;i++) printf("%d ", i); puts("");
	for(int i=l2;i<=r2;i++) printf("%d ", i); puts("");
	fflush(stdout);
	
	int ret; scanf("%d", &ret); return ret;
}

bool vis[N + 5];
void solve() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) vis[i] = false;
	
	int pos = -1;
	for(int i=1;i<n;i++) if( query(1, i, i + 1, i + 1) ) {
		pos = i + 1; break;
	}
	vis[pos] = true;
	
	for(int i=pos+1;i<=n;i++) if( query(pos, pos, i, i) )
		vis[i] = true;
	int l = 1, r = pos - 1;
	while( l < r ) {
		int m = (l + r) >> 1;
		if( query(1, m, pos, pos) ) r = m;
		else l = m + 1;
	}
	vis[r] = true;
	
	std::vector<int>v;
	for(int i=1;i<=n;i++) if( !vis[i] ) v.push_back(i);
	printf("! %d ", (int)v.size()); for(auto x : v) printf("%d ", x); puts("");
	fflush(stdout);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
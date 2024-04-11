#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n, A[N], B[N], vis[N], tot, ans, where[N], ok[N], D[N];

int dfs(int i) {
	if(vis[i]) return ok[i];
	vis[i] = 1;
	int now = dfs(where[B[i]]);
	if(now == -1) return -1;
	if(!now || !ok[i])
	return ok[i] + now;
	else {
		if(now == ok[i]) return now;
		else return -1;
	}
}

void rmain() {
	scanf("%d", &n); tot = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), where[A[i]] = i;
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]), vis[i] = 0;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &D[i]);
		ok[i] = (A[i] == B[i]);
		if(D[i] == A[i] && D[i] == B[i]) {
			ok[i] = 1;
		} else if(D[i] == A[i]) ok[i] = 1;
		else if(D[i] == B[i]) ok[i] = 2;
	}
	
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i]) {
			int now = dfs(i);
			if(now == -1) {
				puts("-1");
				return;
			} else {
				if(!now) ++ tot;
			}
		}
	}
	int ans = 1;
	for(int i = 1; i <= tot; ++ i){
		ans = (ans * 2) % mod;
	}
	cout << ans << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}
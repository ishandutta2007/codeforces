#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N], a[N], b[N], ans[N], P[N];
int t, k, n, found;

bool vis[N][2][2], used[35];

void dfs(int x, bool A, bool B) {
	if(vis[x][A][B]) return;
	vis[x][A][B] = 1;
	if(found) return;
	if(x == n + 1) {
		found = 1;
		puts("YES");
		vector <int> Al; Al.clear();
		for(int i = 1; i <= k; ++ i) if(!used[i]) Al.push_back(i);
		for(int i = 1; i <= k; ++ i) {
			if(!ans[i]) ans[i] = Al.back(), Al.pop_back();
		}
		for(int i = 1; i <= k; ++ i) putchar(ans[i] + 'a' - 1);
		puts("");
		return;
	}
	int L = 1, R = k;
	if(A) L = a[x];
	if(B) R = b[x];
	if(ans[s[x]]) {
		if(ans[s[x]] < L || ans[s[x]] > R) return;
		else dfs(x + 1, A && (ans[s[x]] == L), B && (ans[s[x]] == R));
	}
	else {
		for(int i = L; i <= R; ++ i) {
			if(!used[i]) {
				ans[s[x]] = i;
				used[i] = 1;
				dfs(x + 1, A && (ans[s[x]] == L), B && (ans[s[x]] == R));
				ans[s[x]] = 0;
				used[i] = 0;
			}
		}
	}
}

int main() {
	for(cin >> t; t --;) {
		scanf("%d", &k);
		scanf("%s", s + 1);
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		n = strlen(s + 1);
		for(int i = 1; i <= n; ++ i) s[i] -= 'a' - 1;
		for(int i = 1; i <= n; ++ i) a[i] -= 'a' - 1;
		for(int i = 1; i <= n; ++ i) b[i] -= 'a' - 1;
		//for(int i = 1; i <= n; ++ i) {
			//cout << (int)s[i] <<" " << (int)a[i] <<" " << (int) b[i] << endl;
	//	}
		for(int i = 1; i <= n + 1; ++ i) {
			for(int a = 0; a < 2; ++ a) {
				for(int b = 0; b < 2; ++ b) vis[i][a][b] = 0;
			}
		}
		found = 0;
		memset(used, 0, sizeof(used));
		for(int i = 1; i <= k; ++ i) ans[i] = 0;
		dfs(1, 1, 1);
		if(!found)puts("NO");
	}
}
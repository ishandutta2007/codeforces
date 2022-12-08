#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int N = 5e6L + 11;

int nxt[N][5];
int cnt[N];

char s[N];

int ts[N];

int dfs(int p, char *s, int t) {
	if(!p) return 0;
	if(!*s) {
		if(ts[p] == t) return 0;
		ts[p] = t;
		return cnt[p];
	}
	int r = 0;
	if(*s != '?')
		r += dfs(nxt[p][*s - 'a'], s + 1, t);
	else {
		for(int i = 0; i < 5; i ++)
			r += dfs(nxt[p][i], s + 1, t);
		r += dfs(p, s + 1, t);
	}
	return r;
}

int main() {
	int n, m; cin >> n >> m;
	
	int c = 1;
	for(int i = 0; i < n; i ++) {
		scanf("%s", s);
		int p = 1, l = strlen(s);
		for(int j = 0; j < l; j ++) {
			if(!nxt[p][s[j] - 'a']) {
				nxt[p][s[j] - 'a'] = ++ c;
			}
			p = nxt[p][s[j] - 'a'];
		}
		cnt[p] ++;
	}
	
	for(int i = 0; i < m; i ++) {
		scanf("%s", s);
		printf("%d\n", dfs(1, s, i + 1));
	}
	
	return 0;
}
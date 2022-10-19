#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, ty[N], ch[N][2], m, ans[N], val[N];

char s[N];
int OK[N], fa[N];

#define lc ch[x][0]
#define rc ch[x][1]

void dfs(int x) {
	if(!x) return;
	if(ch[x][0]) dfs(ch[x][0]);
	if(ch[x][1]) dfs(ch[x][1]);
	if(ty[x] == 2) val[x] = val[lc] & val[rc];
	else if(ty[x] == 3) val[x] = val[lc] ^ val[rc];
	else if(ty[x] == 4) val[x] = val[lc] | val[rc];
	else if(ty[x] == 5) {
		val[x] = val[lc] ^ 1;
	}
	fa[lc] = x, fa[rc] = x;
}


int calc(int x) {
	if(ty[x] == 2) return val[lc] & val[rc];
	else if(ty[x] == 3) return val[lc] ^ val[rc];
	else if(ty[x] == 4) return val[lc] | val[rc];
	else if(ty[x] == 5) {
		return val[lc] ^ 1;
	}	
}

bool pd(int x) {
	int now = calc(fa[x]);
	val[x] ^= 1;
	int now2 = calc(fa[x]);
	val[x] ^= 1;
	if(now != now2) return 1;
	else return 0;
}

void dfs2(int x) {
	if(!x) return;
	OK[x] = pd(x);
	if(x == 1) OK[x] = 1;
	OK[x] &= OK[fa[x]];
	dfs2(lc);
	dfs2(rc);
}

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", s + 1);
		if(s[1] == 'I') {
			ty[i] = 1;
			scanf("%d", &val[i]);
		}
		else if(s[1] == 'A') {
			ty[i] = 2;
			scanf("%d%d", &ch[i][0], &ch[i][1]);
		}
		else if(s[1] == 'X') {
			ty[i] = 3;
			scanf("%d%d", &ch[i][0], &ch[i][1]);
		}
		else if(s[1] == 'O') {
			ty[i] = 4;
			scanf("%d%d", &ch[i][0], &ch[i][1]);			
		}
		else if(s[1] == 'N') {
			ty[i] = 5;
			scanf("%d", &ch[i][0]);
		}
	}
	OK[0] = 1;
	dfs(1);
	//for(int i = 1; i <= n; ++ i) cerr << val[i] << " ";
	//puts("");
	dfs2(1);
	for(int i = 1; i <= n; ++ i) if(!ch[i][0]) printf("%d", OK[i] ^ val[1]);
}
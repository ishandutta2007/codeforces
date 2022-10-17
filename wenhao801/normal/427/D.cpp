#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAXN = 100100;
struct SAM { int len, trans[26], slink, siz[2]; } t[MAXN << 1];
int top = 1, las = 1;
void extend (int c, int id) {
	if (t[las].trans[c]) {
		int rua = t[las].trans[c];
		if (t[rua].len == t[las].len + 1) { las = rua; return; }
		int cl = ++top; t[cl] = t[rua]; t[cl].siz[0] = t[cl].siz[1] = 0; t[cl].len = t[las].len + 1;
		for (int i = las; t[i].trans[c] == rua; i = t[i].slink) t[i].trans[c] = cl;
		t[rua].slink = cl; las = cl; return;
	}
	int now = ++top, i; t[now].len = t[las].len + 1;
	for (i = las; !t[i].trans[c]; i = t[i].slink) t[i].trans[c] = now;
	las = now;
	if (!i) { t[now].slink = 1; return; }
	int rua = t[i].trans[c];
	if (t[rua].len == t[i].len + 1) { t[now].slink = rua; return; }
	int cl = ++top; t[cl] = t[rua]; t[cl].siz[0] = t[cl].siz[1] = 0; t[cl].len = t[i].len + 1;
	for (i; t[i].trans[c] == rua; i = t[i].slink) t[i].trans[c] = cl;
	t[rua].slink = t[now].slink = cl;
}
char s[MAXN];
vector <int> E[MAXN << 1];
void dfs (int x) {
	for (auto i: E[x]) dfs(i), t[x].siz[0] += t[i].siz[0], t[x].siz[1] += t[i].siz[1];
}

int main () {
	int i, j; scanf("%s", s); 
	for (i = 0, j = strlen(s); i < j; i++) extend(s[i] - 'a', 0), ++t[las].siz[0];
	las = 1; scanf("%s", s); j = strlen(s);
	for (i = 0, j = strlen(s); i < j; i++) extend(s[i] - 'a', 1), ++t[las].siz[1];
	for (i = 2; i <= top; i++) E[t[i].slink].push_back(i);
	dfs(1);
	int ans = 998244353;
	for (i = 2; i <= top; i++) if (t[i].siz[0] == 1 && t[i].siz[1] == 1) ans = min(ans, t[t[i].slink].len + 1);
	printf("%d\n", ans == 998244353 ? -1 : ans);
	return 0;
}
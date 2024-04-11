#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 200200;
char a[MAXN];
int n;

struct SAM {
	struct sam { int len, slink, trans[26], ep; }; sam t[MAXN];
	int top = 1, las = 1, nlen = 0;
    int slen[MAXN], fr[MAXN];
	void add (int c) {
		int tmp = ++top; t[tmp].len = t[las].len + 1, t[tmp].ep = ++nlen;
		int i, j;
		for (i = las; i && !t[i].trans[c]; i = t[i].slink) t[i].trans[c] = tmp;
		if (!i) t[tmp].slink = 1;
		else {
			int rua = t[i].trans[c];
			if (t[rua].len == t[i].len + 1) t[tmp].slink = rua;
			else {
				int cl = ++top; t[cl] = t[rua];
				t[cl].len = t[i].len + 1;
				for (j = i; t[j].trans[c] == rua; j = t[j].slink) t[j].trans[c] = cl;
				t[tmp].slink = t[rua].slink = cl;
			}
		}
		las = tmp;
	}
	void calc () {
		int len = 0, now = 1, i;
		for (i = 1; i <= n; i++) {
			int c = a[i] - 'a';
			while (now != 1 && !t[now].trans[c]) now = t[now].slink, len = t[now].len;
			if (t[now].trans[c]) ++len, now = t[now].trans[c];
            slen[i] = len; fr[i] = t[now].ep - len + 1;
		}
	}
} s, rs;

int dp[MAXN];
struct out { int fr, l, r; } ans[MAXN];

char tmp[MAXN];

void prt (int x) {
    if (!x) return;
    prt(ans[x].fr);
    printf("%d %d\n", ans[x].l, ans[x].r);
}

int main () {
	scanf("%s", tmp + 1);
    int i, j;
    int len = strlen(tmp + 1);
    for (i = 1; i <= len; i++) s.add(tmp[i] - 'a');
    for (i = len; i >= 1; i--) rs.add(tmp[i] - 'a');
    scanf("%s", a + 1); n = strlen(a + 1);
    s.calc(); rs.calc();
    for (i = 1; i <= n; i++) {
        dp[i] = 998244353;
        if (dp[i - s.slen[i]] + 1 < dp[i]) {
            dp[i] = dp[i - s.slen[i]] + 1;
            ans[i].fr = i - s.slen[i], ans[i].l = s.fr[i], ans[i].r = s.fr[i] + s.slen[i] - 1;
        }
        if (dp[i - rs.slen[i]] + 1 < dp[i]) {
            dp[i] = dp[i - rs.slen[i]] + 1;
            ans[i].fr = i - rs.slen[i], ans[i].l = len + 1 - rs.fr[i], ans[i].r = len + 2 - rs.fr[i] - rs.slen[i];
        }
    }
    if (dp[n] >= 998244353) puts("-1"); else printf("%d\n", dp[n]), prt(n);
	return 0;
}
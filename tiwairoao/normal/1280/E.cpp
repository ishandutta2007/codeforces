#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;

char get_char() {
	char ch = getchar();
	while( ch != '(' && ch != ')' && ch != '*' && ch != 'P' && ch != 'S' )
		ch = getchar();
	return ch;
}

int ch[2][MAXN + 5], clr[MAXN + 5], ncnt;
int a[MAXN + 5], cnt;
int get() {
	char c = get_char();
	if( c == '*' ) {
		a[++cnt] = (++ncnt), clr[ncnt] = -1;
		return ncnt;
	}
	else {
		int p = get(), q;
		c = get_char();
		if( c == 'S' ) {
			while( c == 'S' ) {
				q = (++ncnt), clr[q] = 0;
				ch[0][q] = p, ch[1][q] = get();
				c = get_char(), p = q;
			}
		}
		else {
			while( c == 'P' ) {
				q = (++ncnt), clr[q] = 1;
				ch[0][q] = p, ch[1][q] = get();
				c = get_char(), p = q;
			}
		}
		return p;
	}
}

int f[MAXN + 5];
int dfs1(int x) {
	if( clr[x] == -1 ) return f[x] = 0;
	else if( clr[x] == 0 ) return f[x] = min(dfs1(ch[0][x]), dfs1(ch[1][x]));
	else return f[x] = dfs1(ch[0][x]) + dfs1(ch[1][x]) + 1;
}

bool tg[MAXN + 5];
void dfs2(int x, bool t) {
	tg[x] = t;
	if( clr[x] == -1 ) return ;
	else if( clr[x] == 0 ) {
		if( f[ch[0][x]] < f[ch[1][x]] )
			dfs2(ch[0][x], t), dfs2(ch[1][x], false);
		else dfs2(ch[0][x], false), dfs2(ch[1][x], t);
	}
	else dfs2(ch[0][x], t), dfs2(ch[1][x], t);
}

void solve() {
	ncnt = cnt = 0;
	int R; scanf("%d", &R);
	int rt = get(), t = dfs1(rt);
	dfs2(rt, true);
	printf("REVOLTING");
	for(int i=1;i<=cnt;i++) {
		printf(" %lld", 1LL*tg[a[i]]*(t+1)*R);
	}
	puts("");
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
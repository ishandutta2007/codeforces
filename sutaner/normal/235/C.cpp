#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--) 
#define ll long long int 
#define pb push_back
#define maxr 500000
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 	2000020			// maximum number of nodes
#define maxsig 	26 				// size of character set 
using namespace std;

#define islower(ch) ('a' <= ch && ch <= 'z') 
#define isdigit(ch) ('0' <= ch && ch <= '9')
char buffer[maxr], *p1, *p2;
template<class T> void read(T& x){
	char ch = gc(); x = 0; while (!isdigit(ch)) ch = gc();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}
int reads(char* s){
	int l = 0; char ch = gc(); while (!islower(ch)) ch = gc();
	while (islower(ch)) s[l++] = ch, ch = gc(); s[l] = '\0'; return l;
}

namespace Suffix_Automaton{
	// indexed from 1 
	int mxl[maxn], go[maxn][maxsig], par[maxn], siz[maxn], last = 1, ct = 1;
	void extend(int ch) {
		int p = last, np = last = ++ct; mxl[np] = mxl[p] + 1, siz[np] = 1;
		while (p && !go[p][ch]) go[p][ch] = np, p = par[p];
		if (p) {
			int q = go[p][ch];
			if (mxl[q] == mxl[p] + 1) par[np] = q;
			else {
				int nq = ++ct;
				par[nq] = par[q], par[q] = par[np] = nq, mxl[nq] = mxl[p] + 1;
				srep(i, 0, maxsig) go[nq][i] = go[q][i];
				while (p && go[p][ch] == q) go[p][ch] = nq, p = par[p];
			}
		}else par[np] = 1;
	}
	vector<int> g[maxn];
	void dfs(int x){
		int si = g[x].size();
		srep(i, 0, si) { int op = g[x][i]; dfs(op); siz[x] += siz[op]; }
	}
	void update_parent_tree(){
		rep(i, 1, ct) g[par[i]].pb(i); dfs(1);
	} 
}using namespace Suffix_Automaton;

namespace Find_Cyclical_Isomorphic_Pattern_in_Text{
	int f[maxn];
	int getp(char* s, int n){
		f[0] = f[1] = 0;
		srep(i, 1, n) {
			int now = f[i];
			while (now && s[i] != s[now]) now = f[now];
			f[i + 1] = (s[i] == s[now]) ? (now + 1) : 0; 
		}
		return n - f[n];
	}
	char s[maxn], t[maxn];
	void test(){
		reads(s + 1); int T; read(T);
		int n = strlen(s + 1);
		rep(i, 1, n) extend(s[i] - 'a'); update_parent_tree();
		while (T--){
			reads(t + 1);
			int now = 1, ans = 0, m = strlen(t + 1);
			rep(i, 1, m) t[i + m] = t[i]; 
			int p = getp(t + 1, 2 * m), l = 0;
			rep(i, 1, m + p) {
				if (l == m && i > m) ans += siz[now]; 
				while (now && !go[now][t[i] - 'a']) now = par[now], l = mxl[now]; 
				now = go[now][t[i] - 'a'], l++;
				if (l == m + 1) { if (mxl[par[now]] == m) now = par[now]; l--; } 
			}
			printf("%d\n", ans);
		}
	}
}

int main(){ Find_Cyclical_Isomorphic_Pattern_in_Text :: test(); }
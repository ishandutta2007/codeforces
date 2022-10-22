/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define B 20
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int f[105][105], na[105][105], nb[105][105];
int main() {
	int n = read();
	ru(i, 0, 100) ru(j, 0, 100) if(i + j > 2) f[i][j] = 10000;
	ru(step, 1, 100) {
	ru(k, 3, B) ru(j, 0, k) {
		int i = k - j;
		ru(a, 0, i) ru(b, 0, j) {
			int res = max(f[a + b][i - a], f[i - a + j - b][a]) + 1;
			if(res < f[i][j]) {
				f[i][j] = res;
				na[i][j] = a, nb[i][j] = b;
			}
		}
		//if(step == 100) printf("%d %d %d %d %d %d %d\n", i, j, f[i][j], na[i][j], nb[i][j], f[na[i][j] + nb[i][j]][i - na[i][j]], f[i - na[i][j] + j - nb[i][j]][na[i][j]]);
	}
	}
	vector<int> a, b;
	ru(i, 1, n) a.push_back(i);
	ru(i, 1, 53) if(a.size() + b.size() > 2) {
		vector<int> nxta[2], nxtb[2];
		int rema = a.size() / 2, remb = (b.size() + 1) / 2;
		if(a.size() + b.size() <= B) {
			rema = na[a.size()][b.size()];
			remb = nb[a.size()][b.size()];
		}
		for (auto x: a) {
			if(rema) nxta[0].push_back(x), rema--;
			else nxta[1].push_back(x);
		}
		for (auto x: b) {
			if(remb) nxtb[0].push_back(x), remb--;
			else nxtb[1].push_back(x);
		}
		printf("? %d ", nxta[0].size() + nxtb[0].size());
		for (auto x: nxta[0]) printf("%d ", x);
		for (auto x: nxtb[0]) printf("%d ", x);
		printf("\n"); fflush(stdout);
		char s[5];
		scanf("%s", s);
		if(s[0] == 'N') swap(nxta[0], nxta[1]), swap(nxtb[0], nxtb[1]);
		a.clear(), b.clear();
		for (auto x: nxta[0]) a.push_back(x);
		for (auto x: nxta[1]) b.push_back(x);
		for (auto x: nxtb[0]) a.push_back(x);
	}
	for (auto x: b) a.push_back(x);
	for (auto x: a) {
		printf("! %d\n", x);
		fflush(stdout);
		char s[5];
		scanf("%s", s);
		if(s[1] == ')') return 0;
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define maxn 
#define maxb 40
using namespace std;

int n, m;
int g[maxb][maxb];
int num[maxb];
int dep(int x) {
	int cn = 0;
	while (x) {
		num[cn++] = x & 1;
		x >>= 1;
	}
	return cn;
}
void outans(){
	puts("YES");
	n = 32;
	rep(i, 1, 32) rep(j, i + 1, 32) if (g[i][j] > 0) m++;
	cout << n << ' ' << m << endl;
	rep(i, 1, 32) rep(j, i + 1, 32) if (g[i][j] > 0) cout << i << ' ' << j << ' ' << g[i][j] << endl;
	exit(0);
}
int main(){
	int L, R, st;
	cin >> L >> R;
	if (L > 1) {
		g[1][2] = L - 1;
		R -= (L - 1), L = 1;
		st = 2;
	}
	else st = 1;
	
	L--, R--;
	int x = R + 1, s = 0;
	while (x) {
		s++;
		x >>= 1;
	}
	s--;
	int ed = 32;
	int ptr = st + 2;
	g[st][ed] = 1;
	per(i, s - 1, 0) {
		g[st][ptr] = 1 << i;
		int _ptr = ptr - 1;
		rep(j, i + 1, s - 1) {
			g[_ptr][ptr] = 1 << i;
			_ptr--;
		}
		g[ptr][ed] = 1;
		ptr++;
	}
	if (R + 1 == (1 << s)) { 
		outans();
	}
	int off = st + 1;
	g[st][off] = 1;
	int le = dep(R + 1);
	int sum = 0;
	ptr = st + 1;
	per(i, le - 1, 0) {
		if (num[i] && sum) {
			g[off][ptr] = sum - 1;
		}
		sum += num[i] * (1 << i);
		ptr++;
	}
	//g[off][ed] = sum - 1;
	outans();
	return 0;
}
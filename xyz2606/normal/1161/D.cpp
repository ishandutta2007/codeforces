#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 222222;
int rela[N], delta[N];
int flag = false;
void getr(int x) {
	int p = x, sum = 0;
	while(p != rela[p]) {
		sum ^= delta[p];
		p = rela[p];
	}
	int p1 = p; p = x;
	while(p != rela[p]) {
		int p2 = rela[p];
		rela[p] = p1;
		sum ^= delta[p];
		delta[p] ^= sum;
		p = p2;
	}
}
void cnnt(int x, int y, int d) {
	//printf("cnnt %d %d %d\n", x, y, d);
	getr(x); getr(y);
	if(rela[x] == rela[y]) {
		if((delta[x] ^ delta[y] ^ d)) {
			flag = false;
			//printf("!!! %d %d %d %d %d\n", x, y, delta[x], delta[y],d);
		}
		return;
	}
	int x1 = rela[x];
	rela[x1] = rela[y];
	delta[x1] = delta[x] ^ delta[y] ^ d;
}
int main() {
	string s;
	cin >> s;
	int ans = 0;
	reverse(s.begin(), s.end());
	int n = s.length();
	for(int i(1); i < n; i++) {
		//cout << i << endl;
		flag = true;
		for(int j(1); j <= n * 2; j++) {
			rela[j] = j;
			delta[j] = 0;
		}
		cnnt(n, n * 2, 1);
		cnnt(n + i, n * 2, 1);
		for(int j(n + i + 1); j < n * 2; j++)
			cnnt(j, n * 2, 0);
		for(int j(1); j <= n; j++) {
			if(s[j - 1] != '?')
				cnnt(j, j + n, s[j - 1] - '0');
		}
		for(int j(1); j <= n; j++) 
			cnnt(j, n + 1 - j, 0);
		for(int j(1); j <= i; j++) 
			cnnt(n + j, n + i + 1 - j, 0);
		if(flag) {
			int tmp = 1, cnt = 0;
			for(int j(1); j <= n * 2; j++) if(rela[j] == j) {
				cnt++;
			}
			for(int j(1); j < cnt; j++) tmp = (tmp * 2) % mod;
			ans = (ans + tmp) % mod;
			//cout << '!' << cnt << endl;
		}
	}
	printf("%d\n", ans);
}
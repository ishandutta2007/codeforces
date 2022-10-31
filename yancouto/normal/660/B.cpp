#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int pos[200][4];
int n;

void nx_en(int &r, int &c) {
	if(c == 0) return (void)(c = 3);
	if(c == 1) return (void)(c = 2);
	if(c == 3) {
		c = 0; r++;
		if(r == n) r = 0, c = 1;
	} else {
		c = 1; r++;
		if(r == n) r = c = -1;
	}
}

void nx_ex(int &r, int &c) {
	if(c == 1) return (void)(c = 0);
	if(c == 0) return (void)(c = 2);
	if(c == 2) return (void)(c = 3);
	c = 1; r++;
	if(r == n) c = r = -1;
}

int main() {
	int i, m, r, c;
	scanf("%d %d", &n, &m);
	r = 0, c = 0;
	for(i = 0; i < m; i++) {
		pos[r][c] = i + 1;
		nx_en(r, c);
	}
	r = 0; c = 1;
	while(r != -1) {
		if(pos[r][c]) printf("%d ", pos[r][c]);
		nx_ex(r, c);
	}
	putchar('\n');
}
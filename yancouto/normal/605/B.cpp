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
const int N = 100009;
pii e[N];
pii es[N];

void imp() {
	puts("-1");
	exit(0);
}

int q[N];
int nx[N];
int vx = 0;
int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &e[i].fst, &e[i].snd);
		e[i].snd = -e[i].snd;
		q[i] = i;
	}
	sort(q, q + m, [](int i, int j) { return e[i] < e[j]; });
	int got = 1;
	nx[0] = 1;
	for(i = 0; i < m; i++) {
		int j = q[i];
		if(e[j].snd) {
			int u = got - 1;
			es[j] = pii(u, got);
			nx[got] = got + 1;
			nx[u] = got + 1;
			vx = 0;
			got++;
		} else {
			while(vx < got && nx[vx] >= got) vx++;
			if(vx == got) imp();
			es[j] = pii(vx, nx[vx]);
			nx[vx]++;
		}
	}
	for(i = 0; i < m; i++)
		printf("%d %d\n", es[i].fst + 1, es[i].snd + 1);
}
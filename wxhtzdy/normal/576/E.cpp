#include <bits/stdc++.h>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 5e5 + 500;
const int M = 55;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

inline int add(int A, int B) {if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) {if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

struct DSU{
	int sz[N], par[N], put[N];
	bool bip;
	DSU(){
		bip = true;
		for(int i = 0;i < N;i++){
			sz[i] = 1;
			par[i] = i;
			put[i] = 0;
		}
	}
	int predak(int x){
		// odakle sam ja?
		if(par[x] == x) return x;
		else return predak(par[x]);
	}
	int path(int x){
		if(par[x] == x) return 0;
		else return put[x] ^ path(par[x]);
	}
	struct op{
		int x, y, a, b;
		bool bio;
	};
	stack < op > stek;
	void spoji(int x, int y){
		int a = x;
		int b = y;
		x = predak(x);
		y = predak(y);
		stek.push({x, y, sz[x], sz[y], bip});
		if(x == y){
			if(path(a) == path(b)) bip = false;
			return;
		}
		if(sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		par[y] = x;
		put[y] = 1 ^ path(a) ^ path(b);
	}
	void roll(){
		op curr = stek.top();
		par[curr.x] = curr.x;
		par[curr.y] = curr.y;
		put[curr.x] = 0;
		put[curr.y] = 0;
		sz[curr.x] = curr.a;
		sz[curr.y] = curr.b;
		bip = curr.bio;
		stek.pop();
	}
} d[M];

int n, m, k, q, x[N], y[N], id[N], col[N], boja[N];
int lst[N], nxt[N];

// smorcina

vector < pii > qq[4 * N];

void ubaci(int i, int lo, int hi, int a, int b, pii sta){
	if(a <= lo && hi <= b){
		qq[i].PB(sta); return;
	}
	if(lo > hi || lo > b || hi < a) return;
	ubaci(i * 2, lo, (lo + hi) / 2, a, b, sta);
	ubaci(i * 2 + 1, (lo + hi) / 2 + 1, hi, a, b, sta);
}

void resi(int i, int l, int r){
	for(auto kvr: qq[i]){
		d[kvr.Y].spoji(x[kvr.X], y[kvr.X]);
	}
	if(l == r){
		if(d[col[l]].predak(x[id[l]]) != d[col[l]].predak(y[id[l]]) || d[col[l]].path(x[id[l]]) != d[col[l]].path(y[id[l]])){
			printf("YES\n");
			ubaci(1, 1, q, l + 1, nxt[l] - 1, {id[l], col[l]});
			boja[id[l]] = col[l];
		}
		else{
			printf("NO\n");
			if(boja[id[l]] != 0){
				ubaci(1, 1, q, l + 1, nxt[l] - 1, {id[l], boja[id[l]]});
			}
		}
	}
	else{
		resi(i * 2, l, (l + r) / 2);
		resi(i * 2 + 1, (l + r) / 2 + 1, r);
	}
	for(auto kvr: qq[i]){
		d[kvr.Y].roll();
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", x + i, y + i);
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d", id + i, col + i);
		nxt[i] = q + 1;
	}
	for(int i = 1;i <= q;i++){
		nxt[lst[id[i]]] = i;
		lst[id[i]] = i;
	}
	resi(1, 1, q);
	return 0;
}
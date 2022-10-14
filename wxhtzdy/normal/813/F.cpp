#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define X first
#define Y second

typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int M = 4e5 + 500;

int n, q;
vector < pii > koj[M];
map < pii, vector < int > > edg;

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
} d;

void dodaj(int i, int a, int b, int lo, int hi, pii x){
	if(lo <= a && b <= hi){
		koj[i].PB(x); return;
	}
	if(a > b || hi < a || lo > b) return;
	dodaj(i * 2, a, (a + b) / 2, lo, hi, x);
	dodaj(i * 2 + 1, (a + b) / 2 + 1, b, lo, hi, x);
}

void solve(int i, int x, int y){
	if(x > y) return;
	for(auto c : koj[i]){
		d.spoji(c.first, c.second);
		//printf("%d %d %d %d\n", x, y, c.first, c.second);
	}
	if(x == y){
		//printf("%d\n", x);
		if(d.bip) printf("YES\n");
		else printf("NO\n");
		for(auto c : koj[i]){
			d.roll();
		}
		return;
	}
	solve(i * 2, x, (x + y) / 2);
	solve(i * 2 + 1, (x + y) / 2 + 1, y);
	for(auto c : koj[i]){
		d.roll();
	}
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < q;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		edg[{x, y}].PB(i);
	}
	for(auto c : edg){
		for(int i = 0;i < c.Y.size() - 1;i += 2){
			dodaj(1, 0, q - 1, c.Y[i], c.Y[i + 1] - 1, c.X);
		}
		if((int) c.Y.size() % 2 == 1){
			dodaj(1, 0, q - 1, c.Y.back(), q - 1, c.X);
		}
	}
	solve(1, 0, q - 1);
	return 0;
}
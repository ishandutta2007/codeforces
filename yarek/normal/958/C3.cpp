#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e5 + 7;
const int T = 1 << 7;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k, p;
int tab[N];
int tree[T][T + T + 7];

void update(int t, int x, int v){
	x += T;
	tree[t][x] = v;
	
	while(x > 1){
		x >>= 1;
		tree[t][x] = min(tree[t][x + x], tree[t][x + x + 1]);
	}
}

int ask(int t, int p, int k){
	int res = MX;
	p += T, k += T;

	while(p < k){
		if(p & 1)
			res = min(tree[t][p], res);
		if(!(k & 1))
			res = min(tree[t][k], res);
		
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k)
		res = min(tree[t][p], res);
	return res;
}

int main(){
	scanf("%d %d %d", &n, &k, &p);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &tab[i]),
		tab[i] %= p;
	
	for(int i = 0; i <= k; ++i)
		for(int j = 0; j < p; ++j)
			update(i, j, MX);
	update(0, 0, 0);
	
	int pref = 0;
	for(int i = 1; i < n; ++i){
		pref = (pref + tab[i])%p;
		for(int j = k; j >= 1; --j){
			int cur = min(ask(j - 1, 0, pref), ask(j - 1, pref + 1, p - 1) + p);
			update(j, pref, cur);
//			printf("%d %d %d :: %d\n", i, j, pref, cur);
		}
	}
	
	pref = (pref + tab[n])%p;
	printf("%d\n", min(ask(k - 1, 0, pref), ask(k - 1, pref + 1, p - 1) + p) + pref);
	return 0;
}
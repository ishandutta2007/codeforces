#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int logn = 20;
const int full = (1 << logn) - 1;
const int maxn = 5e5 + 5;

class Node{
public:
	int sum, tag, msk[2];
	int ls, rs;
	
	inline Node(int x = -1){
		if(!~x)
			msk[0] = msk[1] = sum = 0;
		else
			sum = 1, msk[0] = full ^ x, msk[1] = x;
		tag = ls = rs = 0;
		return;
	}
} ;

class Trie{
public:
	int rt, tot;
	Node dat[maxn * logn];
	
	Trie(){ rt = newNode(-1); return; }
	
	inline int newNode(int x = -1){ dat[tot] = Node(x); return tot++; }
	
	inline void insert(int &u, int x, int dep = logn){
		if(!u)
			u = newNode();
		if(dep == 0){
			u = newNode(x);
			return;
		}
		pushDown(u, dep);
		if(x >> dep - 1 & 1)
			insert(dat[u].rs, x, dep - 1);
		else
			insert(dat[u].ls, x, dep - 1);
		pushUp(u);
		return;
	}
	
	inline void split(int u, int &x, int &y, int k, int dep = logn){
		if(!u){
			x = y = 0;
			return;
		}
		if(!dep){
			x = u, y = 0;
			return;
		}
		pushDown(u, dep);
		if(k >> dep - 1 & 1){
			y = newNode();
			split(dat[u].rs, dat[u].rs, dat[y].rs, k, dep - 1);
			x = u;
		}
		else{
			x = newNode();
			split(dat[u].ls, dat[x].ls, dat[u].ls, k, dep - 1);
			y = u;
		}
		pushUp(x), pushUp(y);
		return;
	}
	
	inline void merge(int &u, int x, int y, int dep = logn){
		if(!x || !y){
			u = (x | y);
			return;
		}
		if(!u)
			u = newNode();
		if(dep){
			pushDown(x, dep), pushDown(y, dep);
			merge(dat[u].ls, dat[x].ls, dat[y].ls, dep - 1);
			merge(dat[u].rs, dat[x].rs, dat[y].rs, dep - 1);
			pushUp(u);
		}
		else
			u = x;
		return;
	}
	
	inline void pushUp(int u){
		FOR(i, 0, 2)
			dat[u].msk[i] = dat[dat[u].ls].msk[i] | dat[dat[u].rs].msk[i];
		dat[u].sum = (dat[dat[u].ls].sum + dat[dat[u].rs].sum);
		return;
	}
	
	inline void pushDown(int u, int dep){
		if(!u || !dat[u].tag)
			return;
		push(dat[u].ls, dep - 1, dat[u].tag);
		push(dat[u].rs, dep - 1, dat[u].tag);
		dat[u].tag = 0;
		return;
	}
	
	inline void push(int u, int dep, int x){
		if(!u)
			return;
		dat[u].tag ^= x;
		if(x >> dep - 1 & 1)
			swap(dat[u].ls, dat[u].rs);
		int tmp[2] = {(dat[u].msk[0] & (~x)) | (dat[u].msk[1] & x), (dat[u].msk[1] & (~x)) | (dat[u].msk[0] & x)};
		dat[u].msk[0] = tmp[0];
		dat[u].msk[1] = tmp[1];
		return;
	}
	
	inline void update(int u, int x, int dep = logn){
		if(!u)
			return;
		if((x & dat[u].msk[0] & dat[u].msk[1]) == 0){
			push(u, dep, x & dat[u].msk[0]);
			return;
		}
		pushDown(u, dep);
		if(x >> dep - 1 & 1){
			push(dat[u].ls, dep - 1, 1 << dep - 1);
			merge(dat[u].rs, dat[u].ls, dat[u].rs, dep - 1);
			dat[u].ls = 0;
		}
		update(dat[u].ls, x, dep - 1);
		update(dat[u].rs, x, dep - 1);
		pushUp(u);
		return;
	}
	
	inline void print(int u, int dep = logn, int x = 0){
		if(!u)
			return;
		pushDown(u, dep);
		if(!dep){
			printf("leaf x = %d\n", x);
			return;
		}
		printf("u = %d ls = %d rs = %d sum = %d\n", u, dat[u].ls, dat[u].rs, dat[u].sum);
		print(dat[u].ls, dep - 1, x);
		print(dat[u].rs, dep - 1, x ^ (1 << dep - 1));
		return;
	}
} trie;

int n, q;
int a[maxn];

int main(){
	scanf("%d%d", &n, &q);
	
	FOR(i, 0, n)
		scanf("%d", a + i), trie.insert(trie.rt, a[i]);
		
	FOR(i, 0, q){
		int tp, l, r, x; scanf("%d%d%d", &tp, &l, &r);
		int u = 0, v = 0, w = 0;
		if(l)
			trie.split(trie.rt, u, v, l - 1);
		else
			u = 0, v = trie.rt;
		trie.split(v, v, w, r);
		
		if(tp == 4)
			printf("%d\n", trie.dat[v].sum);
		else{
			scanf("%d", &x);
			if(tp == 1){
				trie.push(v, logn, full), trie.update(v, full ^ x), trie.push(v, logn, full);
			}
			else if(tp == 2)
				trie.update(v, x);
			else
				trie.push(v, logn, x);
		}
		
		trie.merge(u, u, v);
		trie.merge(trie.rt, u, w);
	}
	return 0;
}
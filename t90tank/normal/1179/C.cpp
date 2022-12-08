#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 300006; 
const int D = 1000006; 

struct node {
	int maxv, add; 
}; 

node e[D*3];
int n, m;  
int a[maxn], b[maxn]; 

void down(int T) {
	e[T*2].add += e[T].add; 
	e[T*2+1].add += e[T].add; 
	e[T].maxv += e[T].add; 
	e[T].add = 0; 
}

void up(int T) {
	e[T].maxv = max(e[T*2].maxv+e[T*2].add, e[T*2+1].maxv+e[T*2+1].add); 
}

void add(int T, int l, int r, int x, int d) { 
	if (x >= r) {
		e[T].add += d; 
		return; 
	}
	down(T); 
	int m = (l + r) / 2; 
	add(T*2,l,m,x,d); 
	if (x > m) add(T*2+1,m+1,r,x,d); 
	up(T); 
}

int ask(int T, int l, int r) {
	//cout<<l<<' '<<r<<' '<<e[T].maxv + e[T].add<<endl; 
	if (e[T].maxv+e[T].add <= 0) return -1; 
	if (l == r) return l; 
	down(T); 
	int m = (l + r) / 2; 
	if (e[T*2+1].maxv+e[T*2+1].add > 0) return ask(T*2+1, m+1, r); 
	return ask(T*2, l, m); 
}

int main() {
	scanf( "%d%d", &n, &m ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &a[i] ); 
	for (int i = 1; i <= m; ++i) scanf( "%d", &b[i] ); 
	memset(e, 0, sizeof(e)); 
	for (int i = 1; i <= n; ++i) add(1, 1, D, a[i], 1); 
	for (int i = 1; i <= m; ++i) add(1, 1, D, b[i], -1); 
	int q; scanf( "%d", &q ); 
	while (q--) {
		int op, no, x; 
		scanf( "%d%d%d", &op, &no, &x ); 
		if (op == 1) {
			add(1, 1, D, a[no], -1); 
			a[no] = x; 
			add(1, 1, D, a[no], 1); 
		}
		else {
			add(1, 1, D, b[no], 1); 
			b[no] = x; 
			add(1, 1, D, b[no], -1); 
		}
		printf( "%d\n", ask(1, 1, D) ); 
	}
}
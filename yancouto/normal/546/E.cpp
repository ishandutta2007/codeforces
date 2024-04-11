#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int a[102], b[102];
int c[205][205], f[205][205];

inline int i_in(int i) { return (i << 1) + 1; }
inline int i_out(int i) { return (i << 1) + 2; }
inline int cf(int i, int j) { return c[i][j] - f[i][j]; }

struct Node {
	int v, f, pai;
	bool operator < (const Node &o) const { return f < o.f; }
};

int usado[205], pai[205], tempo = 0;
int bfs(int s, int t) {
	priority_queue<Node> pq;
	tempo++;
	pq.push({s, INT_MAX, -1});
	while(!pq.empty()) {
		Node no = pq.top();
		pq.pop();
		if(usado[no.v] == tempo) continue;
		usado[no.v] = tempo;
		pai[no.v] = no.pai;
//		printf("Looking at %d from %d with flux %d\n", no.v, no.pai, no.f);
		if(no.v == t) {
//			puts("yea");
			int l = t;
			while(pai[l] != -1) {
				f[pai[l]][l] += no.f;
				f[l][pai[l]] -= no.f;
				l = pai[l];
			}
			return no.f;
		}
		for(int i = 0; i <= t; i++)
			if(usado[i] < tempo && cf(no.v, i))
				pq.push({i, min(no.f, cf(no.v, i)), no.v});
	}
	return 0;
}

int max_flow(int s, int t) {
	int mf = 0;
	while(int f = bfs(s, t))
		mf += f;
	return mf;
}

int get_val(int i, int j) {
	if(i == j) return cf(i_in(i), i_out(i));
	if(f[i_out(i)][i_in(j)] > 0) return f[i_out(i)][i_in(j)];
	return 0;
}

int main() {
	int i, j, p, q, total1 = 0, total2 = 0;
	scanf("%d %d", &n, &m);
	int s = 0, t = 2 * n + 1;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
		c[i_in(i)][i_out(i)] = a[i];
	}
	for(i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if(b[i] > a[i])
			total1 += (c[i_in(i)][t] = b[i] - a[i]);
		else if(b[i] < a[i])
			total2 += (c[s][i_in(i)] = a[i] - b[i]);
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &p, &q); p--; q--;
		c[i_out(p)][i_in(q)] = a[p];
		c[i_out(q)][i_in(p)] = a[q];
	}
	if(total1 != total2) { puts("NO"); return 0; }
	int mf = max_flow(s, t);
	if(mf != total1) { puts("NO"); return 0; }
	puts("YES");
	for(i = 0; i < n; i++) {
		printf("%d", get_val(i, 0));
		for(j = 1; j < n; j++)
			printf(" %d", get_val(i, j));
		putchar('\n');
	}
}
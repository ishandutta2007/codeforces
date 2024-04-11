#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

const int MAXV = 2e2 + 10;
const int U = 3e2 + 4;

int n, m;
int a[MAXV];
int b[MAXV];
int f[MAXV][MAXV];
int c[MAXV][MAXV];
int level[MAXV];
int ptr[MAXV];
int q[MAXV];
int qh = 0, qt = 0;

void fail(){
	printf("NO");
	exit(0);
}

void bfs(int bn){
	qh = 0; qt = 0;
	q[qt++] = 0;
	while(qh < qt){
		int v = q[qh++];
		F(i, 0, 2 * (n + 1)){
			if(level[i] == 0 && c[v][i] - f[v][i] >= bn){
				q[qt++] = i;
				level[i] = level[v] + 1;
			}
		}
	}
}

int dfs(int v, int flow, int bn){
	if(flow == 0)ret 0;
	if(v == 1)ret flow;
	for(int &i = ptr[v]; i < 2 * (n + 1); ++i){
		if(level[i] != level[v] + 1)cont;
		if(c[v][i] - f[v][i] >= bn){
			int df = dfs(i, min(flow, c[v][i] - f[v][i]), bn);
			if(!df)cont;
			f[v][i] += df;
			f[i][v] -= df;
			ret df;
		}
	}
	ret 0;
}

int dinic(){
	int pw = 1;
	while(pw < U)pw <<= 1;
	pw >>= 1;
	int flow = 0;
	while(pw > 0){
		while(true){
			fi0(level);
			level[0] = 1;
			bfs(pw);
			if(level[1] == 0)brk;
			fi0(ptr);
			while(int pushed = dfs(0, U + U, pw))flow += pushed;
		}
		pw >>= 1;
	}
	ret flow;
}

int main() {
	scanf("%d%d", &n, &m);
	int s = 0;
	F(i, 0, n)scanf("%d", &a[i]);
	F(i, 0, n)scanf("%d", &b[i]);
	F(i, 0, n)s += a[i] - b[i];
	if(s != 0)fail();
	fi0(f); fi0(c);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u);
		c[1 + v][1 + u + n] = U;
		c[1 + u][1 + v + n] = U;
	}
	F(i, 0, n){
		c[2 + i][2 + i + n] = U;
		c[0][2 + i] = a[i];
		c[2 + i + n][1] = b[i];
	}
	int flow = dinic();
	F(i, 0, n)flow -= a[i];
	if(flow != 0)fail();
	printf("YES\n");
	F(i, 0, n){
		F(j, 0, n){
			printf("%d ", f[2 + i][2 + j + n]);
		}
		printf("\n");
	}
	return 0;
}
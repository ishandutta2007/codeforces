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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXV = 2e2 + 6;

int n, m;
pair<int, int> r[MAXV];
bool gr[MAXV][MAXV];
bool grt[MAXV][MAXV];
int ord[MAXV];
bool used[MAXV];
int id[MAXV];
int cid = 0;
int sz = 0;

void add_edge(int v, int u){
	gr[v][u] = grt[u][v] = true;
}

void dfs(int v){
	used[v] = true;
	F(u, 0, 2*m){
		if(gr[v][u] && !used[u])dfs(u);
	}
	ord[sz++] = v;
}

void dfs1(int v){
	used[v] = true;
	id[v] = cid;
	F(u, 0, 2 * m){
		if(grt[v][u] && !used[u])dfs1(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(gr); fi0(grt);
	scanf("%d%d", &n, &m);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		if(v > u)swap(v, u);
		r[i] = mk(v, u);
	}
	F(i, 0, m){
		F(j, i + 1, m){
			pair<int, int> a[4];
			a[0] = mk(r[i].X, 0); a[1] = mk(r[i].Y, 0); a[2] = mk(r[j].X, 1); a[3] = mk(r[j].Y, 1);
			sort(a, a + 4);
			bool ie = false;
			F(k, 1, 4)if(a[k].X == a[k - 1].X){ie = true; brk;}
			if(ie)cont;
			F(k, 1, 4)if(a[k].Y == a[k - 1].Y){ie = true; brk;}
			if(ie)cont;
			add_edge(2*i + 1, 2*j);
			add_edge(2*i, 2*j + 1);
			add_edge(2*j, 2*i + 1);
			add_edge(2*j + 1, 2*i);
		}
	}
	fi0(used);
	F(i, 0, 2*m)if(!used[i])dfs(i);
	reverse(ord, ord + sz);
	fi0(used);
	F(i, 0, sz){
		int v = ord[i];
		if(!used[v]){
			dfs1(v);
			cid++;
		}
	}
	F(i, 0, m){
		if(id[2*i] == id[2*i + 1]){printf("Impossible"); ret 0;}
	}
	F(i, 0, m)if(id[2*i] < id[2*i + 1])putc('o', stdout); else putc('i', stdout);
	ret 0;
}
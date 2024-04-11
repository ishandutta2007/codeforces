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

const int MAXN = 3e5 + 5;
const int inf = 1e9;

vector<pair<int, int> > gr[MAXN];
int n, m;
int a, b;
int d[MAXN];
int p[MAXN];
bool used[MAXN];
int q[MAXN];
int qh = 0, qt = 0;
set<pair<int, int> > s;
int gt = 0;

void dfs(int v, int pr = -1){
	used[v] = true;
	p[v] = pr;
	I(c, gr[v]){
		int u = c.X, w = c.Y;
		if(!used[u]){
			if(w == 1 || d[v] == 1)d[u] = 1;
			dfs(u, v);
		}
	}
}

void calc(){
	dfs(a);
	F(i, 0, n){
		I(c, gr[i]){
			int v = c.X, w = c.Y;
			if(w == 0)cont;
			if(p[v] == i){d[v] = 1;}
			else if(p[i] == v){d[i] = 1;}
			else {d[i] = 1; d[v] = 1;}
		}
	}
	F(i, 0, n)if(d[i] == 1)q[qt++] = i;
	while(qh < qt){
		int v = q[qh++];
		I(c, gr[v]){
			int u = c.X;
			if(d[u] == 0 && p[v] != u){q[qt++] = u; d[u] = 1;}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(2204);
	scanf("%d%d", &n, &m);
	F(i, 0, m){
		int v, u, z;
		scanf("%d%d%d", &v, &u, &z);
		v--; u--;
		gr[v].pb(mk(u, z)); gr[u].pb(mk(v, z));
	}
	scanf("%d%d", &a, &b);
	a--; b--;
	calc();
	if(d[b] == 0)printf("NO"); else printf("YES");
	ret 0;
}
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
#define y1 adjf
#define tm afhdhn

const int MAXK = 505;
const int inf = 2e9;

int n, m, k;
vector<int> tp;
vector<list<int> > gr;
lint c[MAXK][MAXK];
lint d[MAXK][MAXK];
int cc = -1;
vector<int> com;

void dfs(int v){
	com[v] = cc;
	I(u, gr[v])if(com[u] == -1)dfs(u);
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	tp.rs(n); gr.rs(n); com.rs(n); com.asg(n, -1);
	int cr = 0;
	F(i, 0, k){
		int sz;
		scanf("%d", &sz);
		F(j, 0, sz)tp[cr++] = i;
		F(j, 0, k){c[i][j] = inf;}
		c[i][i] = 0;
	}
	F(i, 0, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w); v--; u--;
		c[tp[v]][tp[u]] = min(c[tp[v]][tp[u]], (lint)w);
		c[tp[u]][tp[v]] = min(c[tp[u]][tp[v]], (lint)w);
		if(w == 0){gr[v].pb(u); gr[u].pb(v);}
	}
	cr = 0;
	F(i, 0, k){
		if(com[cr] == -1){cc++; dfs(cr);}
		int old = com[cr];
		while(cr < n && tp[cr] == i){
			if(com[cr] != old){printf("No"); ret 0;}
			cr++;
		}
	}
	F(i, 0, k)
		F(j, 0, k)
			d[i][j] = c[i][j];
	printf("Yes\n");
	F(i, 0, k)
		F(j, 0, k)
			F(l, 0, k)
				d[j][l] = min(d[j][l], d[j][i] + d[i][l]);
	F(i, 0, k)
		F(j, 0, k)
			if(d[i][j] == inf)d[i][j] = -1;
	F(i, 0, k){
		F(j, 0, k)printf("%lld ", d[i][j]);
		printf("\n");
	}
	ret 0;
}
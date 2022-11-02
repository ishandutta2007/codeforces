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

int n;
vector<list<int> > gr;
vector<int> m1, m2;
vector<char> w;
int pl = 0;
int ans = 0;

void mark(int i, int j, int p = -1){
	if(i == j){w[i] = true; ret;}
	I(u, gr[i]){
		if(u == p)cont;
		mark(u, j, i);
		if(w[u]){w[i] = true; pl++;}
	}
}

void dfs(int v, int p = -1){
	I(u, gr[v]){
		if(u == p)cont;
		dfs(u, v);
		if(!w[u]){
			if(m1[u] + 1 > m1[v]){m2[v] = m1[v]; m1[v] = m1[u] + 1;}
			else if(m1[u] + 1 > m2[v]){m2[v] = m1[u] + 1;}
		}
	}
	int curr = m1[v] + m2[v];
	if(!w[v])ans = max(ans, pl * curr);
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	gr.rs(n); m1.rs(n); m2.rs(n); w.rs(n);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(i, 0, n){
		F(j, 0, n){ pl = 0;
			w.asg(n, false); m1.asg(n, 0); m2.asg(n, 0);
			mark(i, j);
			dfs(i);
		}
	}
	printf("%d", ans);
	ret 0;
}
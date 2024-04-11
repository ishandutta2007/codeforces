#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

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

const int MAXN = 1e2 + 3;
int up[MAXN];
vector<pair<int, int> > gr[MAXN];
int n;
int ans = 0;

void dfs(int v, int p = -1){
	up[v] = 0;
	I(u, gr[v]){
		if(u.X == p)cont;
		dfs(u.X, v);
		up[u.X] += u.Y;
		up[v] = max(up[v], up[u.X]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n - 1){
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		gr[v].pb(mk(u, c));
		gr[u].pb(mk(v, c));
	}
	dfs(0);
	printf("%d", up[0]);
	ret 0;
}
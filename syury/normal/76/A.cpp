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

const lint inf = 2e18 + 1818;

const int MAXM = 5e4 + 4;
const int MAXN = 2e2 + 2;

struct edge{
	int v, u;
	int g, s;
	void get(){
		scanf("%d%d%d%d", &v, &u, &g, &s); v--; u--;
	}
};

auto comp = [](const edge & a, const edge & b){
	ret (a.g < b.g) || (a.g == b.g && a.s < b.s);
};

int n, m;
lint best = inf;
int p[MAXN], rnk[MAXN];
edge e[MAXM];
int h[2][MAXN];
int ptr[2] = {0, 0};
int g, s;

void fill(){
	F(i, 0, n){p[i] = i; rnk[i] = 0;}
}

int find_set(int v){
	ret (v == p[v]) ? v : p[v] = find_set(p[v]);
}

bool unite(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret false;
	if(rnk[v] > rnk[u])swap(v, u);
	p[v] = u;
	if(rnk[v] == rnk[u])rnk[u]++;
	ret true;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &g, &s);
	F(i, 0, m)e[i].get();
	sort(e, e + m, comp);
	lint crr = 0;
	int u = 0;
	int dcp = 0;
	fill();
	F(i, 0, m){
		while(dcp < ptr[0] && e[h[0][dcp]].s < e[i].s){if(unite(e[h[0][dcp]].v, e[h[0][dcp]].u)){u++; h[1][ptr[1]++] = h[0][dcp]; crr = e[h[0][dcp]].s;} dcp++;}
		if(unite(e[i].v, e[i].u)){h[1][ptr[1]++] = i; u++; crr = e[i].s;}
		if(i == m - 1 || e[i + 1].g > e[i].g){
			while(dcp < ptr[0]){if(unite(e[h[0][dcp]].v, e[h[0][dcp]].u)){u++; h[1][ptr[1]++] = h[0][dcp]; crr = e[h[0][dcp]].s;} dcp++;}
		}
		if(i == m - 1 || e[i + 1].g > e[i].g){if(u == n - 1)best = min(best, crr * s + e[i].g * 1ll * g); crr = 0; dcp = 0; u = 0; acpy(h[0], h[1]); ptr[0] = ptr[1]; ptr[1] = 0; fill();}
	}
	if(best == inf)best = -1;
	printf("%lld", best);
	ret 0;
}
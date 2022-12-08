#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using Flow = int; 
using Cost = int; 
const int MXL = (int)1e9; 
const int mxn = 10000; 
const int mxm = 10000; 
#define pb push_back
#define fore(i,e,x) for(int i,e=fe[x]; i=ev[e],e; e=ne[e])

struct Graph { 
	int n,m,fe[mxn],ne[mxm],ev[mxm]; Flow f[mxm]; Cost c[mxm];
	void clear(int n)
	{ this->n = n; fill(fe, fe + n + 1, 0); m = 1; }
	void add_(int x, int y, Flow F, Cost C)
	{ ne[++m] = fe[x]; fe[x] = m; ev[m] = y; f[m]=F; c[m]=C; }
	void add1(int x, int y, Flow F, Cost C)
	{ add_(x, y, F, C); add_(y, x, 0, -C); }
	Cost d[mxn]; bool inq[mxn]; int p[mxn]; 
	void spfa(int S) {
		fill(d, d + n + 1, MXL); d[S] = 0; 
		for (deque<int> q = {S}; !q.empty(); ) {
			int x = q.front(); q.pop_front(), inq[x] = false;
			fore(i,e,x) if (f[e] && d[i] > d[x] + c[e]) {
				d[i] = d[x] + c[e], p[i] = e;
				if (!inq[i]) q.pb(i), inq[i] = true;
	}}}
	Cost mcmf(int S, int T) {
		Cost cost = 0;
		while (spfa(S), d[T] < MXL) { 
			Flow t = MXL; 
			for (int i = T; i != S; i = ev[p[i] ^ 1])
				t = min(t, f[p[i]]);
			for (int i = T; i != S; i = ev[p[i] ^ 1]) {
				//cout<<i<<' '; 
				f[p[i]] -= t, f[p[i] ^ 1] += t;
			}
			cost += d[T] * t;
			//puts(""); 
			//cout<<t<<' '<<cost<<endl; 
		}
		return cost;
	}
} G; 

int n, m, l, x; 
char s[10000]; 
char t[10000]; 
int S, T; 
int ans = 0; 

bool isame(int x) {
	for (int i = 0; i < l; ++i) 
		if (s[i+x] != t[i]) return false; 
	return true; 
}

void build(int a, int b, int f, int c) {
	assert(c <= 0); 
	G.add1(a,T,f,0); 
	G.add1(S,b,f,0); 
	G.add1(b,a,f,-c); 
	ans += f*c; 
	//cout<<ans<<endl; 
}

int main() {
	scanf( "%d", &n ); 
	scanf( "%s", s ); 
	scanf( "%d", &m ); 
	G.clear(n+3); 
	S = n+1; T = n+2; 
	for (int i = 1; i <= m; ++i) {
		int p; 
		scanf( "%s%d", t, &p ); 
		l = strlen(t); 
		for (int j = 0; j < n-x+1; ++j) 
			if (isame(j)) {
				build(j+l,j,1,-p); 
				//cout<<j<<endl; 
			}
	}
	scanf( "%d", &x ); 
	for (int i = 0; i < n; ++i) G.add1(i,i+1,x,0); 
	ans += G.mcmf(S, T); 
	cout<<-ans<<endl; 
}
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
#define tm dhjghg
#define ctime gjhgjhghg

const int mod = 1000000007;
const int MAXN = 2e5 + 5;

int n;
int nxt[MAXN];
bool used[MAXN];
bool cyc[MAXN];
int mo[MAXN];
int in[MAXN];
lint ans = 1;
int sz = 0;
int ctime = 0;
int tm[MAXN];

void cycle(int v){
	cyc[v] = true;
	sz++;
	if(cyc[nxt[v]]){
		if(sz > 1)ans *= 2;
		ans %= mod;
		ret;
	}
	cycle(nxt[v]);
}

int dfs(int v){
	tm[v] = ctime;
	used[v] = true;
	sz++;
	if(nxt[v] == -1){
		used[v] = false;
		ret v;
	}
	if(used[nxt[v]]){
		if(mo[nxt[v]] != -1){
			mo[v] = mo[nxt[v]];
			in[mo[v]]++;
			ret mo[v];
		}
		if(tm[nxt[v]] != ctime)ret -1;
		sz = 0;
		cycle(nxt[v]);
		ret -1;
	}
	int w = dfs(nxt[v]);
	if(w != -1){
		mo[v] = w;
		in[w]++;
	}
	ret w;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	F(i, 0, MAXN){in[i] = 1; mo[i] = nxt[i] = -1;}
	fi0(used); fi0(cyc);
	scanf("%d", &n);
	F(i, 0, n){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		nxt[v] = u;
	}
	F(i, 0, MAXN){
		if(nxt[i] != -1 && !used[i]){
			ctime++;
			dfs(i);
		}
	}
	F(i, 0, MAXN)ans = ans * in[i] % mod;
	printf("%lld", ans);
	ret 0;
}
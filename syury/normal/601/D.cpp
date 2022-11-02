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
const lint M1 = 1e9 + 7, M2 = 1e9 + 9;
const lint P1 = 31, P2 = 41;

int c[MAXN];
int dif[MAXN];
vector<int> gr[MAXN];
lint h1[MAXN], h2[MAXN];
lint a[MAXN];
int lh[MAXN], rh[MAXN];
int gt = 0;
int n;
char s[MAXN];
vector<pair<int, int> > bnd[MAXN];
int t[MAXN];
int lastpos[MAXN];
set<lint> lol;
map<lint, int> kek;
int cid = 0;

void add(int v, int delta){
	v++;
	while(v <= gt){
		t[v] += delta;
		v += (v&-v);
	}
}

int get(int l, int r){
	r++;
	int ans = 0;
	while(l > 0){
		ans -= t[l];
		l -= (l&-l);
	}
	while(r > 0){
		ans += t[r];
		r -= (r&-r);
	}
	ret ans;
}

void dfs(int v, int p, lint pw1, lint pw2){
	h1[v] = (p == -1) ? 0 : h1[p];
	h2[v] = (p == -1) ? 0 : h2[p];
	h1[v] = (h1[v] + pw1 * (s[v] - 'a' + 1))%M1;
	h2[v] = (h2[v] + pw2 * (s[v] - 'a' + 1))%M2;
	pw1 = pw1 * P1 % M1; pw2 = pw2 * P2 % M2;
	lh[v] = gt++; rh[v] = lh[v];
	a[lh[v]] = (h1[v]<<32) + h2[v];
	I(u, gr[v]){
		if(u == p)cont;
		dfs(u, v, pw1, pw2);
		rh[v] = max(rh[v], rh[u]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &c[i]);
	F(i, 0, n){
		char cc = getc(stdin);
		while(!isalpha(cc))cc = getc(stdin);
		s[i] = cc;
	}
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	dfs(0, -1, 1, 1);
	fi0(t);
	F(i, 0, n)bnd[rh[i]].pb(mk(lh[i], i));
	F(i, 0, n){
		lol.ins(a[i]);
	}
	I(c, lol){lastpos[cid] = n; kek[c] = cid++;}
	F(i, 0, n){
		a[i] = kek[a[i]];
		add(lastpos[a[i]], -1);
		lastpos[a[i]] = i;
		add(lastpos[a[i]], 1);
		I(c, bnd[i]){
			dif[c.Y] = get(c.X, i);
		}
	}
	int cmax = 0, ccnt = 0;
	F(i, 0, n){
		if(c[i] + dif[i] > cmax)cmax = c[i] + dif[i], ccnt = 0;
		if(c[i] + dif[i] == cmax)ccnt++;
	}
	printf("%d\n%d", cmax, ccnt);
	ret 0;
}
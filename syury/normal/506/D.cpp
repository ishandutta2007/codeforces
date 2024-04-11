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

const int MAXN = 1e5 + 5;

struct timearray{
	int gt = 1;
	int val[MAXN];
	int tm[MAXN];
	timearray(){fi0(tm);}
	void clear(){
		gt++;
	}
	int get(int i){
		if(tm[i] < gt)ret -1;
		ret val[i];
	}
	void set(int i, int x){
		val[i] = x;
		tm[i] = gt;
	}
};

unordered_map<int, int> qs[MAXN];
int ansq[MAXN];
int ta[MAXN];
pair<int, int> cq[MAXN];
map<pair<int, int>, int> la;
int cnt[MAXN];
set<int> big;
int n, m;
int cut;
vector<pair<int, int> > e[MAXN];
map<int, int> id;
int cid = 0;
int q;
int stk[MAXN];
int ptr = 0;

timearray p, rnk, used;

int find_set(int v){
	if(p.get(v) == -1){p.set(v, v); ret v;}
	if(p.get(v) == v)ret v;
	else {
		int x = find_set(p.get(v));
		p.set(v, x);
		ret x;
	}
}

void unite(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret;
	if(rnk.get(v) == -1)rnk.set(v, 0);
	if(rnk.get(u) == -1)rnk.set(u, 0);
	if(rnk.get(v) > rnk.get(u))swap(v, u);
	p.set(v, u);
	if(rnk.get(v) == rnk.get(u))rnk.set(u, rnk.get(u) + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(cnt); fi0(ta); fi0(ansq);
	scanf("%d%d", &n, &m);
	F(i, 0, n)qs[i].max_load_factor(0.25);
	cut = (int)sqrt((ldb)m)/4;
	cut = max(1, cut);
	F(i, 0, m){
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		v--; u--;
		if(!id.count(c))id[c] = cid++;
		int nc = id[c];
		e[nc].pb(mk(v, u));
		cnt[nc]++;
	}
	scanf("%d", &q);
	F(i, 0, q){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		if(v > u)swap(v, u);
		cq[i] = mk(v, u);
		if(la.count(mk(v, u)))cont;
		qs[v][u] = i;
		la[mk(v, u)] = i;
	}
	I(cc, id){
		int c = cc.Y;
		if(cnt[c] < cut){
			ptr = 0;
			p.clear(); rnk.clear(); used.clear();
			I(ce, e[c]){
				int v = ce.X, u = ce.Y;
				unite(v, u);
				if(used.get(v) == -1){used.set(v, 0); stk[ptr++] = v;}
				if(used.get(u) == -1){used.set(u, 0); stk[ptr++] = u;}
			}
			F(i, 0, ptr){
				F(j, i + 1, ptr){
					int v = stk[i], u = stk[j];
					if(v > u)swap(v, u);
					if(find_set(v) != find_set(u))cont;
					if(qs[v].count(u))ansq[qs[v][u]]++;
				}
			}
		}
		else{
			p.clear(); rnk.clear(); used.clear();
			I(ce, e[c]){
				int v = ce.X, u = ce.Y;
				unite(v, u);
			}
			F(i, 0, q){
				if(find_set(cq[i].X) == find_set(cq[i].Y))ta[i]++;
			}
		}
	}
	F(i, 0, q){
		ta[i] += ansq[la[cq[i]]];
		printf("%d\n", ta[i]);
	}
	ret 0;
}
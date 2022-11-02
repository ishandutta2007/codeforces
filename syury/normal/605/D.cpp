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
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 1e5 + 5;
const int inf = 1e9 + 9;

struct card{
	int a, b, c, d;
	int id;
};

auto comp = [](const card & a, const card & b){
	ret (a.a < b.a) || (a.a == b.a && a.b < b.b);
};

set<pair<int, int> > t[3 + 4 * MAXN];
int sz[3 + 4 * MAXN];
int n;
card p[MAXN];
set<int> ss;
map<int, int> mp;
int cid = 0;
int q[MAXN];
int pr[MAXN];
int qh = 0, qt = 0;
int stk[MAXN];
int dist[MAXN];
int ptr;

void build(int v, int l, int r){
	if(l == r){
		sz[v] = 1;
		t[v].ins(mk(p[l].b, l));
		ret;
	}
	int mid = (l + r) >> 1;
	build(2*v, l, mid);
	build(1+2*v, mid + 1, r);
	I(u, t[2*v])t[v].ins(u);
	I(u, t[1+2*v])t[v].ins(u);
	sz[v] = sz[2*v] + sz[1+2*v];
}

void del(int v, int l, int r, int pos){
	sz[v]--; t[v].era(mk(p[pos].b, pos));
	if(l == r){ret;}
	int mid = (l + r) >> 1;
	if(pos <= mid)del(2*v, l, mid, pos);
	else del(1+2*v, mid + 1, r, pos);
}

void get(int v, int l, int r, int ul, int ur, int my){
	if(ul > ur)ret;
	if(l == ul && r == ur){
		auto it = t[v].begin();
		while(it != t[v].end() && it->X <= my){stk[ptr++] = it->Y; it++;}
		ret;
	}
	int mid = (l + r) >> 1;
	get(2*v, l, mid, ul, min(ur, mid), my);
	get(1+2*v, mid + 1, r, max(ul, mid + 1), ur, my);
}

void bfs(){
	while(qh < qt){
		int v = q[qh++];
		ptr = 0;
		card tmp;
		tmp.a = p[v].c;
		tmp.b = inf;
		int r = lower_bound(p, p+n, tmp, comp) - p;
		r--;
		get(1, 0, n - 1, 0, r, p[v].d);
		F(i, 0, ptr){
			int u = stk[i];
			q[qt++] = u;
			pr[u] = v;
			dist[u] = dist[v] + 1;
			del(1, 0, n - 1, u);
		}
	}
}

void restore(int v){
	if(v == n)ret;
	restore(pr[v]);
	printf("%d ", p[v].id + 1);
}

int main(){
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n){
		scanf("%d%d%d%d", &p[i].a, &p[i].b, &p[i].c, &p[i].d);
		p[i].id = i;
		ss.ins(p[i].a);
	}
	sort(p, p + n, comp);
	build(1, 0, n - 1);
	p[n].c = 0; p[n].d = 0;
	pr[n] = -1;
	F(i, 0, n)pr[i] = -1;
	dist[n] = 0;
	q[qt++] = n;
	bfs();
	int id = -1;
	F(i, 0, n)if(p[i].id == n - 1)id = i;
	if(pr[id] == -1){printf("-1"); ret 0;}
	printf("%d\n", dist[id]);
	restore(id);
	ret 0;
}
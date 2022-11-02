#include<bits/stdc++.h>

#pragma GCC optimize("O3")

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

int n, d;
lint h[MAXN];
set<lint> ch;
map<lint, int> id;
int p[MAXN];
int cid = 0;
int t[4 * MAXN];
int ps[4 * MAXN];

void build(int v, int l, int r){
	t[v] = 0; ps[v] = -1;
	if(l == r)ret;
	int mid = (l + r) >> 1;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
}

void upd(int v, int l, int r, int pos, int nv, int dcp){
	if(t[v] < nv)ps[v] = dcp;
	t[v] = max(t[v], nv);
	if(l == r)ret;
	int mid = (l + r) >> 1;
	if(pos <= mid)upd(2*v, l, mid, pos, nv, dcp);
	else upd(2*v + 1, mid + 1, r, pos, nv, dcp);
}

pair<int, int> get(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret mk(0, -1);
	if(l == ul && r == ur)ret mk(t[v], ps[v]);
	int mid = (l + r) >> 1;
	ret max(get(2*v, l, mid, ul, min(ur, mid)), get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

void restore(int v){
	if(v == -1)ret;
	restore(p[v]);
	printf("%d ", v + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &d);
	F(i, 0, n)scanf("%lld", &h[i]);
	F(i, 0, n)ch.ins(h[i]);
	I(v, ch)id[v] = cid++;
	build(1, 0, cid - 1);
	int best = 0, bpos = -1;
	F(i, 0, n){
		auto rt = ch.lower_bound(h[i] + d), lt = ch.upper_bound(h[i] - d);
		int l = (lt == ch.begin()) ? -1 : id[*(--lt)], r = (rt == ch.end()) ? cid : id[*rt];
		pair<int, int> crr = max(get(1, 0, cid - 1, r, cid - 1), get(1, 0, cid - 1, 0, l));
		p[i] = crr.Y;
		if(best < crr.X + 1){best = crr.X + 1; bpos = i;}
		upd(1, 0, cid - 1, id[h[i]], crr.X + 1, i);
	}
	printf("%d\n", best);
	restore(bpos);
	ret 0;
}
#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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
#define tm dhgdg

const int MAXN = 1e5 + 5;
const int inf = 1e9 + 9;

struct node{
	int mx, cnt, smx;
	ll val = 0, sum = 0;
	ll sum_vals = 0;
	ll pushed = 0;
	int lpos, rpos;
	int l = -1, r = -1;
	int push = -1;
	ll push_one = 0;
};

node t[4 * MAXN];

void rec_val(int v){
	if(t[v].l == -1){t[v].sum_vals = t[v].val + t[v].pushed;}
	else{
		t[v].sum_vals = t[v].pushed + t[v].val + t[t[v].l].sum_vals - t[t[v].l].pushed + t[t[v].r].sum_vals - t[t[v].r].pushed;
	}
}

void recalc_node(int v){
	t[v].mx = max(t[t[v].l].mx, t[t[v].r].mx);
	t[v].cnt = 0;
	if(t[v].mx == t[t[v].l].mx)t[v].cnt += t[t[v].l].cnt;
	if(t[v].mx == t[t[v].r].mx)t[v].cnt += t[t[v].r].cnt;
	int vl = (t[v].mx == t[t[v].l].mx) ? t[t[v].l].smx : t[t[v].l].mx;
	int vr = (t[v].mx == t[t[v].r].mx) ? t[t[v].r].smx : t[t[v].r].mx;
	t[v].smx = max(vl, vr);
	t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
	rec_val(v);
}

void paintcol(int v, int col){
	t[v].mx = col; t[v].cnt = t[v].rpos - t[v].lpos + 1;
	t[v].smx = -inf; t[v].sum = t[v].mx * 1ll * t[v].cnt;
}

void push(int v){
	if(t[v].push_one != 0){
		if(t[v].l != -1){t[t[v].l].pushed += (t[t[v].l].rpos - t[t[v].l].lpos + 1) * t[v].push_one; t[t[v].l].sum_vals += (t[t[v].l].rpos - t[t[v].l].lpos + 1) * t[v].push_one; t[t[v].l].push_one += t[v].push_one;}
		if(t[v].r != -1){t[t[v].r].pushed += (t[t[v].r].rpos - t[t[v].r].lpos + 1) * t[v].push_one; t[t[v].r].sum_vals += (t[t[v].r].rpos - t[t[v].r].lpos + 1) * t[v].push_one; t[t[v].r].push_one += t[v].push_one;}
		t[v].push_one = 0;
	}
	if(t[v].push != -1){
		int col = t[v].push;
		t[v].push = -1;
		if(t[v].l != -1){paintcol(t[v].l, col); t[t[v].l].push = col; paintcol(t[v].r, col); t[t[v].r].push = col;}
	}
}

void upd_node(int v, int col){
	push(v);
	//printf("upd in (%d, %d)\n", t[v].lpos, t[v].rpos);
	if(t[v].mx <= col){
		ll up = col * 1ll * (t[v].rpos - t[v].lpos + 1);
		t[v].val += up - t[v].sum;
		t[v].sum_vals += up - t[v].sum;
		t[v].sum = up;
		t[v].push_one += col - t[v].mx;
		t[v].mx = col; t[v].cnt = t[v].rpos - t[v].lpos + 1; t[v].smx = -inf;
		t[v].push = col;
	}
	else{
		ll up = col * 1ll * (t[v].rpos - t[v].lpos + 1 - t[v].cnt);
		t[v].val += (t[v].cnt * 1ll * t[v].mx - t[v].cnt * 1ll * col) + up - (t[v].sum - t[v].mx * 1ll * t[v].cnt);
		t[v].sum_vals += (t[v].cnt * 1ll * t[v].mx - t[v].cnt * 1ll * col) + up - (t[v].sum - t[v].mx * 1ll * t[v].cnt);
		t[v].sum = col * 1ll * (t[v].rpos - t[v].lpos + 1);
		t[v].push_one += t[v].mx - col;
		t[v].mx = col; t[v].cnt = t[v].rpos - t[v].lpos + 1; t[v].smx = -inf;
		t[v].push = col;
	}
}

void build(int v, int l, int r){
	t[v].lpos = l; t[v].rpos = r;
	if(l == r){
		t[v].mx = l + 1;
		t[v].cnt = 1;
		t[v].smx = -inf;
		t[v].sum = l + 1;
		ret;
	}
	int mid = (l + r) >> 1;
	t[v].l = 2*v; t[v].r = 2*v + 1;
	build(t[v].l, l, mid);
	build(t[v].r, mid + 1, r);
	recalc_node(v);
}

void paint(int v, int l, int r, int ul, int ur, int col){
	if(ul > ur)ret;
	push(v);
	rec_val(v);
	if(ul == l && r == ur && t[v].smx == -inf){
//		printf("upd node (%d, %d)\n", l, r);
		upd_node(v, col);
		ret;
	}
	int mid = (l + r) >> 1;
	paint(t[v].l, l, mid, ul, min(ur, mid), col);
	paint(t[v].r, mid + 1, r, max(ul, mid + 1), ur, col);
	recalc_node(v);
}

void get(int v, int l, int r, int ul, int ur, ll & ans){
	if(ul > ur)ret;
	push(v);
	rec_val(v);
	//printf("in node (%d, %d) mx = %d smx = %d sumv = %lld pushed = %lld val = %lld push_one = %lld with query = (%d, %d)\n", l, r, t[v].mx, t[v].smx, t[v].sum_vals, t[v].pushed, t[v].val, t[v].push_one, ul, ur);
	if(l == ul && r == ur){ans += t[v].sum_vals; ret;}
	//if(l >= ul && r <= ur)ans += t[v].val;
	int mid = (l + r) >> 1;
	get(t[v].l, l, mid, ul, min(ur, mid), ans);
	get(t[v].r, mid + 1, r, max(ul, mid + 1), ur, ans);
}

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	//n = 100000; m = 100000;
	build(1, 0, n - 1);
	F(i, 0, m){
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		//l = rand()%n + 1; r = rand()%n + 1;
		//if(l > r)swap(l, r);
		//if(i == m - 1){type = 2;}else type = 1;
		l--; r--;
		if(type == 2){ll tmp = 0; get(1, 0, n - 1, l, r, tmp); printf("%lld\n", tmp);}
		else{
			int col;
			scanf("%d", &col);
			//col = rand()%100000000;
			paint(1, 0, n - 1, l, r, col);
		}
	}
	return 0;
}
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
#define tm dhgdg

const int MAXN = 4e5 + 5;
const int MOD = 1e9 + 9;

/*char mem[245 * 1000 * 1000];
size_t memptr = 0;

inline void* operator new(size_t len){
	memptr += len;
	ret mem + memptr - len;
}

inline void operator delete(void*){}*/

struct node{
	node *l = NULL, *r = NULL;
	int val;
};

void merge(node * v, node *l, node *r){
	v->val = max(l->val, r->val);
}

node * build(int l, int r){
	node * v = new node;
	v->val = 0;
	if(l == r)ret v;
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	ret v;
}

void upd(node * v, int l, int r, int pos, int clen){
	if(l == r){
		v->val = clen;
		ret;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid){upd(v->l, l, mid, pos, clen);}
	else{upd(v->r, mid + 1, r, pos, clen);}
	merge(v, v->l, v->r);
}

int get(node *v, int l, int r, int ul, int ur){
	if(ul > ur)ret 0;
	if(l == ul && r == ur)ret v->val;
	int mid = (l + r) >> 1;
	int al, ar;
	al = get(v->l, l, mid, ul, min(ur, mid));
	ar = get(v->r, mid + 1, r, max(ul, mid + 1), ur);
	ret max(al, ar);
}

int n, m;
int a[MAXN];
int pos[MAXN];
int x[MAXN];
int ans[MAXN];
int xcnt[MAXN];
int xlen[MAXN];
int tott[MAXN];
int ql[MAXN], qr[MAXN];
vector<int> q[MAXN];
set<int> ss;
map<int, int> tid;
node* lroot;
node* rroot;

int main(){
	scanf("%d%d", &n, &m);
	fi0(tott);
	F(i, 0, n){
		scanf("%d", &a[i]);
		ss.ins(a[i]);
	}
	int cid = 0;
	I(v, ss){
		tid[v] = cid++;
	}
	F(i, 0, m){
		scanf("%d%d", &pos[i], &x[i]);
		pos[i]--;
		q[pos[i]].pb(i);
		auto it = ss.lower_bound(x[i]);
		int l, r;
		if(it == ss.begin()){l = -1;}else{--it; l = tid[*it]; ++it;}
		if(it != ss.end() && *it == x[i])it++;
		if(it == ss.end()){r = n + 3;}else{r = tid[*it];}
		ql[i] = l; qr[i] = r;

	}
	lroot = build(0, n + 2);
	rroot = build(0, n + 2);
	F(i, 0, n){
		I(v, q[i]){
			ans[v] = 1 + get(lroot, 0, n + 2, 0, ql[v]);
		}
		int tans = get(lroot, 0, n + 2, 0, tid[a[i]] - 1);
		xcnt[i] = tans;
		xlen[i] = 1 + tans;
		upd(lroot, 0, n + 2, tid[a[i]], tans + 1);
	}
	Df(i, n - 1, -1){
		I(v, q[i]){
			ans[v] += get(rroot, 0, n + 2, qr[v], n + 2);
		}
		int tans = get(rroot, 0, n + 2, tid[a[i]] + 1, n + 2);
		xlen[i] += tans;
		upd(rroot, 0, n + 2, tid[a[i]], tans + 1);
	}
	int tlen = get(lroot, 0, n + 2, 0, n + 2);
	F(i, 0, n)if(xlen[i] == tlen)tott[xcnt[i]]++;
	F(i, 0, m){
		//int cbest = 1 + get(lroot[pos], 0, n + 2, 0, l).X + get(rroot[pos + 1], 0, n + 2, r, n + 2).X;
		//int xcnt = get(lroot[pos], 0, n + 2, 0, tid[a[pos]] - 1).Y * get(rroot[pos + 1], 0, n + 2, tid[a[pos]] + 1, n + 2).Y;
		//int xlen = 1 + get(lroot[pos], 0, n + 2, 0, tid[a[pos]] - 1).X + get(rroot[pos + 1], 0, n + 2, tid[a[pos]] + 1, n + 2).X;
		int j = pos[i];
		if(tott[xcnt[j]] == 1 && xlen[j] == tlen){ans[i] = max(ans[i], tlen - 1);}
		else {ans[i] = max(ans[i], tlen);}
		printf("%d\n", ans[i]);
	}
}
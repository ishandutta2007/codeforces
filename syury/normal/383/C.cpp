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
#define y1 adjf

int n, m;
vector<list<int> > gr;
vector<int> last, a, id;
vector<int> col;

int cid = 0;

void dfs(int v, int cl, int p){
	id[v] = cid++;
	col[id[v]] = cl;
	last[v] = id[v];
	I(u, gr[v]){
		if(u != p){
			dfs(u, 1 - cl, v);
			last[v] = max(last[v], last[u]);
		}
	}
}

struct node{
	int val[2] = {0, 0};
	node *l, *r;
};

node * build(int l, int r){
	node * v = new node;
	if(l == r)ret v;
	int mid = (l + r) >> 1;
	v->l = build(l, mid);
	v->r = build(mid + 1, r);
	ret v;
}

void upd(node * v, int l, int r, int ul, int ur, int add, int cl){
	if(ul > ur)ret;
	if(l == ul && r == ur){
		v->val[cl] += add;
		ret;
	}
	int mid = (l + r) >> 1;
	upd(v->l, l, mid, ul, min(ur, mid), add, cl);
	upd(v->r, mid + 1, r, max(ul, mid + 1), ur, add, cl);
}

int get(node * v, int l, int r, int pos){
	if(l == r){
		ret v->val[col[pos]] - v->val[1 - col[pos]];
	}
	int mid = (l + r) >> 1;
	int ans = 0;
	if(pos <= mid)ans = get(v->l, l, mid, pos);
	else ans = get(v->r, mid + 1, r, pos);
	ans += v->val[col[pos]] - v->val[1 - col[pos]];
	ret ans;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	a.rs(n); last.rs(n); id.rs(n); gr.rs(n); col.rs(n);
	F(i, 0, n)scanf("%d", &a[i]);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	dfs(0, 0, -1);
	node * root = build(0, n - 1);
	F(i, 0, m){
		int tp, v;
		scanf("%d%d", &tp, &v); v--;
		if(tp == 1){
			int d;
			scanf("%d", &d);
			upd(root, 0, n - 1, id[v], last[v], d, col[id[v]]);
		}
		else{
			printf("%d\n", a[v] + get(root, 0, n - 1, id[v]));
		}
	}
	ret 0;
}
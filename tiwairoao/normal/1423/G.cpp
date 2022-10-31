#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

int n, q;
struct BIT{
	ll tree[N + 5];
	int lowbit(int x) {return x & -x;}
	void update(int x, int k) {
		for(int i=x;i<=n;i+=lowbit(i)) tree[i] += k;
	}
	ll sum(int x) {
		ll ans = 0;
		for(int i=x;i;i-=lowbit(i)) ans += tree[i];
		return ans;
	}
}t1, t2;
ll sum(int x) {return t1.sum(x) + t2.sum(x) * x;}
void modify(int x, int d) {
//	printf("! %d %d\n", x, d);
	t1.update(x, - x * d), t2.update(x, d);
} // \forall k \in [x, n], ans_k = ans_k + (k - x) * d
 
struct node{
	int l, r, c;
	friend bool operator < (const node &a, const node &b) {
		return a.l < b.l;
	}
}; std::set<node>st, a[N + 5];
void erase(node x) {	
	auto it = a[x.c].find(x);
	if( it != a[x.c].begin() ) it--, modify(x.l - it->r, 1), it++;
	it++; if( it != a[x.c].end() ) modify(it->l - x.r, 1); it--;
	if( it != a[x.c].begin() ) {
		auto it2 = it, it3 = it; it2++, it3--;
		if( it2 != a[x.c].end() ) modify(it2->l - it3->r, -1);
	}
	if( x.l != x.r ) modify(1, x.r - x.l);
	
	modify(a[x.c].begin()->l, 1), modify(n - a[x.c].rbegin()->r + 1, 1), a[x.c].erase(x);
	if( !a[x.c].empty() )
		modify(a[x.c].begin()->l, -1), modify(n - a[x.c].rbegin()->r + 1, -1);
}
void insert(node x) {
	if( !a[x.c].empty() )
		modify(a[x.c].begin()->l, 1), modify(n - a[x.c].rbegin()->r + 1, 1);
	a[x.c].insert(x), modify(a[x.c].begin()->l, -1), modify(n - a[x.c].rbegin()->r + 1, -1);
	
	auto it = a[x.c].find(x);
	if( it != a[x.c].begin() ) it--, modify(x.l - it->r, -1), it++;
	it++; if( it != a[x.c].end() ) modify(it->l - x.r, -1); it--;
	if( it != a[x.c].begin() ) {
		auto it2 = it, it3 = it; it2++, it3--;
		if( it2 != a[x.c].end() ) modify(it2->l - it3->r, 1);
	}
	if( x.l != x.r ) modify(1, x.l - x.r);
}
std::set<node>::iterator split(int p) {
	auto x = st.upper_bound((node){p, -1, -1}); x--;
	if( x->l == p ) return x;
	else if( p > x->r ) return st.end();
	else {
		node t = (*x); erase(t), st.erase(x);
		st.insert((node){t.l, p - 1, t.c}), st.insert((node){p, t.r, t.c});
		insert((node){t.l, p - 1, t.c}), insert((node){p, t.r, t.c});
		return st.find((node){p, t.r, t.c});
	}
}//[l, r] -> [l, p - 1] + [p, r]
void assign(int l, int r, int c) {
	auto rx = split(r + 1), lx = split(l);
	
	auto p = lx;
	do {
		erase(*p), p++;
	}while( p != rx );
	st.erase(lx, rx), st.insert((node){l, r, c});
	insert((node){l, r, c});
}
void debug() {
	for(int i=1;i<=5;i++) {
		printf("%d : ", i);
		for(auto x : a[i]) printf("(%d %d %d)\t", x.l, x.r, x.c);
		puts("");
	}
	for(auto x : st)
		printf("(%d %d %d)\t", x.l, x.r, x.c);
	puts("\n");
}

std::map<int, int>mp; int idcnt;
int id(int x) {return mp.count(x) ? mp[x] : mp[x] = (++idcnt);}

int main() {
	scanf("%d%d", &n, &q);
	for(int i=1,x;i<=n;i++)
		scanf("%d", &x), st.insert((node){i, i, id(x)}), insert((node){i, i, id(x)});
//	debug();
	
	for(int i=1,opt,x,l,r;i<=q;i++) {
		scanf("%d", &opt);
		if( opt == 2 ) {
			scanf("%d", &x);
			ll ans = 1ll * x * (n - x + 1) + 1ll * x * (x - 1);
			printf("%lld\n", ans + sum(x));
		} else scanf("%d%d%d", &l, &r, &x), assign(l, r, id(x));
//		debug();
	}
}
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;

struct node{
	int l, r, c;
	friend bool operator < (const node &a, const node &b) {
		return a.l < b.l;
	}
};

int f[15][15]; set<node>st;
set<node>::iterator split(int p) {
	auto x = st.upper_bound((node){p, -1, -1}); x--;
	if( x->l == p ) return x;
	else if( p > x->r ) return st.end();
	else {
		node t = (*x); st.erase(x), f[t.c][t.c]++;
		st.insert((node){t.l, p - 1, t.c}), st.insert((node){p, t.r, t.c});
		return st.find((node){p, t.r, t.c});
	}
}//[l, r] -> [l, p - 1] + [p, r]
void assign(int l, int r, int c) {
	auto rx = split(r + 1), lx = split(l);
	if( lx != st.begin() ) {
		auto p = lx; p--;
		f[p->c][lx->c]--, f[p->c][c]++;
	}
	auto tmp = lx, p = (lx++);
	for(;lx!=rx;p=lx,lx++) f[p->c][lx->c]--;	
	if( rx != st.end() ) f[p->c][rx->c]--, f[c][rx->c]++;
	st.erase(tmp, rx), st.insert((node){l, r, c});
}

char s[N + 5], t[15];
int main() {
	int n, m, k; scanf("%d%d%d%s", &n, &m, &k, s + 1);
	for(int i=1;i<=n;i++) st.insert((node){i, i, s[i] - 'a'});
	for(int i=2;i<=n;i++) f[s[i - 1] - 'a'][s[i] - 'a']++;
	for(int i=1,opt,l,r;i<=m;i++) {
		scanf("%d", &opt);
		if( opt == 1 ) {
			scanf("%d%d%s", &l, &r, t);
			assign(l, r, t[0] - 'a');
		} else {
			int ans = n; scanf("%s", t);
			for(int p=0;p<k;p++)
				for(int q=p+1;q<k;q++)
					ans -= f[t[p] - 'a'][t[q] - 'a'];
			printf("%d\n", ans);
		}
	}
}
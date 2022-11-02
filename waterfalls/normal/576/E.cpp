#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
#define prev prev_

int p[51][500013];
int s[51][500013];
int rev[51][500013];
stack<pair<int*,int> > change[51];

int find(int w, int x) { return p[w][x]==x ? x : find(w,p[w][x]); }
bool same(int w, int a, int b) { return find(w,a)==find(w,b); }
int path(int w, int x) { return p[w][x]==x ? 0 : rev[w][x]^path(w,p[w][x]); }

void modify(int w, int& x, int y) {
	change[w].push(MP(&x,x));
	x = y;
}

void merge(int w, int a, int b) {
	int r = 1^path(w,a)^path(w,b);
	a = find(w,a), b = find(w,b);
	if (a==b) return;
	if (s[w][a]>s[w][b]) swap(a,b);
	modify(w,rev[w][a],r);
	modify(w,s[w][b],s[w][b]+(s[w][a]==s[w][b]));
	modify(w,p[w][a],b);
}

vector<int> mark() {
	vector<int> state(51);
	for (int w=0;w<=50;w++) state[w] = change[w].size();
	return state;
}
void rollback(vector<int>& state) {
	for (int w=0;w<=50;w++) {
		while (change[w].size()>state[w]) {
			*change[w].top().A = change[w].top().B;
			change[w].pop();
		}
	}
}

vector<int> has[1<<20];
void update(int w, int L, int R, int a, int b, int i) {
	if (b<L || R<a) return;
	if (a<=L && R<=b) has[w].push_back(i);
	else update(w*2,L,(L+R)/2,a,b,i), update(w*2+1,(L+R)/2+1,R,a,b,i);
}

int n,m,q;
int a[500013], b[500013];
vector<int> loc[500013];
int prev[500013];
int e[500013], c[500013];
bool ans[500013];

void solve(int w, int l, int r) {
	if (r<l) return;
	auto state = mark();
	for (int i: has[w]) merge(c[i],a[e[i]],b[e[i]]);
	if (l==r) {
		loc[e[l]].pop_back();
		bool ok = 1;
		if (same(c[l],a[e[l]],b[e[l]]) && path(c[l],a[e[l]])==path(c[l],b[e[l]])) ok = 0;
		if (ok) {
			ans[l] = true;
			prev[e[l]] = l;
		}
		if (prev[e[l]]) update(1,1,q,l+1,loc[e[l]].back()-1,prev[e[l]]);
	} else solve(w*2,l,(l+r)/2), solve(w*2+1,(l+r)/2+1,r);
	rollback(state);
}

int readint() {
	char c;
	while ((c=getchar())<'0');
	int res = c-'0';
	while ((c=getchar())>='0') res = res*10+c-'0';
	return res;
}

int main() {
	n = readint(), m = readint(), readint(), q = readint();
	for (int w=0;w<=50;w++) for (int i=1;i<=n;i++) {
		p[w][i] = i;
		s[w][i] = 1;
	}
	for (int i=1;i<=m;i++) a[i] = readint(), b[i] = readint();
	for (int i=1;i<=q;i++) {
		e[i] = readint(), c[i] = readint();
		loc[e[i]].push_back(i);
	}
	for (int i=1;i<=m;i++) loc[i].push_back(q+1);
	for (int i=1;i<=m;i++) reverse(loc[i].begin(),loc[i].end());
	solve(1,1,q);
	for (int i=1;i<=q;i++) printf("%s\n",ans[i] ? "YES" : "NO");

	return 0;
}
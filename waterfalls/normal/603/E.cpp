#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
#define prev prev_
struct Edge {
	int a,b,l,t;
	bool operator<(Edge o) const { return l<o.l; }
};

int p[100013], s[100013], odd;
stack<pair<int*,int> > ch;
inline int find(int x) {
	if (p[x]==x) return x;
	ch.push(MP(&p[x],p[x]));
	return p[x] = find(p[x]);
}
inline void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a==b) return;
	if (s[a]>s[b]) swap(a,b);
	ch.push(MP(&p[a],p[a]));
	p[a] = b;
	if (s[a]%2==1 && s[b]%2==1) odd-=2;
	ch.push(MP(&s[b],s[b]));
	s[b]+=s[a];
}
inline pair<int,int> mark() { return MP(ch.size(),odd); }
inline void rollback(pair<int,int> state) {
	while (ch.size()>state.A) *ch.top().A = ch.top().B, ch.pop();
	odd = state.B;
}

vector<Edge> edges;

int ans[300013];
vector<int> prev;
inline void solve(int l, int r, int low, int high) {
	if (r<l) return;
	if (low==high) {
		for (int i=l;i<=r;i++) ans[i] = low;
		return;
	}
	int m = (l+r)/2;
	vector<int> next;
	auto state = mark();
	for (int i: prev) {
		Edge e = edges[i];
		if (e.t<l && e.l<low) merge(e.a,e.b);
		else if (e.t<=r && e.l<=high) next.push_back(i);
	}
	swap(prev,next);
	auto state2 = mark();
	ans[m] = high;
	for (int i: prev) {
		Edge e = edges[i];
		if (e.t<=m) {
			merge(e.a,e.b);
			if (odd==0) {
				ans[m] = e.l;
				break;
			}
		}
	}
	rollback(state2);
	solve(l,m-1,ans[m],high);
	solve(m+1,r,low,ans[m]);
	rollback(state);
	swap(prev,next);
}

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	iota(p,p+n,0); fill(s,s+n,1);
	odd = n;
	for (int i=0;i<m;i++) {
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		a-=1; b-=1;
		edges.push_back({a,b,l,i});
		prev.push_back(i);
	}
	sort(edges.begin(),edges.end());
	solve(0,m-1,1,1e9+31);
	for (int i=0;i<m;i++) printf("%d\n",ans[i]>1e9+13 ? -1 : ans[i]);

	return 0;
}
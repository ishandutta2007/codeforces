#include <bits/stdc++.h>
using namespace std;

struct Point {
	int a,b,c,d,i;
	bool operator<(Point o) const {
		if (c!=o.c) return c<o.c;
		return i<o.i;
	}
};
vector<Point> pt;
int dist[100013];
struct comp {
	bool operator() (const int a, const int b) const {
		if (pt[a].d==pt[b].d) return pt[a].i<pt[b].i;
		return pt[a].d<pt[b].d;
	}
};

class ST {
private:
	int size;
	set<int,comp> has[1<<18];
	void build(int w, int L, int R) {
		for (int i=L;i<=R;i++) has[w].insert(i);
		if (L!=R) build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (a>R) return 0;
		if (a<=L) {
			pt.back() = {-1,-1,-1,b,-1};
			auto it = has[w].lower_bound(pt.size()-1);
			while (it!=has[w].end() && dist[*it]!=0) {
				has[w].erase(it);
				it = has[w].lower_bound(pt.size()-1);
			}
			if (it!=has[w].end()) return *it;
			return 0;
		}
		if (int res = queryI(w*2,L,(L+R)/2,a,b)) return res;
		return queryI(w*2+1,(L+R)/2+1,R,a,b);
	}
public:
	ST(int s=0) {
		size = s;
		if (s) build(1,1,size);
	}
	int query(int a, int b) { return queryI(1,1,size,a,b); }
};

int n;
ST tree;
int to[100013];

int main() {
	scanf("%d",&n);
	n+=1;
	pt.resize(n+1);
	pt[0] = {-1,-1,-1,-1,-1};
	for (int i=2;i<=n;i++) scanf("%d%d%d%d",&pt[i].a,&pt[i].b,&pt[i].c,&pt[i].d);
	for (int i=1;i<=n;i++) pt[i].i = i;
	sort(pt.begin(),pt.end());
	tree = ST(n);
	queue<int> frontier;
	int s = 0;
	for (int i=0;i<=n;i++) if (pt[i].i==n) s = i;
	dist[s] = 1;
	frontier.push(s);
	while (frontier.size()>0) {
		int x = frontier.front();
		frontier.pop();
		Point ugh = {0,0,pt[x].a,0,0};
		int ind = lower_bound(pt.begin(),pt.end(),ugh)-pt.begin();
		pt.push_back({0,0,0,0,0});
		while (int nx = tree.query(ind,pt[x].b)) {
			dist[nx] = dist[x]+1;
			to[nx] = x;
			frontier.push(nx);
		}
		pt.pop_back();
	}
	printf("%d\n",dist[1]-1);
	if (dist[1]) {
		int where = 1;
		while (where!=s) {
			where = to[where];
			printf("%d ",pt[where].i-1);
		}
		printf("\n");
	}

	return 0;
}
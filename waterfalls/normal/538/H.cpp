#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

const int INF = 1e9+7;

struct Event {
	int t,a,b,v;
	bool operator<(Event o) const { return t<o.t; }
};

struct Block {
	int low[2], high[2];
	vector<int> has[2];
	Block() {
		low[0] = low[1] = 0;
		high[0] = high[1] = INF;
	}
};

class ST {
private:
	int size;
	pair<int,int> st[1<<21];
	int lazy[1<<21];
	void push(int w, int L, int R) {
		if (!lazy[w]) return;
		st[w].A+=lazy[w];
		if (L!=R) {
			lazy[w*2]+=lazy[w];
			lazy[w*2+1]+=lazy[w];
		}
		lazy[w] = 0;
	}
	void build(int w, int L, int R) {
		st[w] = MP(0,L);
		if (L!=R) build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
	}
	void updateI(int w, int L, int R, int a, int b, int v) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) {
			lazy[w] = v;
			push(w,L,R);
		} else {
			updateI(w*2,L,(L+R)/2,a,b,v), updateI(w*2+1,(L+R)/2+1,R,a,b,v);
			st[w] = max(st[w*2],st[w*2+1]);
		}
	}
	pair<int,int> queryI(int w, int L, int R, int a, int b) {
		push(w,L,R);
		if (b<L || R<a) return MP(-INF,0);
		if (a<=L && R<=b) return st[w];
		return max(queryI(w*2,L,(L+R)/2,a,b), queryI(w*2+1,(L+R)/2+1,R,a,b));
	}
public:
	ST(int s=0) {
		size = s;
		fill(lazy,lazy+(1<<21),0);
		if (s) build(1,0,size-1);
	}
	void update(int a, int b, int v) { updateI(1,0,size-1,a,b,v); }
	pair<int,int> query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int t,T,n,m;
int l[100013], r[100013];
vector<int> adj[100013];

int color[100013];
void dfs(int x, int c, Block& b) {
	color[x] = c;
	b.low[c-1] = max(b.low[c-1],l[x]);
	b.high[c-1] = min(b.high[c-1],r[x]);
	b.has[c-1].push_back(x);
	for (int i: adj[x]) {
		if (color[i] && color[i]==c) printf("IMPOSSIBLE\n"), exit(0);
		if (!color[i]) dfs(i,3-c,b);
	}
}

vector<Block> blocks;
vector<Event> events;
void build() {
	for (int i=1;i<=n;i++) if (!color[i]) {
		Block b = Block();
		dfs(i,1,b);
		if (b.high[0]<b.low[0] || b.high[1]<b.low[1]) printf("IMPOSSIBLE"), exit(0);
		blocks.push_back(b);
		events.push_back({b.low[0],b.low[1],b.high[1],1});
		events.push_back({b.high[0]+1,b.low[1],b.high[1],-1});
		events.push_back({b.low[1],b.low[0],b.high[0],1});
		events.push_back({b.high[1]+1,b.low[0],b.high[0],-1});
		int one = max(b.low[0],b.low[1]);
		int two = min(b.high[0],b.high[1]);
		if (two<one) continue;
		events.push_back({one,one,two,-1});
		events.push_back({two+1,one,two,1});
	}
}

vector<int> comp;
void compress() {
	for (auto e: events) {
		for (int d=-1;d<=1;d++) comp.push_back(e.a+d);
		for (int d=-1;d<=1;d++) comp.push_back(e.b+d);
	}
	comp.push_back(-INF);
	comp.push_back(INF);
	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());
	for (auto& e: events) {
		e.a = lower_bound(comp.begin(),comp.end(),e.a)-comp.begin();
		e.b = lower_bound(comp.begin(),comp.end(),e.b)-comp.begin();
	}
}

pair<int,int> solve() {
	ST tree(comp.size());
	sort(events.begin(),events.end());
	int prev = -INF;
	for (auto e: events) {
		if (e.t>prev) {
			int one = lower_bound(comp.begin(),comp.end(),t-e.t+1)-comp.begin();
			int two = upper_bound(comp.begin(),comp.end(),T-prev)-comp.begin()-1;
			auto pos = tree.query(one,two);
			if (pos.A==blocks.size()) {
				int y = comp[pos.B];
				if (y>=t-prev) return MP(prev,y);
				else return MP(prev+t-prev-y,y);
			}
		}
		tree.update(e.a,e.b,e.v);
		prev = e.t;
	}
	printf("IMPOSSIBLE\n"), exit(0);
}

int which[100013];
void construct(pair<int,int> ans) {
	for (Block b: blocks) {
		int dir = (b.low[0]<=ans.A && ans.A<=b.high[0] && b.low[1]<=ans.B && ans.B<=b.high[1]);
		for (int i: b.has[0]) which[i] = 2-dir;
		for (int i: b.has[1]) which[i] = 2-!dir;
	}
}

int main() {
	scanf("%d%d%d%d",&t,&T,&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build();
	compress();
	auto ans = solve();
	construct(ans);
	printf("POSSIBLE\n");
	printf("%d %d\n",ans.A,ans.B);
	for (int i=1;i<=n;i++) printf("%d",which[i]);
	printf("\n");

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct EdgeRange {
	int from, to;
	ll cost;
	bool operator<(const EdgeRange o) const {
		return cost > o.cost;
	}
};

class ST {
private:
	vector<EdgeRange> st[1<<18];
	void update(int w, int L, int R, int a, int b, EdgeRange v) {
		if (b<L || R<a) return;
		if (a<=L && R<=b) st[w].push_back(v);
		else {
			update(w*2,L,(L+R)/2,a,b,v);
			update(w*2+1,(L+R)/2+1,R,a,b,v);
		}
	}
	void query(int w, int L, int R, int a, vector<EdgeRange>& res) {
		if (a<L || R<a) return;
		res.insert(res.end(),st[w].begin(),st[w].end());
		st[w].clear();
		if (L!=R) {
			query(w*2,L,(L+R)/2,a,res);
			query(w*2+1,(L+R)/2+1,R,a,res);
		}
	}
public:
	int size;
	void update(int a, int b, EdgeRange v) { update(1,1,size,a,b,v); }
	vector<EdgeRange> query(int a) {
		vector<EdgeRange> res;
		query(1,1,size,a,res);
		return res;
	}
};

int n,q,s;
vector<EdgeRange> adj[100013];
ST tree;

ll dist[100013];
set<int> need;
priority_queue<EdgeRange> frontier;

void dijkstra() {
	memset(dist,0x3f,sizeof dist);
	dist[s] = 0;
	frontier.push({s, s, 0});
	for (int i=1;i<=n;i++) need.insert(i);
	while (frontier.size()>0) {
		ll cur = frontier.top().cost;
		int a = frontier.top().from;
		int b = frontier.top().to;
		frontier.pop();
		while (true) {
			auto it = need.lower_bound(a);
			if (it==need.end() || *it>b) break;
			a = *it;
			need.erase(it);
			dist[a] = cur;
			vector<EdgeRange> res = tree.query(a);
			res.insert(res.end(),adj[a].begin(),adj[a].end());
			for (auto e: res) {
				e.cost+=cur;
				if (e.from==e.to) {
					if (e.cost<dist[e.from]) {
						frontier.push(e);
						dist[e.from] = e.cost;
					}
				} else frontier.push(e);
			}
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&q,&s);
	tree.size = n;
	for (int i=0;i<q;i++) {
		int t;
		scanf("%d",&t);
		if (t==1) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			adj[a].push_back({b, b, c});
		} else {
			int a,l,r,c;
			scanf("%d%d%d%d",&a,&l,&r,&c);
			if (t==2) {
                adj[a].push_back({l, r, c});
			} else {
				tree.update(l,r,{a, a, c});
			}
		}
	}
	dijkstra();
	for (int i=1;i<=n;i++) {
		if (dist[i]>1e15) printf("-1 ");
		else printf("%lld ",dist[i]);
	}
	printf("\n");

	return 0;
}
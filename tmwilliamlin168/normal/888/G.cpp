#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;

int p[mxN];
vector<int> comps[mxN];
inline void initDSU(int n) {
	for(int i=0; i<n; ++i) {
		p[i]=i;
		comps[i].push_back(i);
	}
}
int root(int x) {
	return x==p[x]?x:(p[x]=root(p[x]));
}
inline void join(int x, int y) {
	if(comps[x].size()>=comps[y].size()) {
		p[y]=x;
		comps[x].insert(comps[x].end(), comps[y].begin(), comps[y].end());
		comps[y].clear();
	} else {
		p[x]=y;
		comps[y].insert(comps[y].end(), comps[x].begin(), comps[x].end());
		comps[x].clear();
	}
}

struct TrieNode {
	int c[2], t=0;
	unordered_set<int> *d=NULL;
	TrieNode() {
		c[0]=c[1]=-1;
	}
};
vector<TrieNode> trie;
inline void add(int x, int x2) {
	int cNode=0;
	for(int i=29; i>=0; --i) {
		int j=(x>>i)&1;
		if(trie[cNode].c[j]==-1) {
			trie[cNode].c[j] = trie.size();
			trie.push_back(TrieNode());
		}
		cNode=trie[cNode].c[j];
		++trie[cNode].t;
	}
	if(trie[cNode].d==NULL)
		trie[cNode].d = new unordered_set<int>();
	trie[cNode].d->insert(x2);
}
inline void remove(int x, int x2) {
	int cNode=0;
	for(int i=29; i>=0; --i) {
		int j=(x>>i)&1;
		cNode=trie[cNode].c[j];
		--trie[cNode].t;
	}
	trie[cNode].d->erase(x2);
}
inline int leastXor(int x) {
	int cNode=0;
	for(int i=29; i>=0; --i) {
		int j=(x>>i)&1;
		if(trie[cNode].c[j]==-1||!trie[trie[cNode].c[j]].t)
			j^=1;
		cNode=trie[cNode].c[j];
	}
	return *trie[cNode].d->begin();
}

int a[mxN];
vector<pair<int, int>> edges;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	trie.push_back(TrieNode());
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for(int i=0; i<n; ++i)
		add(a[i], i);
	initDSU(n);
	long long ans=0;
	while(comps[root(0)].size()<n) {
		for(int i=0; i<n; ++i) {
			if(i!=root(i))
				continue;
			for(int j : comps[i])
				remove(a[j], j);
			pair<int, int> minEdge=make_pair(-1, -1);
			for(int j : comps[i]) {
				int k=leastXor(a[j]);
				if(minEdge.first==-1||(a[j]^a[k])<(a[minEdge.first]^a[minEdge.second]))
					minEdge = make_pair(j, k);
			}
			edges.push_back(minEdge);
			for(int j : comps[i])
				add(a[j], j);
		}
		for(pair<int, int> edge : edges) {
			int x=root(edge.first), y=root(edge.second);
			if(x!=y) {
				join(x, y);
				ans+=a[edge.first]^a[edge.second];
			}
		}
		edges.clear();
	}
	cout << ans;
}
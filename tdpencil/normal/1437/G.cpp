#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int AL = 26;

vector<int> val;
vector<int> pos;

struct aho_corasick {
	struct node {
		map<int, int> nxt, go;
		int p, pch;
		int suf, ssuf;
		multiset<int> vals;
		bool term;
		
		node() {
			nxt.clear();
			go.clear();
			suf = ssuf = -1;
			term = false;
			vals.clear();
			p = -1, pch = -1;
		}
	};

	vector<node> nodes;
	
	aho_corasick() {
		nodes = vector<node>(1, node());
	}

	int add(const string& s) {
		int v = 0;
		forn(i, s.size()) {
			int c = s[i] - 'a';
			if (!nodes[v].nxt.count(c)) {
				nodes.push_back(node());
				nodes[v].nxt[c] = int(nodes.size()) - 1;
				nodes.back().p = v;
				nodes.back().pch = c;
			}
			v = nodes[v].nxt[c];
		}
		nodes[v].term = true;
		nodes[v].vals.insert(0);
		return v;
	}
	
	int feed(const string &s){
		int v = 0;
		int ans = -1;
		forn(i, s.size()){
			int c = s[i] - 'a';
			v = go(v, c);
			int u = v;
			while (u != 0){
				if (!nodes[u].vals.empty())
					ans = max(ans, *nodes[u].vals.rbegin());
				u = ssuf(u);
			}
		}
		return ans;
	}
	
	int go(int v, int c) {
		if (nodes[v].go.count(c))
			return nodes[v].go[c];
		if (nodes[v].nxt.count(c))
			return nodes[v].go[c] = nodes[v].nxt[c];
		if (v == 0)
			return nodes[v].go[c] = 0;
		return nodes[v].go[c] = go(suf(v), c);
	}
	
	int suf(int v) {
		if (nodes[v].suf != -1)
			return nodes[v].suf;
		if (v == 0 || nodes[v].p == 0)
			return nodes[v].suf = 0;
		return nodes[v].suf = go(suf(nodes[v].p), nodes[v].pch);
	}
	
	int ssuf(int v) {
		if (nodes[v].ssuf != -1)
			return nodes[v].ssuf;
		if (v == 0 || nodes[v].p == 0)
			return nodes[v].ssuf = 0;
		int s = suf(v);
		if (nodes[s].term)
			return nodes[v].ssuf = s;
		return nodes[v].ssuf = ssuf(s);
	}
};

aho_corasick ac;

int main() {
	int n, m;
	ios::sync_with_stdio(!cin.tie(0));
	cin >> n >> m;
	pos.resize(n);
	val.resize(n, 0);
	
	vector<int> tp2;
	
	ac = aho_corasick();
	
	forn(i, n){
		string s;
		cin >> s;
		pos[i] = ac.add(s);
	}
	
	forn(i, m){
		int t;
		cin >> t;
		if (t == 1){
			int j, x;
			cin >> j >> x;
			--j;
			ac.nodes[pos[j]].vals.erase(ac.nodes[pos[j]].vals.find(val[j]));
			val[j] = x;
			ac.nodes[pos[j]].vals.insert(val[j]);
		}
		else{
			string q;
			cin >> q;
			printf("%d\n", ac.feed(q));
		}
	}
	
	return 0;
}
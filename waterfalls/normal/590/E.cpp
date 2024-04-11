#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node *c[2], *f, *out;
	bool done;
	vector<int> has;
	Node() {
		c[0] = c[1] = 0;
		f = out = 0;
		done = 0;
	}
};

void makelinks(Node* head) {
	queue<Node*> frontier;
	head->out = head;
	head->done = 1;
	for (int i=0;i<2;i++) if (head->c[i] && head->c[i]!=head) {
		head->c[i]->f = head;
		head->c[i]->out = head;
		frontier.push(head->c[i]);
	}
	while (frontier.size()>0) {
		Node* x = frontier.front();
		frontier.pop();
		for (int i=0;i<2;i++) if (x->c[i]) {
			Node* cur = x->c[i];
			Node* prev = x->f;
			while (!prev->c[i]) prev = prev->f;
			cur->f = prev->c[i];
			cur->out = (cur->f->has.size()>0) ? cur->f : cur->f->out;
			frontier.push(cur);
		}
	}
}

int n;
char buff[10000013];
vector<string> words;

Node* head;
void makeAC() {
	head = new Node();
	for (int i=0;i<words.size();i++) {
		int on = 0;
		Node* cur = head;
		while (true) {
			if (on==words[i].size()) {
				cur->has.push_back(i);
				break;
			}
			if (!cur->c[words[i][on]-'a']) cur->c[words[i][on]-'a'] = new Node();
			cur = cur->c[words[i][on]-'a'];
			on+=1;
		}
	}
	for (int i=0;i<2;i++) if (!head->c[i]) head->c[i] = head;
	makelinks(head);
}

int bad[763][763];
void getbad() {
	for (int i=0;i<n;i++) {
		vector<Node*> reset;
		Node* cur = head;
		for (char c: words[i]) {
			while (!cur->c[c-'a']) cur = cur->f;
			cur = cur->c[c-'a'];
			Node* cur2 = cur;
			while (!cur2->done) {
				for (int j: cur2->has) {
					bad[i][j] = 1;
					cur2->done = 1;
					reset.push_back(cur2);
				}
				cur2 = cur2->out;
			}
		}
		for (Node* j: reset) j->done = 0;
	}
}

vector<int> adj[763];
int match[763], visited[763];
int matchR[763];
bool dfs(int x) {
	visited[x] = 1;
	for (int i: adj[x]) {
		if (match[i]==-1 || (!visited[match[i]] && dfs(match[i]))) {
			match[i] = x;
			return 1;
		}
	}
	return 0;
}
void matching() {
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (bad[i][j]) {
		if (bad[j][i] && j>=i) continue;
		adj[i].push_back(j);
	}
	for (int i=0;i<n;i++) match[i] = matchR[i] = -1;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) visited[j] = 0;
		dfs(i);
	}
	for (int i=0;i<n;i++) if (match[i]!=-1) matchR[match[i]] = i;
}

vector<vector<int> > chains;
void getchains() {
	for (int i=0;i<n;i++) if (match[i]==-1) {
		chains.push_back(vector<int>());
		int where = i;
		while (matchR[where]!=-1) {
			chains.back().push_back(where);
			where = matchR[where];
		}
		chains.back().push_back(where);
	}
}

bool dead[763];
vector<int> ans;
void dfs2(int x, int f=0) {
	if (dead[x]) return;
	if (f) dead[x] = 1;
	for (int i: adj[x]) dfs2(i,1);
}
void construct() {
	for (auto v: chains) dfs2(v.back());
	while (true) {
		bool ok = 1;
		for (auto& v: chains) if (dead[v.back()]) {
			ok = 0;
			while (dead[v.back()]) v.pop_back();
			dfs2(v.back());
		}
		if (ok) break;
	}
	for (auto v: chains) ans.push_back(v.back());
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&buff);
		words.push_back(string(buff));
	}
	makeAC();
	getbad();
	matching();
	getchains();
	construct();
	printf("%d\n",ans.size());
	for (int i: ans) printf("%d ",i+1);
	printf("\n");

	return 0;
}
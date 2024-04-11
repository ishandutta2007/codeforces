#include <bits/stdc++.h>
using namespace std;

struct Node {
	int size;
	Node *c[26];
	Node() {
		size = 1;
		for (int i=0;i<26;i++) c[i] = 0;
	}
	void calc() {
		size = 1;
		for (int i=0;i<26;i++) if (c[i]) size+=c[i]->size;
	}
};
void merge(Node*& a, Node* b) {
	if (!a) a = b;
	if (!a || !b) return;
	for (int i=0;i<26;i++) {
		if (!a->c[i]) a->c[i] = b->c[i];
		else if (b->c[i]) merge(a->c[i],b->c[i]);
	}
	a->calc();
}

int n;
int c[300013];
char s[300013];
vector<int> adj[300013];
Node* head[300013];

int best = 0;
int which = 0;

void dfs(int x, int p=0) {
	if (p) adj[x].erase(find(adj[x].begin(),adj[x].end(),p));
	if (adj[x].size()==0) {
		head[x] = new Node();
		head[x]->c[s[x]-'a'] = new Node();
		head[x]->calc();
	} else {
		for (int i: adj[x]) dfs(i,x);
		for (int i: adj[x]) if (i!=adj[x][0]) merge(head[adj[x][0]],head[i]);
		head[x] = new Node();
		head[x]->c[s[x]-'a'] = head[adj[x][0]];
		head[x]->calc();
	}
	if (head[x]->size+c[x]>best) best = head[x]->size+c[x], which = 0;
	if (head[x]->size+c[x]==best) which+=1;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf(" %s",s+1);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	printf("%d\n",best-1);
	printf("%d\n",which);

	return 0;
}
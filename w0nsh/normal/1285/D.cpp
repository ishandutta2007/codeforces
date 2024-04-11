#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Node{
	Node *l, *r;
	Node() : l(nullptr), r(nullptr) {}
};

Node *root;

Node *left(Node *node){
	if(!node->l) node->l = new Node();
	return node->l;
}
Node *right(Node *node){
	if(!node->r) node->r = new Node();
	return node->r;
}

void add(Node *node, int val, int pos=29){
	if(pos == -1) return;
	if(val&(1<<pos)){
		add(left(node), val, pos-1);
	}else{
		add(right(node), val, pos-1);
	}
}

int dfs(Node *node, int pos=29){
	if(!node->l) return (node->r ? dfs(node->r, pos-1) : 0);
	if(!node->r) return (node->l ? dfs(node->l, pos-1) : 0);
	return std::min(dfs(node->r, pos-1), dfs(node->l, pos-1)) | (1<<pos);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	root = new Node();
	FOR(i, n) std::cin >> A[i], add(root, A[i]);
	std::cout << dfs(root) << "\n";
	return 0;
}
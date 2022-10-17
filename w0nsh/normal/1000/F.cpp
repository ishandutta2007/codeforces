#include <algorithm>
#include <utility>
#include <cstdio>
#include <vector>
#include <map>

const int INF = 2000000666;

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define PR std::pair<int, int>
#define MP std::make_pair
#define LL long long

struct Node{
	PR val;
	Node *left, *right;
	Node(Node *l, Node *r){
		this->left = l;
		this->right = r;
		this->val = std::min(left->val, right->val);
	}
	Node(int ls, int pos){
		this->left = nullptr;
		this->right = nullptr;
		this->val = MP(ls, pos);
	}
};

int n;
std::vector<int> A;
std::vector<int> last;

std::vector<Node*> trees;

Node* build(int low, int high){
	if(low == high)
		return new Node(INF, low);
	int mid = (low + high) >> 1;
	return new Node(build(low, mid), build(mid+1, high));
}

PR query(Node *node, int a, int b, int low, int high){
	if(b < a)
		return MP(INF, -1);
	if(a == low && b == high)
		return node->val;
	int mid = (low+high) >> 1;
	return std::min(query(node->left, a, std::min(b, mid), low, mid),
					query(node->right, std::max(a, mid+1), b, mid+1, high));
}

Node* update(Node *node, int low, int high, int pos, int val){
	if(low == high) return new Node(val, pos);
	int mid = (low+high)>>1;
	if(pos <= mid)
		return new Node(update(node->left, low, mid, pos, val), node->right);
	else
		return new Node(node->left, update(node->right, mid+1, high, pos, val));
}

void answer(){
	int q;
	std::scanf("%d", &q);
	while(q--){
		int l, r;
		std::scanf("%d%d", &l, &r);
		--l;--r;
		PR odp = query(trees[r+1], l, r, 0, n-1);
		if(odp.first < l) std::printf("%d\n", A[odp.second]);
		else std::printf("0\n");
	}
}

void build_trees(){
	trees.resize(n+1);
	trees[0] = build(0, n-1);
	for(int i = 0; i < n; ++i){
		Node *cur = trees[i];
		if(last[i] != -1)
			cur = update(cur, 0, n-1, last[i], INF);
		cur = update(cur, 0, n-1, i, last[i]);
		trees[i+1] = cur;
	}
}

void read(){
	std::scanf("%d", &n);
	int oldn = n;
	n = 1048576/2;
	A.resize(n);
	FOR(i, oldn){
		std::scanf("%d", &A[i]);
	}
	for(int i = oldn; i < n; ++i) A[i] = INF;
	std::map<int, int> map;
	last.resize(n);
	FOR(i, n){
		if(map.find(A[i]) == map.end()){
			last[i] = -1;
		}else{
			last[i] = map[A[i]];
		}
		map[A[i]] = i;
	}
}

int main(){
	read();
	build_trees();
	answer();
	return 0;
}
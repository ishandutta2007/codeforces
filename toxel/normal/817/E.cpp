#include<bits/stdc++.h>

const int MAXN = 100010;
const int MAX = 27;
const int N = 1 << MAX;

class trie{
public:
	int sum;
	trie *child[2];
	
	trie():sum(0){memset(child, 0, sizeof(child));}
	
	int getsum(){
		return this ? sum : 0;
	}
	
	trie *getchild(int type){
		return this ? child[type] : NULL;
	}
};

trie *triepool;
int triesize;

trie *newnode(){
	if (!triesize){
		triepool = new trie[MAXN];
		triesize += MAXN;
	}
	return triepool + -- triesize;
}

void add(trie *&root, int l, int r, int sit, int value){
	if (!root){
		root = newnode();
	}
	root -> sum += value;
	if (l == r){
		return;
	}
	int mid = l + r >> 1;
	if (sit <= mid){
		add(root -> child[0], l, mid, sit, value);
	}
	else{
		add(root -> child[1], mid + 1, r, sit, value);
	}
}

int query(trie *root, int l, int p){
	int ret = 0;
	for (int i = MAX - 1; ~i; -- i){
		int type = p >> i & 1, x = l >> i & 1;
		if (x){
			ret += root -> getchild(type) -> getsum();
			root = root -> getchild(type ^ 1);
		}
		else{
			root = root -> getchild(type);
		}
	}
	return ret;
}

int main(){
	trie *root = NULL;
	int test;
	scanf("%d", &test);
	while (test --){
		int op, p;
		scanf("%d%d", &op, &p);
		if (op == 1){
			add(root, 0, N - 1, p, 1);
			continue;
		}
		if (op == 2){
			add(root, 0, N - 1, p, -1);
			continue;
		}
		int l;
		scanf("%d", &l);
		printf("%d\n", query(root, l, p));
	}
	return 0;
}
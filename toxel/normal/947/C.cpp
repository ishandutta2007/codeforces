#include<bits/stdc++.h>

struct trie{
	int cnt;
	trie *child[2];
	
	trie(){cnt = 0, child[0] = child[1] = NULL;}
	
	int getcnt(){return cnt;}
	trie *getchild(int n){return child[n];}
};

trie *triepool;
int triecnt = 0;

trie *newtrie(){
	const int MAX = 100000;
	if (!triecnt){
		triepool = new trie [MAX];
		triecnt += MAX;
	}
	return triepool + -- triecnt;
}

const int N = 300010;

int a[N];
int p[N];
int ans[N];

void add(trie *root, int n){
	trie *p = root;
	for (int i = 29; i >= 0; -- i){
		int bit = n >> i & 1;
		if (p -> getchild(bit) == NULL){
			p -> child[bit] = newtrie();
		}
		++ p -> cnt;
		p = p -> getchild(bit);
	}
	++ p -> cnt;
}

int query(trie *root, int n){
	trie *p = root;
	int ret = 0;
	for (int i = 29; i >= 0; -- i){
		int bit = n >> i & 1;
		if (p -> getchild(bit) == NULL || !((p -> getchild(bit)) -> getcnt())){
			bit ^= 1;
			ret ^= 1 << i;
		}
		-- p -> cnt;
		p = p -> getchild(bit);
	}
	-- p -> cnt;
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	trie *root = newtrie();
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i]);
		add(root, p[i]);
	}
	for (int i = 0; i < n; ++ i){
		ans[i] = query(root, a[i]);
	}
	for (int i = 0; i < n; ++ i){
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}
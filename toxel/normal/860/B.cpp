#include<bits/stdc++.h>

const int N = 70010;
const int M = 10;

char s[N][M];

struct trie{
	int cnt;
	trie *next[M];
	
	trie():cnt(0){memset(next, 0, sizeof(next));}
};

int triesz = 0;
trie *nodepool;

trie *newnode(){
	if (!triesz){
		nodepool = new trie [N];
		triesz += N;
	}
	return nodepool + -- triesz;
}

int main(){
	int n;
	scanf("%d", &n);
	trie *root = newnode();
	for (int u = 0; u < n; ++ u){
		scanf("%s", s[u]);
		std::set <trie *> rollback;
		for (int i = 0; i < 9; ++ i){
			for (int j = i; j < 9; ++ j){
				trie *p = root;
				for (int k = i; k <= j; ++ k){
					int x = s[u][k] - '0';
					if (p -> next[x] == NULL){
						p -> next[x] = newnode();
					}
					p = p -> next[x];
				}
				if (!rollback.count(p)){
					++ p -> cnt;
					rollback.insert(p);
				}
			}
		}
	}
	for (int u = 0; u < n; ++ u){
		bool flag = false;
		for (int i = 1; i <= 9; ++ i){
			for (int j = 0; j <= 9 - i; ++ j){
				trie *p = root;
				for (int k = j; k <= j + i - 1; ++ k){
					int x = s[u][k] - '0';
					p = p -> next[x];
				}
				if (p -> cnt == 1){
					for (int k = j; k <= j + i - 1; ++ k){
						putchar(s[u][k]);
					}
					putchar('\n');
					flag = true;
					break;
				}
			}
			if (flag){
				break;
			}
		}
	}
	return 0;
}
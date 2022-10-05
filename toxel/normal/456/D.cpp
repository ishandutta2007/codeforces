#include<bits/stdc++.h>

const int N = 200010;
const int M = 26;

char *s[N], str[N];
int len[N];

struct trie{
	trie *child[M];
	bool sg;
	
	trie():sg(false){memset(child, 0, sizeof(child));}
	
	trie *&getchild(int i){
		return child[i];
	}
};

trie *triepool;
int triecnt = 0;

trie *newtrie(){
	if (!triecnt){
		triepool = new trie [N];
		triecnt = N;
	}
	return triepool + -- triecnt;
}

void dfs(trie *p){
	for (int i = 0; i < M; ++ i){
		if (p -> getchild(i)){
			dfs(p -> getchild(i));
			if (!(p -> getchild(i) -> sg)){
				p -> sg = true;
			}
		}
	}
}

void dfs1(trie *p){
	bool flag = true;
	p -> sg = false;
	for (int i = 0; i < M; ++ i){
		if (p -> getchild(i)){
			flag = false;
			dfs1(p -> getchild(i));
			if (!(p -> getchild(i) -> sg)){
				p -> sg = true;
			}
		}
	}
	if (!(p -> sg)){
		p -> sg = flag;
	}
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	s[0] = str;
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
		len[i] = strlen(s[i]);
		s[i + 1] = s[i] + len[i] + 1;
	}
	trie *root = newtrie();
	for (int i = 0; i < n; ++ i){
		trie *p = root;
		for (int j = 0; j < len[i]; ++ j){
			int x = s[i][j] - 'a';
			if (!(p -> getchild(x))){
				p -> getchild(x) = newtrie();
			}
			p = p -> getchild(x);
		}
	}
	dfs(root);
	if (!(root -> sg)) return printf("Second\n"), 0;
	dfs1(root);
	if (root -> sg) return printf("First\n"), 0;
	return printf(k & 1 ? "First\n" : "Second\n"), 0;
}
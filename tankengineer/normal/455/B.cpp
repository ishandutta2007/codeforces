#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int C = 26;

struct Trie {
	Trie *ch[C];
	bool con[2];

	Trie() {
		memset(ch, 0, sizeof(ch));
	}

	void add(char *s) {
		if (*s == '\0') {
			return;
		}
		if (!ch[*s - 'a']) {
			ch[*s - 'a'] = new Trie();
		}
		ch[*s - 'a']->add(s + 1);
	}

	void calCon() {
		con[0] = con[1] = false;
		bool haschild = false;
		for (int i = 0; i < C; ++i) {
			if (ch[i]) {
				haschild = true;
				ch[i]->calCon();
				con[0] = con[0] || !ch[i]->con[0];
				con[1] = con[1] || !ch[i]->con[1];
			}
		}
		if (!haschild) {
			con[0] = false;
			con[1] = true;
		}
	}

} *root;

const int N = 100005;

char s[N];

int n, k;

int main() {
	root = new Trie();
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		root->add(s);
	}
	root->calCon();	
	if (root->con[0] && root->con[1]) {
		puts("First");
	} else if (!root->con[0] && !root->con[1]) {
		puts("Second");
	} else if (root->con[0] && !root->con[1]) {
		puts(k & 1 ? "First" : "Second");
	} else if (!root->con[0] && root->con[1]) {
		puts("Second");
	}
	return 0;
}
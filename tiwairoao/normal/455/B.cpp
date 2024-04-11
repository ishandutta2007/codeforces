#include<cstdio>
#include<cstring>
const int MAXN = 100000;
struct node{
	int dp[2];
	node *nxt[26];
}trie[MAXN + 5], *tcnt, *root, *NIL;
void init() {
	NIL = tcnt = root = &trie[0];
	for(int i=0;i<26;i++)
		NIL->nxt[i] = NIL;
	for(int i=0;i<2;i++)
		NIL->dp[i] = 0;
}
node *newnode() {
	tcnt++;
	for(int i=0;i<26;i++)
		tcnt->nxt[i] = NIL;
	for(int i=0;i<2;i++)
		tcnt->dp[i] = 0;
	return tcnt;
}
char s[MAXN + 5];
void addstring() {
	node *nw = root;
	int len = strlen(s);
	for(int i=0;i<len;i++) {
		if( nw->nxt[s[i]-'a'] == NIL )
			nw->nxt[s[i]-'a'] = newnode();
		nw = nw->nxt[s[i]-'a'];
	}
}
void dfs(node *rt) {
	bool flag = false;
	for(int i=0;i<26;i++)
		if( rt->nxt[i] != NIL )
			flag = true;
	if( !flag ) {
		rt->dp[0] = false;
		rt->dp[1] = true;
		return ;
	}
	for(int i=0;i<26;i++)
		if( rt->nxt[i] != NIL ) {
			dfs(rt->nxt[i]);
			if( !rt->nxt[i]->dp[0] ) rt->dp[0] = true;
			if( !rt->nxt[i]->dp[1] ) rt->dp[1] = true;
		}
}
void solve() {
	init(); int n, K;
	scanf("%d%d", &n, &K);
	for(int i=1;i<=n;i++) {
		scanf("%s", s);
		addstring();
	}
	dfs(root);
	if( root->dp[0] ) {
		if( root->dp[1] ) puts("First");
		else {
			if( K%2 ) puts("First");
			else puts("Second");
		}
	}
	else puts("Second");
}
int main() {
	solve();
}
#include <bits/stdc++.h>

const int N = 1000000;

int dl[N + 5], dr[N + 5], dcnt;
std::vector<int>G[N + 5];
void dfs(int x) {
	dl[x] = (++dcnt);
	for(auto to : G[x]) dfs(to);
	dr[x] = dcnt;
}

int tree[N + 5];
void add(int x) {
	for(int i=x;i<=dcnt;i+=(i&-i)) tree[i]++;
}
void sub(int x) {
	for(int i=x;i<=dcnt;i+=(i&-i)) tree[i]--;
}
int sum(int x) {
	int r = 0; for(int i=x;i;i-=(i&-i)) r += tree[i]; return r;
}

int ch[26][N + 5], fa[N + 5], id[N + 5], ncnt;
int insert(char *s, int l) {
	int x = 0;
	for(int i=0;i<l;i++) {
		if( !ch[s[i] - 'a'][x] ) ch[s[i] - 'a'][x] = (++ncnt);
		x = ch[s[i] - 'a'][x];
	}
	return x;
}
void build() {
	std::queue<int>que;
	for(int i=0;i<26;i++) if( ch[i][0] ) que.push(ch[i][0]);
	
	while( !que.empty() ) {
		int x = que.front(); que.pop();
		if( !id[x] ) id[x] = id[fa[x]];
		for(int i=0;i<26;i++) {
			if( ch[i][x] ) fa[ch[i][x]] = ch[i][fa[x]], que.push(ch[i][x]);
			else ch[i][x] = ch[i][fa[x]];
		}
	}
	
	for(int i=1;i<=ncnt;i++) G[fa[i]].push_back(i);
	dfs(0);
}

int f[N + 5];

int pos[N + 5], len[N + 5], num[N + 5];
int solve(char *s, int l) {
	int x = 0;
	for(int i=0;i<l;i++) {
		x = ch[s[i] - 'a'][x];
		if( i == l - 1 ) x = fa[x];
		f[i] = id[x]; if( f[i] ) add(dl[num[f[i]]]);
	}
	
	std::set<int>st;
	for(int i=l-1;i>=0;i--) if( f[i] ) {
		if( !(sum(dr[num[f[i]]]) - sum(dl[num[f[i]]])) )
			st.insert(f[i]);
	}
	
	int p = l;
	for(int i=l-1;i>=0;i--) if( f[i] ) {
		if( p > i - len[f[i]] + 1 )
			p = i - len[f[i]] + 1;
		else st.erase(f[i]);
	}
	
	for(int i=0;i<l;i++) if( f[i] ) sub(dl[num[f[i]]]);
	return (int)st.size();
}

char s[N + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		pos[i] = pos[i - 1] + len[i - 1];
		scanf("%s", s + pos[i]);
		len[i] = strlen(s + pos[i]);
	}
	for(int i=1;i<=n;i++) id[num[i] = insert(s + pos[i], len[i])] = i;
	build();
	
	int ans = 0;
	for(int i=1;i<=n;i++) ans += solve(s + pos[i], len[i]);
	printf("%d\n", ans);
}
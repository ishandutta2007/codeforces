#include <bits/stdc++.h>
using namespace std;
#define M 600010
#define LL long long
#define rep(i, x, y) for(LL i = (x); i <= (y); i ++)
inline LL read() {
	char ch = getchar(); LL x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	} while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	} return x * f;
}
struct Edge{
	int u, v, id, Next;
} G[M]; int head[M], tot = -1;
vector<int> T[M];
bool vis[M], done[M], ans[M];
inline void add(int u, int v, int w) {
	G[++ tot] = (Edge){u, v, w, head[u]};
	head[u] = tot;
} queue<int> Q;
int main(){
	int n = read(), m = read(), s = read();
	memset(head, -1, sizeof(head));
	rep(i, 1, m) {
		int t = read(), u = read(), v = read();
		if(t == 1) T[u].push_back(v);
		else add(u, v, i), add(v, u, i);
	} 
	while(!Q.empty()) Q.pop();
	memset(vis, 0, sizeof(vis));
	memset(done, 0, sizeof(done));
	Q.push(s); vis[s] = 1; while(!Q.empty()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < T[x].size(); i ++) {
			if(!vis[T[x][i]]) vis[T[x][i]] = 1, Q.push(T[x][i]); 
		} for(int i = head[x]; i != -1; i = G[i].Next) {
			if(!done[i / 2 + 1]) {
				done[i / 2 + 1] = 1;
				if(i & 1) ans[i / 2 + 1] = 1;
				else ans[i / 2 + 1] = 0;
				if(!vis[G[i].v]) vis[G[i].v] = 1, Q.push(G[i].v);
				continue;
			} 
		}
	} int cnt = 0;
	rep(i, 1, n) if(vis[i]) cnt ++;
	printf("%d\n", cnt);
	rep(i, 1, tot / 2 + 1) {
		printf(ans[i] ? "-" : "+");
	} puts("");
	while(!Q.empty()) Q.pop();
	memset(vis, 0, sizeof(vis));
	memset(done, 0, sizeof(done));
	Q.push(s); vis[s] = 1; while(!Q.empty()) {
		int x = Q.front(); Q.pop();
		for(int i = 0; i < T[x].size(); i ++) {
			if(!vis[T[x][i]]) vis[T[x][i]] = 1, Q.push(T[x][i]); 
		} for(int i = head[x]; i != -1; i = G[i].Next) {
			if(done[i / 2 + 1]) {
				if(!vis[G[i].v]) vis[G[i].v] = 1, Q.push(G[i].v);
				continue;
			} done[i / 2 + 1] = 1;
			if(i & 1) ans[i / 2 + 1] = 0;
			else ans[i / 2 + 1] = 1;
		}
	} cnt = 0;
	rep(i, 1, n) if(vis[i]) cnt ++;
	printf("%d\n", cnt);
	rep(i, 1, tot / 2 + 1) {
		printf(ans[i] ? "-" : "+");
	} 
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = N * 2;

const int TTT = (1 << 20) + 5;

int S[N] , f[TTT], n , m , x , y , fir[N] , ne[M] , to[M] , cnt;
long long ans[N] , now[N];

void add(int x , int y) {
    ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
    add(x , y); add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

bool vis[N];
char s[N];

void dance(int x , int f) {int i; for(S[x] = 1 , i = fir[x];i;i = ne[i]) if(!vis[to[i]] && to[i] - f) dance(to[i] , x) , S[x] += S[to[i]];}

int GR(int x , int f , int Size) {
    Foreachson(i , x)
	if(to[i] - f && !vis[to[i]] && S[to[i]] * 2 >= Size) return GR(to[i] , x , Size);
    return x;
}

vector <int> T;

int R[22];

void dfs(int x , int F , int sta) {
    now[x] = 0;
    for(int i = 0;i <= 20;++ i) {
	now[x] = now[x] + f[R[i] ^ sta];
    }
    T.push_back(sta);
    Foreachson(i , x) {
	int V = to[i];
	if(V == F || vis[V]) continue;
	dfs(V , x , sta ^ (1 << (s[V] - 'a')));
	now[x] = now[x] + now[V];
    }
    ans[x] += now[x];
}

void solve(int x) {
    vis[x] = 1;
    vector <int> son; son.clear();
    vector <int> Ba; Ba.clear();
    ++ ans[x]; ++ f[1 << (s[x] - 'a')];
    Foreachson(i , x) {
	int V = to[i];
	if(vis[V]) continue;
	son.push_back(V);
	T.clear();
	dfs(V , x , (1 << (s[V] - 'a')));
	ans[x] += now[V];
	for(int j = 0;j < (int)T.size();++ j) {
	    T[j] = T[j] ^ (1 << (s[x] - 'a'));
	    Ba.push_back(T[j]); ++ f[T[j]];
	}
    }
    -- f[1 << (s[x] - 'a')];
    for(int i = 0;i < (int) Ba.size();++ i) -- f[Ba[i]];
    for(int i = (int) son.size() - 1;i >= 0;-- i) {
	int V = son[i];
	if(vis[V]) continue;
	T.clear();
	dfs(V , x , (1 << (s[V] - 'a')));
	for(int j = 0;j < (int) T.size();++ j) ++ f[T[j] ^ (1 << (s[x] - 'a'))];
    }
    for(int i = 0;i < (int) Ba.size();++ i) -- f[Ba[i]];
    Foreachson(i , x) {
	int V = to[i];
	if(vis[V]) continue;
	dance(V , x);
	solve(GR(V , x , S[V]));
    }
}

int main(void) {
    for(int i = 0;i < 20;++ i) R[i] = 1 << i; R[20] = 0;
    scanf("%d" , &n);
    for(int i = 1;i < n;++ i) scanf("%d%d" , &x , &y) , link(x , y);
    scanf("%s" , s + 1);
    dance(1 , 0);
    solve(GR(1 , 0 , S[1]));
    for(int i = 1;i <= n;++ i) {
	printf("%I64d " , ans[i]);
    }
}
#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 3e5 + 5;

int n;
int fa[maxn], sz[maxn], nxt[maxn];
char s[maxn];

inline int find(int x){ return (fa[x] == x) ? x : (fa[x] = find(fa[x])); }

inline void merge(int x, int y){
	x = find(x), y = find(y);
	fa[x] = y;
	sz[y] += sz[x];
	return; 
}

inline void solve(){
	scanf("%d", &n);
	scanf("%s", s);
	int x = -1;
	FOR(i, 0, n) if(s[i] != '-')
		x = s[i];
	if(!~x){
		printf("%d\n", n);
		return;
	}
	int ans = 0;
	FOR(i, 0, n)
		fa[i] = i, sz[i] = 1;
	FOR(i, 0, n) if(s[i] == '-')
		merge(i, (i + 1) % n);
	bool f = true;
	FOR(i, 0, n)
		f &= (s[i] == '-' || s[i] == x);
	if(f){
		printf("%d\n", n);
		return;
	}
	FOR(i, 0, n)
		ans += (sz[find(i)] > 1);
	printf("%d\n", ans);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}
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
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 5e5 + 5;
const int INF = 1e9 + 7;

class Dsu{
public:
	int fa[maxn];
	Dsu(){ FOR(i, 0, maxn) fa[i] = i; }
	inline int find(int x){ return (x == fa[x] ? x : (fa[x] = find(fa[x]))); }
	inline void merge(int x, int y){ fa[x] = y; return; }
} dsu;

int n, m;
int vis[maxn], used[maxn];

int main(){
	scanf("%d%d", &n, &m);
	
	FOR(i, 0, n){
		int t, x, y; scanf("%d", &t);
		if(t == 1){
			scanf("%d", &x); --x;
			x = dsu.find(x);
			if(!vis[x])
				vis[x] = 1, used[i] = 1;
		}
		else{
			scanf("%d%d", &x, &y);
			--x; --y;
			x = dsu.find(x), y = dsu.find(y);
			if(x == y || (vis[x] && vis[y]))
				continue;
//			printf("x = %d y = %d\n", x, y);
			if(vis[x])
				vis[y] = 1;
			if(vis[y])
				vis[x] = 1;
			if(!vis[x] && !vis[y]){
				if(x > y)
					swap(x, y);
				dsu.merge(x, y);
			}
			used[i] = 1;
		}
	}
	
	int ans = 1, cnt = 0;
	FOR(i, 0, n) if(used[i])
		(ans <<= 1) %= INF, ++cnt;
	printf("%d %d\n", ans, cnt);
	FOR(i, 0, n) if(used[i])
		printf("%d ", i + 1);
	puts("");
	return 0;
}
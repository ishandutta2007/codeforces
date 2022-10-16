#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 2505;

int n;
int a[maxn][maxn];

class Edge{
public:
	int u, v, w;
	Edge(){}
	Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
	bool operator < (const Edge &oth)const{ return w < oth.w; }
};

class Dsu{
private:
	int fa[maxn];
	inline int find(int x){ return (x == fa[x] ? x : fa[x] = find(fa[x]));}
public:
	inline void init(){
		FOR(i, 0, n)
			fa[i] = i;
		return;
	}
	inline void combine(int x, int y){
		x = find(x);
		y = find(y);
		fa[x] = y;
		return;
	}
	inline bool same(int x, int y){ return find(x) == find(y); }
}dsu;

vector<Edge> ed;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n) FOR(j, 0, n){
		scanf("%d", &a[i][j]);
		if(i < j)
			ed.PB(Edge(i, j, a[i][j]));
	}
	FOR(i, 0, n){
		FOR(j, 0, n) if(a[i][j] != a[j][i]){
			puts("NOT MAGIC");
			return 0;
		}
		if(a[i][i]){
			puts("NOT MAGIC");
			return 0;
		}
	}
	dsu.init();
	sort(ed.begin(), ed.end());
	for(int i = 0, j; i < ed.size(); i = j){
		for(j = i; j < ed.size() && ed[j].w == ed[i].w; ++j)
			if(dsu.same(ed[j].u, ed[j].v)){
				puts("NOT MAGIC");
				return 0;
			}
		for(j = i; j < ed.size() && ed[j].w == ed[i].w; ++j)
			dsu.combine(ed[j].u, ed[j].v);
	}
	puts("MAGIC");
	return 0;
}
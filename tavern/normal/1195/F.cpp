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
const int maxn = 3e5 + 5;

class Vector{
public:
	ldb x, y;
	inline Vector(){}
	inline Vector(int _x, int _y): x(_x), y(_y){
		if(x){
			y /= abs(x);
			x /= abs(x);
		}
		else
			(y /= abs(y)) *= INF;
		return;
	}
	bool operator < (const Vector &oth)const{ return MP(x, y) < MP(oth.x, oth.y); }
}slp[maxn];

int n, m, q;
int s[maxn], ans[maxn];
vector<pii> qry[maxn];
map<Vector, int> mp;

class FenwickTree{
private:
	inline void update(int x, int k){
		for(++x; x <= n; x += x & (-x)){
			dat[x] += k;
		}
		return;
	}
public:
	int dat[maxn];
	inline void update(int l, int r, int k){
		if(l > r)
			return;
		update(l, k);
		update(r + 1, -k);
		return;
	}
	inline int query(int x){
		int ret = 0;
		for(++x; x; x -= x & (-x))
			ret += dat[x];
		return ret;
	}
}fen;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		int k;
		scanf("%d", &k);
		s[i] = m;
		int x, y, nx, ny, sx, sy;
		FOR(j, 0, k){
			scanf("%d%d", &nx, &ny);
			if(j)
				slp[m++] = Vector(x - nx, y - ny);
			else
				sx = nx, sy =ny;
			x = nx, y = ny;
		}
		slp[m++] = Vector(x - sx, y - sy);
	}
	s[n] = m;
	scanf("%d", &q);
	FOR(i, 0, q){
		int l, r;
		scanf("%d%d", &l, &r);
		--l; --r;
		qry[r].PB(MP(l, i));
	}
	for(int i = 0, j = 0; i < n; ++i){
		for(; j < s[i + 1]; ++j){
			int pos = (mp.find(slp[j]) != mp.end()) ? mp[slp[j]] : -1;
			fen.update(pos + 1, i, 1);
			mp[slp[j]] = i;
		}
		FOR(x, 0, qry[i].size()){
			ans[qry[i][x].snd] = fen.query(qry[i][x].fst);
		}
	}
	FOR(i, 0, q)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
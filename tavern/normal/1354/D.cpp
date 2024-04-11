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
const int maxn = 1e6 + 5;

class SegmentTree{
private:
	static const int siz = 1048576;
	int dat[siz << 1];
public:
	inline int size(){
		return siz;
	}
	inline void update(int x, int l, int r, int y, int k){
		if(l == r){
			dat[x] += k;
			return;
		}
		int md = l + r >> 1;
		if(y <= md)
			update(x << 1, l, md, y, k);
		else
			update(x << 1 | 1, md + 1, r, y, k);
		dat[x] += k;
		return;
	}
	inline int query(int x, int l, int r, int k){
		if(dat[x] < k)
			return -1;
		if(l == r)
			return l;
		int md = (l + r) >> 1;
		if(dat[x << 1] >= k)
			return query(x << 1, l, md, k);
		return query(x << 1 | 1, md + 1, r, k - dat[x << 1]);
	}
}seg;

int n, q;
int a[maxn], t[maxn];

int main(){
	scanf("%d%d", &n, &q);
	FOR(i, 0, n){
		scanf("%d", a + i);
		seg.update(1, 0, seg.size() - 1, a[i], 1);
	}
	FOR(i, 0, q){
		scanf("%d", t + i);
		if(t[i] > 0)
			seg.update(1, 0, seg.size() - 1, t[i], 1);
		else{
			int res = seg.query(1, 0, seg.size() - 1, -t[i]);
			seg.update(1, 0, seg.size() - 1, res, -1);
		}
	}
	int ans = seg.query(1, 0, seg.size() - 1, 1);
	printf("%d\n", ans == -1 ? 0 : ans);
	return 0;
}
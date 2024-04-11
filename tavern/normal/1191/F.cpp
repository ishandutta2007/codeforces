/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;
int x[maxn], y[maxn];
ll ans;
vector<pii> vec;
map<int, int> mp;

class SegmentTree{
private:
	int siz;
	int dat[maxn << 2];
	inline void build(int x, int l, int r){
		dat[x] = 0;
		if(l == r) return;
		int md = l + r >> 1;
		build(x << 1, l, md);
		build(x << 1 | 1, md + 1, r);
		return;
	}
public:
	inline int size(){return siz;}
	inline void init(int _siz){
		for(siz = 1; siz < _siz; siz <<= 1);
		build(1, 0, siz - 1);
		return;
	}
	inline int query(int x, int l, int r, int s, int t){
		//printf("x = %d l = %d r = %d s = %d t = %d\n", x, l, r, s, t);
		if(l >= s && r <= t)
			return dat[x];
		int md = l + r >> 1, res = 0;
		if(s <= md) res += query(x << 1, l, md, s, t);
		if(t > md) res += query(x << 1 | 1, md + 1, r, s, t);
		return res;
	}
	inline void update(int x, int l, int r, int y){
		//printf("x = %d l = %d r = %d y = %d\n", x, l, r, y);
		if(l == r){
			dat[x] = 1;
			return;
		}
		int md = l + r >> 1;
		if(y <= md) update(x << 1, l, md, y);
		else update(x << 1 | 1, md + 1, r, y);
		dat[x] = dat[x << 1] + dat[x << 1 | 1];
		return;
	}
}seg;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%d%d", x + i, y + i);
		vec.PB(MP(y[i], x[i]));
		mp[x[i]] = 1;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	map<int, int>::iterator it = mp.begin();
	for(int i = 0; it != mp.end(); ++it, ++i) mp[it -> fst] = i;
	seg.init(mp.size());
	for(int i = 0, j; i < n; ){
		for(j = i; j < n && vec[j].fst == vec[i].fst; ++j){
			//printf("i = %d j = %d\n", i, j);
			seg.update(1, 0, seg.size() - 1, mp[vec[j].snd]);
			int nxt;
			if(j + 1 < n && vec[j + 1].fst == vec[i].fst) nxt = mp[vec[j + 1].snd];
			else nxt = -1;
			ll res1 = seg.query(1, 0, seg.size() - 1, mp[vec[j].snd], mp.size() - 1);
			ll res2 = seg.query(1, 0, seg.size() - 1, nxt + 1, mp[vec[j].snd]);
			ans += res1 * res2;
			//printf("%d ans = %d\n", vec[j].snd, ans);
		}
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}
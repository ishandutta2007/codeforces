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
const int maxn = 10005;

class Event{
public:
	int tp, id, x;
	Event(int _tp, int _id, int _x):tp(_tp), id(_id), x(_x){}
	bool operator < (const Event &e){return MP(x, tp) < MP(e.x, e.tp);}
};

int n, cntx, cnty;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
ll ans;
map<int, int> mpx, mpy;
vector<Event> evn;
vector<int> h;

class FenwickTree{
private:
	int dat[maxn];
public:
	inline void init(){memset(dat, 0, sizeof(dat));}
	inline int query(int x){
		int ret = 0;
		for(++x; x; x -= x & (-x)) ret += dat[x];
		return ret;
	}
	inline void update(int x, int k){
		//printf("update : x = %d k = %d\n", x, k);
		for(++x; x <= cnty; x += x & (-x)) dat[x] += k;
		return;
	}
	inline int query(int l, int r){
		if(l > r) return 0;
		return query(r) - query(l - 1);
	}
}fen;

inline bool cmp(const int &i, const int &j){return x1[i] < x1[j];}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		mpx[x1[i]] = mpx[x2[i]] = 1;
		mpy[y1[i]] = mpy[y2[i]] = 1;
	}
	cntx = cnty = 0;
	for(map<int, int>::iterator it = mpx.begin(); it != mpx.end(); ++it, ++cntx) it -> snd = cntx;
	for(map<int, int>::iterator it = mpy.begin(); it != mpy.end(); ++it, ++cnty) it -> snd = cnty;
	FOR(i, 0, n){
		x1[i] = mpx[x1[i]], x2[i] = mpx[x2[i]];
		y1[i] = mpy[y1[i]], y2[i] = mpy[y2[i]];
		if(x1[i] == x2[i]){
			h.PB(i);
			if(y1[i] > y2[i]) swap(y1[i], y2[i]);
		}
		else{
			if(x1[i] > x2[i]) swap(x1[i], x2[i]);
			evn.PB(Event(0, i, x1[i]));
			evn.PB(Event(1, i, x2[i]));
		}
	}
	//FOR(i, 0, n) printf("%d %d %d %d\n", x1[i], y1[i], x2[i], y2[i]);
	sort(h.begin(), h.end(), cmp);
	sort(evn.begin(), evn.end());
	FOR(i, 0, h.size()){
		int h1 = h[i];
		fen.init();
		int p = 0;
		for(p = 0; p < evn.size() && evn[p].x <= x1[h1]; ++p){
			if(!evn[p].tp) fen.update(y1[evn[p].id], 1);
			else fen.update(y1[evn[p].id], -1);
		}
		FOR(j, i + 1, h.size()) if(x1[h[j]] > x1[h[i]]){
			int h2 = h[j];
			for(; p < evn.size() && evn[p].x < x1[h2]; ++p){
				if(evn[p].tp){
					int cur = evn[p].id;
					if(x1[cur] <= x1[h1]) fen.update(y1[evn[p].id], -1);
				}
			}
			int dn = max(y1[h1], y1[h2]);
			int up = min(y2[h1], y2[h2]);
			ll res = fen.query(dn, up);
			//printf("id1 = %d id2 = %d up = %d dn = %d res = %lld\n", id, id2, up, dn, res);
			ans += res * (res - 1) / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

/*
4
1 1 1 2
2 1 2 2
1 1 2 1
1 2 2 2
*/
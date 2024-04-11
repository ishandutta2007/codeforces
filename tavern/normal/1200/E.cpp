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
const int maxn = 1e5 + 5;
const int maxl = 1e6 + 5;
const int P = 1e6 + 3;
const int MOD = 19260817;

int n, tot = 0;
ll pw[maxl], h[maxl];
vector<ll> ph[maxn];
string s[maxn];
char ans[maxl];

inline ll getH(int l, int r){
	//printf("l = %d r = %d\n", l, r);
	if(!l) return h[r];
	return (h[r] - h[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
}

inline bool check(int id, int i, int j){
	REP(k, 0, i) if(s[id][k] != ans[j + k]) return false;
	return true;
}

int main(){
	cin >> n;
	pw[0] = 1;
	FOR(i, 1, maxl) pw[i] = pw[i - 1] * P % MOD;
	FOR(i, 0, n){
		cin >> s[i];
		ph[i].resize(s[i].size());
		FOR(j, 0, s[i].size()){
			ph[i][j] = ((j ? ph[i][j - 1] : 0) * P % MOD + s[i][j]) % MOD;
		}
	}
/*	FOR(i, 0, n){
		FOR(j, 0, s[i].size()) cout << ph[i][j] << " "; cout << endl;
		FOR(j, 0, s[i].size()) cout << sh[i][j] << " "; cout << endl;
	}
*/	cout << s[0];
	FOR(i, 0, s[0].size()){
		ans[tot] = s[0][i];
		h[tot] = ((tot ? h[tot - 1] : 0) * P % MOD + s[0][i]) % MOD;
		++tot;
	}
	FOR(i, 1, n){
		int lb = -1;
		for(int j = s[i].size() - 1; j >= 0; --j){
			int len = s[i].size() - 1 - j;
			if(tot - j - 1 < 0) continue;
			if(ph[i][j] == getH(tot - j - 1, tot - 1) && check(i, j, tot - j - 1)){
				lb = j;
				break;
			}
		}
		FOR(j, lb + 1, s[i].size()){
			cout << s[i][j];
			ans[tot] = s[i][j];
			h[tot] = (h[tot - 1] * P % MOD + s[i][j]) % MOD;
			++tot;
		}
		//cout << endl;
		//FOR(j, 0, tot) cout << h[j] << " ";
		//cout << endl;
	}
	cout << endl;
	return 0;
}
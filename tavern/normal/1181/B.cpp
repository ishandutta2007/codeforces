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

int n, l, r;
string s, ans;
vector<string> vec;

inline bool check(int x){return (s[x] != 0);}

string getAns(int x){
	//cout << "x = " << x << endl;
	string ret = "";
	int a[maxn];
	memset(a, 0, sizeof(a));
	for(int i = x - 1; i >= 0; --i){
		a[(x - 1 - i)] = s[i];
	}
/*	FOR(i, 0, 10)
		cout << a[i] << " ";
	cout << endl;
*/	for(int i = n - 1; i >= x; --i){
		a[(n - 1 - i)] += s[i];
	}
/*	FOR(i, 0, 10)
		cout << a[i] << " ";
	cout << endl;
*/	for(int i = 0; i < maxn - 1; ++i){
		//printf("%d %d\n", i, a[i]);
		if(a[i] >= 10)
			++a[i + 1], a[i] -= 10;
	}
/*	FOR(i, 0, 11)
		cout << a[i] << " ";
	cout << endl;
*/	bool f = false;
	for(int i = maxn - 1; i >= 0; --i){
		if(a[i])
			f = true;
		if(f)
			ret += a[i] + '0';
	}
	//cout << ret << endl;
	return ret;
}

bool cmp(const string &s1, const string &s2){
	if(s1.size() != s2.size())
		return (s1.size() < s2.size());
	FOR(i, 0, s1.size())
		if(s1[i] != s2[i])
			return (s1[i] < s2[i]);
	return 0;
}

int main(){
	cin >> n >> s;
	FOR(i, 0, n) s[i] -= '0';
	if(!(n & 1)){
		if(check(n >> 1)){
			vec.PB(getAns(n >> 1));
		}
		l = (n >> 1) - 1, r = (n >> 1) + 1;
	}
	else
		l = (n >> 1), r = (n >> 1) + 1;
	for(int i = 0; i < 10; --l, ++r){
		if(l > 0 && check(l)){
			vec.PB(getAns(l));
			++i;
		}
		if(r < n && check(r)){
			vec.PB(getAns(r));
			++i;
		}
		if(l <= 0 && r >= n)
			break;
	}
	ans = vec[0];
	FOR(i, 0, vec.size())
		if(cmp(vec[i], ans))
			ans = vec[i];
	cout << ans << endl;
	return 0;
}
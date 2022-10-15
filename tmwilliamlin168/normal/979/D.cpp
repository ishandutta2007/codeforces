#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod7=1000000007LL;
inline ll getint() {
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add(ll _x, ll _y, ll _mod=mod7) {
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline ll sub(ll _x, ll _y, ll _mod=mod7) {
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline ll mul(ll _x, ll _y ,ll _mod=mod7) {
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
ll mypow(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 1ll;
  ll _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
ll mymul(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 0ll;
  ll _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021) {
	clock_t s = clock();
	while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/

const int mxN=1e5;
int q;
bool ad[mxN+1];
vector<int> dvs[mxN+1], ft[mxN+1];

inline void upd(int i, int x) {
	for(int j=x/i; j<=mxN/i; j+=j&-j)
		++ft[i][j];
}

inline int qry1(int i, int x) {
	if(x<=0)
		return 0;
	int r=0;
	for(int j=x/i; j; j-=j&-j)
		r+=ft[i][j];
	return r;
}

inline int qry2(int i, int x, int y) {
	int s=0;
	for(int j=16; j>=0; --j) {
		if(~(x>>j)&1)
			s+=1<<j;
		int l=s, r=min(s+(1<<j)-1, y);
		if(l>r||qry1(i, r)-qry1(i, l-1)<=0)
			s^=1<<j;
	}
	return s<=y&&qry1(i, s)-qry1(i, s-1)?s:-1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(int i=1; i<=mxN; ++i)
		for(int j=i; j<=mxN; j+=i)
			dvs[j].push_back(i);
	for(int i=1; i<=mxN; ++i)
		ft[i]=vector<int>(mxN/i+1);
	cin >> q;
	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int ai;
			cin >> ai;
			if(!ad[ai]) {
				for(int di : dvs[ai])
					upd(di, ai);
				ad[ai]=1;
			}
		} else {
			int xi, ki, si;
			cin >> xi >> ki >> si;
			if(xi%ki)
				cout << "-1\n";
			else
				cout << qry2(ki, xi, si-xi) << "\n";
		}
	}
}
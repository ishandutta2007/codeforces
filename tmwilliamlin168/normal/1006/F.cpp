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

const int mxN=20;
int n, m, s;
ll k, a[mxN][mxN], ans;
unordered_map<ll, int> mps[mxN];

void dfs1(int i, int j, ll x) {
	if(i>=n||j>=m)
		return;
	x^=a[i][j];
	if(i+j==s-1) {
//		cout << i << " " << x << endl;
		++mps[i][x];
		return;
	}
	dfs1(i+1, j, x);
	dfs1(i, j+1, x);
}

void dfs2(int i, int j, ll x) {
	if(i<0||j<0)
		return;
	if(i+j==s-1) {
//		cout << i << " " << x << endl;
		ans+=mps[i][x^k];
		return;
	}
	x^=a[i][j];
	dfs2(i-1, j, x);
	dfs2(i, j-1, x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> a[i][j];
	s=max(n, m);
	for(int i=0; i<s; ++i)
		mps[i].reserve(1<<s);
	dfs1(0, 0, 0);
	dfs2(n-1, m-1, 0);
	cout << ans;
}
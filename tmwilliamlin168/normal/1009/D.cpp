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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	if(m<n-1) {
		cout << "Impossible";
		return 0;
	}
	vector<pair<int, int>> v;
	for(int i=0; i<n-1; ++i)
		v.push_back({i+1, i+2});
	for(int i=1; i<=n&&v.size()<m; ++i) {
		for(int j=1; j<i-1&&v.size()<m; ++j) {
			int a=i, b=j;
			while((a%=b)&&(b%=a));
			if((a^b)==1)
				v.push_back({i, j});
		}
	}
	if(v.size()<m) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible\n";
	for(pair<int, int> p : v)
		cout << p.first << " " << p.second << "\n";
}
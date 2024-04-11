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

int c[10], d[10];
ll ans=0;

ll ca() {
	ll r=1;
	int ds=0;
	for(int i=0; i<10; ++i)
		ds+=d[i];
	for(int i=1; i<=ds; ++i)
		r*=i;
	for(int i=0; i<10; ++i)
		for(int j=1; j<=d[i]; ++j)
			r/=j;
	return r;
}

void rec(int di) {
	if(di>=10) {
		ans+=ca();
		if(d[0]) {
			--d[0];
			ans-=ca();
			++d[0];
		}
	} else {
		if(c[di]) {
			for(int i=1; i<=c[di]; ++i) {
				d[di]=i;
				rec(di+1);
			}
		} else
			rec(di+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	while(n) {
		++c[n%10];
		n/=10;
	}
	rec(0);
	cout << ans;
}
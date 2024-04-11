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

const int mxN=2e5;
int n, m, a[mxN], ps1, ps2;
vector<int> pts[2*mxN+1], fts[2*mxN+1];
long long ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
//		upd(n+ps2-ps1, 1+ps2+ps1);
		for(int j=n+ps2-ps1; j<=2*n; j+=j&-j)
			pts[j].push_back(1+ps2+ps1);
		cin >> a[i];
		if(a[i]>m)
			++ps1;
		else if(a[i]<m)
			--ps1;
		else
			++ps2;
//		ans+=qry(n+ps2-ps1, ps2+ps1);
	}
	for(int i=1; i<=2*n; ++i) {
		sort(pts[i].begin(), pts[i].end());
		fts[i]=vector<int>(pts[i].size()+1);
	}
//	cout << pts[6].size() << endl;
	ps1=0;
	ps2=0;
	for(int i=0; i<n; ++i) {
//		cout << "u " << n+ps2-ps1 << " " << 1+ps2+ps1 << endl;
		for(int j=n+ps2-ps1; j<=2*n; j+=j&-j)
			for(int k=lower_bound(pts[j].begin(), pts[j].end(), 1+ps2+ps1)-pts[j].begin()+1; k<fts[j].size(); k+=k&-k)
				++fts[j][k];
		if(a[i]>m)
			++ps1;
		else if(a[i]<m)
			--ps1;
		else
			++ps2;
//		cout << "a " << n+ps2-ps1 << " " << ps2+ps1 << endl;
		for(int j=n+ps2-ps1; j; j-=j&-j)
			for(int k=upper_bound(pts[j].begin(), pts[j].end(), ps2+ps1)-pts[j].begin(); k; k-=k&-k)
				ans+=fts[j][k];
//		cout << ans << endl;
	}
	cout << ans;
}
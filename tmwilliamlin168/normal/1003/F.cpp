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

int n, a1, ans, s[301][301];
string w[300];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	a1=n-1;
	for(int i=0; i<n; ++i)
		cin >> w[i], a1+=w[i].size();
	ans=a1;
	for(int i=n-2; i>=0; --i)
		for(int j=n-1; j>i; --j)
			s[i][j]=s[j][i]=w[i]==w[j]?1+s[i+1][j+1]:0;
	for(int i=0; i<n; ++i) {
		int sl=-1;
		for(int j=0; i+j<n; ++j) {
			sl+=w[i+j].size();
			int oc=1, k=i+j+1;
			while(k<n) {
				if(s[i][k]>=j+1) {
					k+=j;
					++oc;
				}
				++k;
			}
			if(oc>=2) {
//				cout << i << " " << j << " " << oc << " " << a1-oc*sl << endl;
				ans=min(a1-oc*sl, ans);
			}
		}
	}
	cout << ans;
}
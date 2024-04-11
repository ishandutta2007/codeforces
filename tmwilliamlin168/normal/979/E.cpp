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

const int mxN=50, M=1e9+7;
int n, p, c[mxN], qh, qt=1;
ll p2[mxN+1], dp[mxN+1][mxN+1][mxN+1][mxN+1], ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> p;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	p2[0]=1;
	for(int i=1; i<=n; ++i)
		p2[i]=p2[i-1]*2%M;
	dp[0][0][0][0]=1;
	for(int x1=0; x1<=n; ++x1) {
		for(int x2=0; x2<=n; ++x2) {
			if(x1+x2>n)
				break;
			for(int x3=0; x3<=n; ++x3) {
				if(x1+x2+x3>n)
					break;
				for(int x4=0; x4<=n; ++x4) {
					int i=x1+x2+x3+x4;
					if(i==n&&(x2+x4)%2==p)
						ans=(dp[x1][x2][x3][x4]+ans)%M;
					if(i>=n)
						break;
					dp[x1][x2][x3][x4]%=M;
					if(c[i]!=1) {
						dp[x1+1][x2][x3][x4]+=p2[x1+x2+x3]*(x4?p2[x4-1]:0)%M*dp[x1][x2][x3][x4]%M;
						dp[x1][x2+1][x3][x4]+=p2[x1+x2+x3]*(x4?p2[x4-1]:1)%M*dp[x1][x2][x3][x4]%M;
					}
					if(c[i]!=0) {
						dp[x1][x2][x3+1][x4]+=p2[x3+x4+x1]*(x2?p2[x2-1]:0)%M*dp[x1][x2][x3][x4]%M;
						dp[x1][x2][x3][x4+1]+=p2[x3+x4+x1]*(x2?p2[x2-1]:1)%M*dp[x1][x2][x3][x4]%M;
					}
				}
			}
		}
	}
	cout << ans;
}
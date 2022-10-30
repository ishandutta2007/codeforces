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

int dp[101][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s[2];
	cin >> s[0] >> s[1];
	s[0]+='X';
	s[1]+='X';
	int n=s[0].size();
	for(int i=0; i<n; ++i) {
		if(s[0][i]=='0'&&s[0][i+1]=='0'&&s[1][i]=='0')
			dp[i+1][1]=max(dp[i][0]+1, dp[i+1][1]);
		if(s[0][i]=='0'&&s[1][i+1]=='0'&&s[1][i]=='0')
			dp[i+1][2]=max(dp[i][0]+1, dp[i+1][2]);
		dp[i][1]=max(dp[i][0], dp[i][1]);
		if(s[1][i]=='0'&&s[0][i+1]=='0'&&s[1][i+1]=='0')
			dp[i+2][0]=max(dp[i][1]+1, dp[i+2][0]);
		dp[i][2]=max(dp[i][0], dp[i][2]);
		if(s[0][i]=='0'&&s[0][i+1]=='0'&&s[1][i+1]=='0')
			dp[i+2][0]=max(dp[i][2]+1, dp[i+2][0]);
		dp[i+1][0]=max(max(dp[i][1], dp[i][2]), dp[i+1][0]);
	}
	cout << dp[n][0];
}
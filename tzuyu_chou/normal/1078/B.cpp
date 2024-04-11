/*
_________ _______    _       _________ _        _______   __________________
\__   __/(       )  ( \      \__   __/| \    /\(  ____ \  \__   __/\__   __/
   ) (   | () () |  | (         ) (   |  \  / /| (    \/     ) (      ) (   
   | |   | || || |  | |         | |   |  (_/ / | (__         | |      | |   
   | |   | |(_)| |  | |         | |   |   _ (  |  __)        | |      | |   
   | |   | |   | |  | |         | |   |  ( \ \ | (           | |      | |   
___) (___| )   ( |  | (____/\___) (___|  /  \ \| (____/\     | |      | |   
\_______/|/     \|  (_______/\_______/|_/    \/(_______/     )_(      )_(  
 
_________          _______ _________   _       _________ _        _______   __________________
\__    _/|\     /|(  ____ \\__   __/  ( \      \__   __/| \    /\(  ____ \  \__   __/\__   __/
   )  (  | )   ( || (    \/   ) (     | (         ) (   |  \  / /| (    \/     ) (      ) (   
   |  |  | |   | || (_____    | |     | |         | |   |  (_/ / | (__         | |      | |   
   |  |  | |   | |(_____  )   | |     | |         | |   |   _ (  |  __)        | |      | |   
   |  |  | |   | |      ) |   | |     | |         | |   |  ( \ \ | (           | |      | |   
|\_)  )  | (___) |/\____) |   | |     | (____/\___) (___|  /  \ \| (____/\     | |      | |   
(____/   (_______)\_______)   )_(     (_______/\_______/|_/    \/(_______/     )_(      )_(  
 
https://www youtube com/watch?v=ePpPVE-GGJw
*/

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

int n;
ll dp[10001][101];
ll c[101][101];
int cnt[101];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int type=0;
	cin >> n;
	dp[0][0]=1;
	c[0][0]=1;
	for(int i=1; i<=100; ++i){
		c[i][0]=1;
		for(int j=1; j<=i; ++j) c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	for(int i=1; i<=n; ++i){
		int x;cin >> x;++cnt[x];type+=(cnt[x]==1);
		for(int j=10000; j>=x; --j)
			for(int k=0; k<i ;k++) dp[j][k+1]=add(dp[j-x][k],dp[j][k+1]);
	}
	int ans=0;
	for(int i=1; i<=100; ++i){
		for(int j=ans+1; j<=cnt[i]; ++j){
			if(dp[i*j][j]==c[cnt[i]][j]){
				ans=max(ans,j);
				if(j==cnt[i] && type<=2) ans=n;
			}
			else break;
		}
	}
	cout << ans << endl;
}
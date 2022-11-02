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
const ll M7=1000000007LL;
inline ll getint() {
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add(ll _x, ll _y, ll _M=M7) {
  _x+=_y;
  return _x>=_M ? _x-_M : _x;
}
inline ll sub(ll _x, ll _y, ll _M=M7) {
  _x-=_y;
  return _x<0 ? _x+_M : _x;
}
inline ll mul(ll _x, ll _y ,ll _M=M7) {
  _x*=_y;
  return _x>=_M ? _x%_M : _x;
}
ll mypow(ll _a, ll _x, ll _M) {
  if(_x == 0) return 1ll;
  ll _ret = mypow(mul(_a, _a, _M), _x>>1, _M);
  if(_x & 1) _ret=mul(_ret, _a, _M);
  return _ret;
}
ll mymul(ll _a, ll _x, ll _M) {
  if(_x == 0) return 0ll;
  ll _ret = mymul(add(_a, _a, _M), _x>>1, _M);
  if(_x & 1) _ret=add(_ret, _a, _M);
  return _ret;
}
void sleep(double sec = 1021) {
	clock_t s = clock();
	while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/

const int mxN=505;
const ll M=998244353;
int n, m;
ll dp[mxN][mxN], ndp[mxN][mxN];
ll pla[mxN][mxN], prb[mxN][mxN];
int c[mxN], p[mxN];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	cin >> n;
    for(int i=1; i<=n ;i++){
        cin >> c[i];
        p[c[i]]=i;
    }
    for(int i=1; i<=n ;i++){
        dp[i][i]=dp[i][i-1]=1;
    }
    dp[n+1][n]=1;
    for(int i=n; i>=1 ;i--){
        for(int j=1; j<=n ;j++)
            for(int k=1; k<=n ;k++)
                pla[j][k]=prb[j][k]=ndp[j][k]=0;
        for(int l=p[i]; l>=1 ;l--){
            for(int a=p[i]; a>=l ;a--){
                pla[l][a]=dp[l][a-1]*dp[a][p[i]-1]%M;
                pla[l][a]+=pla[l][a+1];
                if(pla[l][a]>=M) pla[l][a]-=M;
            }
        }
        for(int r=p[i]; r<=n ;r++){
            for(int b=p[i]; b<=r ;b++){
                prb[r][b]=dp[b+1][r]*dp[p[i]+1][b]%M;
                prb[r][b]+=prb[r][b-1];
                if(prb[r][b]>=M) prb[r][b]-=M;
            }
        }
        for(int l=1; l<=p[i] ;l++)
            for(int r=p[i]; r<=n ;r++)
                dp[l][r]=pla[l][l]*prb[r][r]%M;
    }
    cout << dp[1][n] << endl;
}
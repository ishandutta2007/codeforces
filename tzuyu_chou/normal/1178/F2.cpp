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

const ll M=998244353;
const int N=1005, mxM=1e6+3;

int n, m, pl[N], pr[N];
ll dp[N][N], pla[N][N], prb[N][N];
vector<int> f[N];
vector<pair<int, int>> v;
stack<int> s;
bool die[N], ok=1;
map<int, int> mp;
int mj[mxM], c[N];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> c[i];
		if(die[c[i]]) {
			ok=0;
			break;
		}
		while(!s.empty()&&s.top()>c[i]) {
			die[s.top()]=1;
			s.pop();
		}
		s.push(c[i]);
	}
	if(!ok) {
		cout << 0;
		return 0;
	}
	for(int i=1; i<=m; ++i) {
		pr[c[i]]=i;
		f[c[i]].push_back(i);
		if(pl[c[i]]==0)
			pl[c[i]]=i;
	}
	for(int i=1; i<=n; ++i)
		mp[pl[i]]=mp[pr[i]]=1;
	mp[m+1]=1;
	int x=0;
	for(auto &cur : mp)
		mj[cur.first]=++x;
	--x;
	dp[x+1][x]=1;
	for(int i=1; i<=x; ++i)
		dp[i][i]=dp[i][i-1]=1;
	for(int i=n; i>=1 ;i--) {
		for(int j=1; j<=x; ++j)
			for(int k=1; k<=x; ++k)
				pla[j][k]=prb[j][k]=0;
		ll twice=1;
		for(int j=1; j<f[i].size(); ++j) {
			if(f[i][j]==f[i][j-1]+1)
				continue;
			twice=twice*dp[mj[f[i][j-1]+1]][mj[f[i][j]-1]]%M;
		}
		int cl=mj[pl[i]], cr=mj[pr[i]];
		for(int l=cl; l>=1; --l) {
			for(int a=cl; a>=l; --a) {
				pla[l][a]=dp[l][a-1]*dp[a][cl-1]%M;
				pla[l][a]+=pla[l][a+1];
				if(pla[l][a]>=M)
					pla[l][a]-=M;
			}
		}
		for(int r=cr; r<=x; ++r) {
			for(int b=cr; b<=r; ++b) {
				prb[r][b]=dp[b+1][r]*dp[cr+1][b]%M;
				prb[r][b]+=prb[r][b-1];
				if(prb[r][b]>=M)
					prb[r][b]-=M;
			}
		}
		for(int l=1; l<=x; ++l) {
			for(int r=l; r<=x; ++r) {
				if(r<cl||l>cr)
					continue;
				if(l>cl||r<cr)
					dp[l][r]=0;
				else
					dp[l][r]=pla[l][l]*prb[r][r]%M*twice%M;
			}
		}
	}
	cout << dp[1][x] << "\n";
}
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
int n, m, k, eu[mxN], ev[mxN], qu[mxN], qh, qt=1, dist[mxN], as;
vector<int> adj[mxN], pp[mxN], mpp;
string ca, ans[mxN];

void rec(int i) {
	if(as>=k)
		return;
	ans[as++]=ca;
	for(; i<mpp.size(); ++i) {
		for(int j=1; j<pp[mpp[i]].size(); ++j) {
			ca[pp[mpp[i]][j-1]]='0';
			ca[pp[mpp[i]][j]]='1';
			rec(i+1);
		}
		ca[pp[mpp[i]][pp[mpp[i]].size()-1]]='0';
		ca[pp[mpp[i]][0]]='1';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	for(int i=1; i<n; ++i)
		dist[i]=n;
	while(qh<qt) {
		int u=qu[qh++];
		for(int e : adj[u]) {
			int v=eu[e]^ev[e]^u;
			if(dist[v]>dist[u]) {
				dist[v]=dist[u]+1;
				if(!pp[v].size())
					qu[qt++]=v;
				pp[v].push_back(e);
			}
		}
	}
	for(int i=0; i<m; ++i)
		ca+='0';
	for(int i=1; i<n; ++i) {
		ca[pp[i][0]]='1';
		if(pp[i].size()>1)
			mpp.push_back(i);
	}
	rec(0);
	cout << as << "\n";
	for(int i=0; i<as; ++i)
		cout << ans[i] << "\n";
}
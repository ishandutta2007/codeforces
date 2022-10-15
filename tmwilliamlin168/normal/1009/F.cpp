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

inline int in() {
	int result = 0;
	char ch = _getchar_nolock();
	while(true) {
		if(ch >= '0' && ch <= '9')
			break;
		ch = _getchar_nolock();
	}
	result = ch-'0';
	while(true) {
		ch = _getchar_nolock();
		if (ch < '0' || ch > '9')
			break;
		result = result*10 + (ch - '0');
	}
	return result;
}
inline void out(int x) {
	int rev=x, c=0;
	if(!x) {
		_putchar_nolock('0');
		return;
	}
	while(!(rev%10)) {
		++c;
		rev/=10;
	}
	rev=0;
	while(x) {
		rev=rev*10+x%10;
		x/=10;
	}
	while(rev) {
		_putchar_nolock(rev%10+'0');
		rev/=10;
	}
	while(c--)
		_putchar_nolock('0');
}

#define pii pair<int, int>
#define fi first
#define se second

const int mxN=1e6;
int n, d[mxN], mpi[mxN], mpss;
pii ans[mxN];
vector<int> adj[mxN];
map<int, int> mps[mxN];

void dfs(int u, int p) {
	d[u]=p==-1?0:d[p]+1;
	if(adj[u].size()==1&&p!=-1)
		mpi[u]=mpss++;
	else {
		int mv=-1;
		for(int v : adj[u]) {
			if(v==p)
				continue;
			dfs(v, u);
			if(mv==-1||mps[mpi[v]].size()>mps[mpi[mv]].size())
				mv=v;
		}
		mpi[u]=mpi[mv];
		ans[u]=ans[mv];
		for(int v : adj[u]) {
			if(v==p||v==mv)
				continue;
			for(auto it=mps[mpi[v]].begin(); it!=mps[mpi[v]].end(); ++it) {
				int a=mps[mpi[u]][it->first]+=it->second;
				ans[u]=max(pii(a, -it->first), ans[u]);
			}
		}
	}
	++mps[mpi[u]][d[u]];
	ans[u]=max(pii(1, -d[u]), ans[u]);
}

int main() {
	n=in();
	for(int i=0; i<n-1; ++i) {
		int u=in()-1, v=in()-1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	for(int i=0; i<n; ++i) {
//		out(-ans[i].se);
//		_putchar_nolock('\n');
		out(-ans[i].se-d[i]);
		_putchar_nolock('\n');
	}
}
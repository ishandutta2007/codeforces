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

vector<int> adj[400000];
int qh, qt;
pair<int, int> qu[400000];

inline void ae(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d, k;
	cin >> n >> d >> k;
	if(d>=n) {
		cout << "NO";
		return 0;
	}
	if(n==1) {
		cout << (d==0?"YES":"NO");
		return 0;
	}
	if(n==2) {
		cout << (d==1?"YES\n":"NO");
		if(d==1)
			cout << "1 2";
		return 0;
	}
	if(k<2) {
		cout << "NO";
		return 0;
	}
	for(int i=0; i<d; ++i) {
		ae(i, i+1);
		qu[qt++]={i, min(i, d-i)};
	}
	int n2=d+1;
	while(qh<qt&&n2<n) {
		pair<int, int> pi = qu[qh++];
		if(pi.second<=0)
			continue;
		int dg=pi.first<=d?k-2:k-1;
		for(int i=0; i<dg&&n2<n; ++i) {
			int j=n2++;
			ae(pi.first, j);
			qu[qt++]={j, pi.second-1};
		}
	}
	if(n2<n) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		for(int j : adj[i])
			if(i<j)
				cout << i+1 << " " << j+1 << "\n";
}
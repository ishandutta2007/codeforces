/*
_________            _______  _        _        _______    _        _        _______          
\__   __/  |\     /|(  ___  )( (    /|( (    /|(  ___  )  | \    /\( (    /|(  ___  )|\     /|
   ) (     | )   ( || (   ) ||  \  ( ||  \  ( || (   ) |  |  \  / /|  \  ( || (   ) || )   ( |
   | |     | | _ | || (___) ||   \ | ||   \ | || (___) |  |  (_/ / |   \ | || |   | || | _ | |
   | |     | |( )| ||  ___  || (\ \) || (\ \) ||  ___  |  |   _ (  | (\ \) || |   | || |( )| |
   | |     | || || || (   ) || | \   || | \   || (   ) |  |  ( \ \ | | \   || |   | || || || |
___) (___  | () () || )   ( || )  \  || )  \  || )   ( |  |  /  \ \| )  \  || (___) || () () |
\_______/  (_______)|/     \||/    )_)|/    )_)|/     \|  |_/    \/|/    )_)(_______)(_______)
                                                                                              
 _        _        _______             _        _        _______             _        _        _______          
| \    /\( (    /|(  ___  )|\     /|  | \    /\( (    /|(  ___  )|\     /|  | \    /\( (    /|(  ___  )|\     /|
|  \  / /|  \  ( || (   ) || )   ( |  |  \  / /|  \  ( || (   ) || )   ( |  |  \  / /|  \  ( || (   ) || )   ( |
|  (_/ / |   \ | || |   | || | _ | |  |  (_/ / |   \ | || |   | || | _ | |  |  (_/ / |   \ | || |   | || | _ | |
|   _ (  | (\ \) || |   | || |( )| |  |   _ (  | (\ \) || |   | || |( )| |  |   _ (  | (\ \) || |   | || |( )| |
|  ( \ \ | | \   || |   | || || || |  |  ( \ \ | | \   || |   | || || || |  |  ( \ \ | | \   || |   | || || || |
|  /  \ \| )  \  || (___) || () () |  |  /  \ \| )  \  || (___) || () () |  |  /  \ \| )  \  || (___) || () () |
|_/    \/|/    )_)(_______)(_______)  |_/    \/|/    )_)(_______)(_______)  |_/    \/|/    )_)(_______)(_______)
 
https://www youtube com/watch?v=i0p1bmr0EmE
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

const int mxN=1e6;
int n, a[mxN], b[mxN], e[mxN][2];
string t[mxN];
bool c[mxN];

bool d(string &s, bool a, bool b) {
	if(s=="AND")
		return a&&b;
	if(s=="OR")
		return a||b;
	if(s=="XOR")
		return a^b;
	if(s=="NOT")
		return !a;
}

void dfs1(int i) {
	if(t[i]=="IN") {
		c[i]=a[i]==0;
		return;
	}
	dfs1(a[i]);
	if(t[i]=="NOT") {
		c[i]=!c[a[i]];
		return;
	}
	dfs1(b[i]);
	c[i]=d(t[i], c[a[i]], c[b[i]]);
}

void dfs2(int i, int j) {
	if(j!=-1)
		for(int k=0; k<2; ++k)
			e[i][k]=e[j][d(t[j], k, c[a[j]^b[j]^i])];
	if(t[i]!="IN") {
		dfs2(a[i], i);
		if(t[i]!="NOT")
			dfs2(b[i], i);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> t[i] >> a[i], --a[i];
		if(t[i]!="NOT"&&t[i]!="IN")
			cin >> b[i], --b[i];
	}
	dfs1(0);
//	for(int i=0; i<n; ++i)
//		cout << c[i];
//	cout << endl;
	e[0][1]=1;
	dfs2(0, -1);
	for(int i=0; i<n; ++i)
		if(t[i]=="IN")
			cout << e[i][a[i]==-1];
}
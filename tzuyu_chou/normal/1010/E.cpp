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

const int mxN=1e5;
int xm, ym, zm, n, m, k, ei, xl=mxN, xr, yl=mxN, yr, zl=mxN, zr, ea[mxN];
vector<int> ft[mxN+1], ftp[mxN+1];

struct event {
	int x1, x2, y1, y2, z, i, a;
	inline bool operator<(const event &o) const {
		return z==o.z?i<o.i:z<o.z;
	}
} es[3*mxN];

inline int qry(int x, int y) {
	int r=0;
	for(; x>0; x-=x&-x)
		for(int j=lower_bound(ftp[x].begin(), ftp[x].end(), y)-ftp[x].begin(); j>0; j-=j&-j)
			r+=ft[x][j];
//	cout << x << " " << y << " " << r << endl;
	return r;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> xm >> ym >> zm >> n >> m >> k;
	for(int i=0; i<n; ++i) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi, --xi, --yi, --zi;
		xl=min(xi, xl);
		xr=max(xi, xr);
		yl=min(yi, yl);
		yr=max(yi, yr);
		zl=min(zi, zl);
		zr=max(zi, zr);
	}
	for(int i=0; i<m; ++i) {
		cin >> es[i].x1 >> es[i].y1 >> es[i].z, --es[i].x1, --es[i].y1, --es[i].z;
		if(es[i].x1>=xl&&es[i].x1<=xr&&es[i].y1>=yl&&es[i].y1<=yr&&es[i].z>=zl&&es[i].z<=zr) {
			cout << "INCORRECT";
			return 0;
		}
		es[i].i=-1;
		for(int j=es[i].x1+1; j<=xm; j+=j&-j)
			ftp[j].push_back(es[i].y1);
	}
	cout << "CORRECT\n";
	for(int i=0; i<k; ++i) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi, --xi, --yi, --zi;
		es[m+2*i]={min(xi, xl), max(xi, xr), min(yi, yl), max(yi, yr), min(zi, zl)-1, i, -1};
		es[m+2*i+1]={min(xi, xl), max(xi, xr), min(yi, yl), max(yi, yr), max(zi, zr), i, 1};
		if(xi>=xl&&xi<=xr&&yi>=yl&&yi<=yr&&zi>=zl&&zi<=zr)
			ea[i]=-1;
	}
	for(int i=1; i<=xm; ++i) {
		sort(ftp[i].begin(), ftp[i].end());
		ft[i]=vector<int>(ftp[i].size()+1);
//		cout << "fts " << ft[i].size() << endl;
	}
	sort(es, es+m+2*k);
	for(int ei=0; ei<m+2*k; ++ei) {
//		cout << es[ei].x1 << " " << es[ei].x2 << " " << es[ei].y1 << " " << es[ei].y2 << " " << es[ei].z << " " << es[ei].i << " " << es[ei].a << endl;
		if(es[ei].i!=-1)
			ea[es[ei].i]+=es[ei].a*(qry(es[ei].x2+1, es[ei].y2+1)-qry(es[ei].x1, es[ei].y2+1)-qry(es[ei].x2+1, es[ei].y1)+qry(es[ei].x1, es[ei].y1));
		else
			for(int j=es[ei].x1+1; j<=xm; j+=j&-j)
				for(int k=lower_bound(ftp[j].begin(), ftp[j].end(), es[ei].y1)-ftp[j].begin()+1; k<ft[j].size(); k+=k&-k)
					++ft[j][k];
	}
	for(int i=0; i<k; ++i)
		cout << (ea[i]==0?"UNKNOWN":(ea[i]<0?"OPEN":"CLOSED")) << "\n";//, cout << ea[i] << endl;
}
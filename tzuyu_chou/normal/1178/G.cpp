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

//#define DBG
#define dbgn(x) dbg(x, #x)
#ifdef DBG
template<typename T>
void dbg(T x, string s="") {
	cout << s << " " << x << endl;
}
template<typename T>
void dbg(vector<T> v, string s="") {
	cout << s << endl;
	for(int i : v)
		cout << i << " ";
	cout << endl;
}
#else
template<typename T>
void dbg(T x, string s="") {}
#endif
/*********default*********/

const int mxN=2e5, B=200, mxNB=(mxN-1)/B+1;
int n, q, p[mxN], dt, ds[mxN], de[mxN];
ll a[mxN+1], b[mxN+1];
vector<int> c[mxN];

void dfs(int u=0) {
	ds[u]=dt++;
	for(int v : c[u])
		dfs(v);
	de[u]=dt;
}

struct cht {
	ll a[B], b[B];
	int qh, qt=0, p[B];
	void al(ll ai, ll bi) {
		if(qt&&a[qt-1]==ai) {
			if(bi<b[qt-1])
				return;
			--qt;
		}
		while(qt>1&&(long double)(b[qt-1]-b[qt-2])/(a[qt-2]-a[qt-1])>=(long double)(bi-b[qt-1])/(a[qt-1]-ai))
			--qt;
		a[qt]=ai;
		b[qt]=bi;
		++qt;
	}
	ll qry(ll x) {
		while(qh+1<qt&&a[qh+1]*x+b[qh+1]>a[qh]*x+b[qh])
			++qh;
		return a[qh]*x+b[qh];
	}
	void bld(vector<pair<ll, ll>> &v) {
		qh=qt=0;
		//sort(v.begin(), v.end());
		for(int i=0; i<v.size(); ++i)
			al(v[p[i]].first, v[p[i]].second);
	}
};

struct ds {
	ll a[mxN], b[mxN], lz[mxNB];
	cht c[mxNB];
	void psh(int i) {
		for(int j=i*B; j<min((i+1)*B, n); ++j)
			a[j]+=lz[i];
		lz[i]=0;
	}
	void cmb(int i) {
		vector<pair<ll, ll>> vl;
		for(int j=i*B; j<min((i+1)*B, n); ++j)
			vl.push_back(pair<ll, ll>(b[j], a[j]*b[j]));
		if(!c[i].qt) {
			iota(c[i].p, c[i].p+min(B, n-i*B), 0);
			sort(c[i].p, c[i].p+min(B, n-i*B), [&](const int &i, const int &j) {
				return vl[i].first<vl[j].first;
			});
		}
		c[i].bld(vl);
	}
	void upd(int l1, int r1, int x) {
		for(int i=l1/B; i<=r1/B; ++i) {
			int l2=i*B, r2=(i+1)*B-1;
			if(l1<=l2&&r2<=r1) {
				lz[i]+=x;
			} else {
				psh(i);
				l2=max(l1, l2);
				r2=min(r1, r2);
				for(int j=l2; j<=r2; ++j)
					a[j]+=x;
				cmb(i);
			}
		}
	}
	ll qry(int l1, int r1) {
		ll r=0;
		for(int i=l1/B; i<=r1/B; ++i) {
			int l2=i*B, r2=(i+1)*B-1;
			if(l1<=l2&&r2<=r1) {
				r=max(r, c[i].qry(lz[i]));
			} else {
				l2=max(l1, l2);
				r2=min(r1, r2);
				for(int j=l2; j<=r2; ++j)
					r=max(r, (a[j]+lz[i])*b[j]);
			}
		}
		return r;
	}
} dx, dn;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for(int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		c[p[i]].push_back(i);
	}
	dfs();
	/*
	for(int i=0; i<n; ++i) {
		int ai, bi;
		cin >> ai >> bi;
		a[ds[i]]+=ai;
		a[de[i]]-=ai;
		b[ds[i]]+=bi;
		b[de[i]]-=bi;
	}
	*/
	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;
		a[ds[i]]+=ai;
		a[de[i]]-=ai;
	}
	for(int i=0; i<n; ++i) {
		int bi;
		cin >> bi;
		b[ds[i]]+=bi;
		b[de[i]]-=bi;
	}
	for(int i=0; i<n; ++i) {
		a[i+1]+=a[i];
		b[i+1]+=b[i];
		dbgn(a[i]);
		dbgn(b[i]);
		int c=1;
		dx.a[i]=dn.a[i]=a[i];
		dx.b[i]=b[i];
		dn.b[i]=-b[i];
	}
	for(int i=0; i*B<n; ++i) {
		dx.cmb(i);
		dn.cmb(i);
	}
	while(q--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int v, x;
			cin >> v >> x, --v;
			dx.upd(ds[v], de[v]-1, x);
			dn.upd(ds[v], de[v]-1, x);
		} else {
			int v;
			cin >> v, --v;
			cout << max(dx.qry(ds[v], de[v]-1), dn.qry(ds[v], de[v]-1)) << "\n";
		}
	}
}
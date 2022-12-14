#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;
const int MAXM = 800007;

struct eT
{
	eT () : ch ( false ) {}

	void setd ( int _u, int _v, int _last )
	{
		u = _u, v = _v, last = _last;
	}

	int u, v, last;
	bool ch;
}edge[MAXM];

int n, m, s, t, ds, dt, k;
int la[MAXN];
int num[MAXN];
bool cs[MAXN];
int chs[MAXN];
bool ct[MAXN];
int cht[MAXN];

void init ();
void input ();
void work ();

void dfs ( int now, int c );



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	cin >> n >> m;
	int u, v;
	k = 0;
	memset ( la, -1, sizeof ( la ) );
	lp ( i, 0, m ){
		cin >> u >> v;
		edge[k].setd ( u, v, la[u] );
		la[u] = k++;
		edge[k].setd ( v, u, la[v] );
		la[v] = k++;
	}
	cin >> s >> t >> ds >> dt;
}

void work ()
{
	// main work

	if ( !ds || !dt ){
		cout << "No" << endl;
		return;
	}

	memset ( num, 0, sizeof ( num ) );
	int ncc = 1;
	lpi ( i, 1, n ){
		if ( i ^ s && i ^ t && !num[i] ) dfs ( i, ncc++ );
	}

	memset ( cs, false, sizeof ( cs ) );
	memset ( ct, false, sizeof ( ct ) );
	for ( int i = la[s]; i ^ -1; i = edge[i].last ) cs[num[edge[i].v]] = true, chs[num[edge[i].v]] = i;
	for ( int i = la[t]; i ^ -1; i = edge[i].last ) ct[num[edge[i].v]] = true, cht[num[edge[i].v]] = i;

	lp ( i, 1, ncc ){
		if ( cs[i] && !ct[i] ){
			cs[i] = false;
			edge[chs[i]].ch = true;
			--ds;
		}else if ( ct[i] && !cs[i] ){
			ct[i] = false;
			edge[cht[i]].ch = true;
			--dt;
		}
	}

	if ( ds < 0 || dt < 0 ){
		cout << "No" << endl;
		return;
	}

	bool flag = true;
	lp ( i, 1, ncc ){
		if ( cs[i] ){
			if ( flag ){
				edge[chs[i]].ch = edge[cht[i]].ch = true;
				flag = false;
				cs[i] = ct[i] = false;
				--ds;
				--dt;
			}else if ( ds > 0 ){
				edge[chs[i]].ch = true;
				cs[i] = ct[i] = false;
				--ds;
			}else{
				edge[cht[i]].ch = true;
				cs[i] = ct[i] = false;
				--dt;
			}
		}
	}

	if ( flag ){
		bool suc = false;
		for ( int i = la[s]; i ^ -1; i = edge[i].last ){
			if ( edge[i].v == t ){
				edge[i].ch = true;
				--ds; --dt;
				suc = true;
				break;
			}
		}

		if ( !suc ){
			cout << "No" << endl;
			return;
		}
	}

	if ( ds >= 0 && dt >= 0 ){
		cout << "Yes" << endl;
		lp ( i, 0, k ){
			if ( edge[i].ch ) cout << edge[i].u << " " << edge[i].v << endl;
		}
	}else
		cout << "No" << endl;
}



void dfs ( int now, int c )
{
	num[now] = c;
	for ( int i = la[now]; i ^ -1; i = edge[i].last ){
		if ( edge[i].v ^ s && edge[i].v ^ t && !num[edge[i].v] ){
			edge[i].ch = true;
			dfs ( edge[i].v, c );
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
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
const int MAXN = 400007;
const int MOD = SC ( int, 1e9 + 7 );

class ftT
{
public:
	void upd ( int p, int x )
	{
		for ( ; p < MAXN; p += p & -p ) data[p] += x;
	}

	int sum ( int p )
	{
		int ans = 0;
		for ( ; p; p ^= p & -p ) ans += data[p];
		return ans;
	}

	int query ( int l, int r )
	{
		return sum ( r ) - sum ( l - 1 );
	}

private:
	int data[MAXN];
}ft;

int n, m;
int tp[MAXN], qa[MAXN];
int stb[MAXN];
bool vis[MAXN];

void init ();
void input ();
void work ();

int getnext ( int ni )
{
	lpi ( i, ni + 1, m ) {
		if ( tp[i] == 2 ) {
			return qa[i];
		}
	}
	return -1;
}



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d", &m );
	char stp[13];
	lpi ( i, 1, m ) {
		scanf ( "%s%d", stp, &qa[i] );
		tp[i] = ( stp[1] == 'D' ) ? 1 : 2;
	}
}

void work ()
{
	// main work

	lpi ( i, 1, m ) stb[++n] = qa[i];
	sort ( stb + 1, stb + 1 + n );
	n = unique ( stb + 1, stb + 1 + n ) - stb - 1;
	lpi ( i, 1, m ) qa[i] = lower_bound ( stb + 1, stb + 1 + n, qa[i] ) - stb;

	int ans = 2, np = getnext ( 0 );
	if ( np == -1 ) {
		int nc = 0;
		lpi ( i, 1, m ) if ( tp[i] == 1 ) ++nc;
		cout << ( nc + 1 ) << endl;
		return;
	}
	lpi ( i, 1, m ) {
		if ( tp[i] == 1 ) {
			vis[qa[i]] = true;
			ft.upd ( qa[i], 1 );
		} else {
			vis[qa[i]] = false;
			ft.upd ( qa[i], -1 );
			np = getnext ( i );
			if ( np == -1 ) {
				int nl = 0, nr = n + 1;
				lpd ( j, qa[i], 0 ) {
					if ( vis[j] ) {
						nl = j;
						break;
					}
				}
				lpi ( j, qa[i], n ) {
					if ( vis[j] ) {
						nr = j;
						break;
					}
				}
				int nc = 0;
				lpi ( j, i, m ) if ( tp[j] == 1 && qa[j] > nl && qa[j] < nr ) ++nc;
				ans = SC ( LL, ans ) * ( nc + 1 ) % MOD;
				break;
			}
			bool flag = true;
			if ( np > qa[i] && ft.query ( qa[i] + 1, np - 1 ) ) flag = false;
			else if ( np < qa[i] && ft.query ( np + 1, qa[i] - 1 ) ) flag = false;
			if ( !flag ) {
				cout << 0 << endl;
				return;
			}
			if ( !vis[np] ) {
				ans = SC ( LL, ans ) * 2 % MOD;
			}
		}
	}
	cout << ans << endl;
}
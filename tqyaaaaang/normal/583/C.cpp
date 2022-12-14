#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define lp(loop,start,end) for ( int loop = start; loop < end; loop++ )
#define lpd(loop,start,end) for ( int loop = start; loop > end; loop-- )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; loop++ )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; loop-- )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 505;

int g[MAXN*MAXN];
int a[MAXN];
int seq[MAXN*MAXN];
map < int, int > m;
map < int, int > ::iterator it;

int gcd ( int x, int y )
{
	return ( ( y == 0 ) ? x : gcd ( y, x%y ));
}

bool _cmp ( int a, int b )
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio ( false );

	int n, ok = 0, now, size;
	cin >> n;
	lp ( i, 0, n*n ){
		cin >> g[i];

		it = m.find ( g[i] );
		if ( it == m.end() ){
			m.insert ( make_pair ( g[i], 1 ) );
		}else{
			(*it).second++;
		}
	}

	for ( it = m.begin(); it != m.end(); it++ ){
		if ( (*it).second & 1 ){
			a[ok] = (*it).first;
			(*it).second--;
			ok++;
		}
	}

	lp ( i, 0, ok ){
		lp ( j, i+1, ok ){
			m[gcd(a[i],a[j])] -= 2;
		}
	}

	int k = 0;
	for ( it = m.begin(); it != m.end(); it++ ){
		now = (*it).first;
		size = (*it).second;
		(*it).second = -1;
		lp ( i, 0, size ){
			seq[k] = now;
			k++;
		}
	}

	sort ( seq, seq+k, _cmp );

	lp ( i, 0, k ){
		it = m.find ( seq[i] );
		if ( (*it).second == -1 ) (*it).second = i;
	}

	int loop = 0, ind;
	while ( ok < n ){
		if ( seq[loop] > -1 ){
			a[ok] = seq[loop];
			lp ( j, 0, ok ){
				it = m.find( gcd(a[ok],a[j]) );
				seq[(*it).second] = seq[(*it).second+1] = -1;
				(*it).second += 2;
			}
			it = m.find ( a[ok] );
			seq[(*it).second] = -1;
			(*it).second++;
			ok++;
		}
		loop++;
	}

	lp ( i, 0, n ) cout << a[i] << " ";
	cout << endl;
}
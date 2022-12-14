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
const int MAXN = 50007;
const int BASE = 26;

int n;
char s[MAXN];
int cc[BASE];

void init ();
void input ();
void work ();

void output ( int l, int r );



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

	cin >> s;
}

void work ()
{
	// main work

	n = strlen ( s );

	if ( n < BASE ){
		cout << -1 << endl;
		return;
	}

	memset ( cc, 0, sizeof ( cc ) );
	int l, r;
	l = 0, r = BASE;
	lp ( i, 0, BASE ) if ( s[i] ^ '?' ) ++cc[s[i]-'A'];

	bool flag = true;
	lp ( i, 0, BASE ){
		if ( cc[i] >= 2 ){
			flag = false;
			break;
		}
	}

	bool suc = false;
	if ( flag ){
		suc = true;
		output ( l, r );
	}else if ( n > BASE ){
		for ( ; r < n; ){
			if ( s[r] ^ '?' ) ++cc[s[r]-'A'];
			if ( s[l] ^ '?' ) --cc[s[l]-'A'];
			++l, ++r;

			flag = true;
			lp ( i, 0, BASE ){
				if ( cc[i] >= 2 ){
					flag = false;
					break;
				}
			}

			if ( flag ){
				suc = true;
				output ( l, r );
				break;
			}
		}
	}

	if ( !suc ) cout << -1 << endl;
}

void output ( int l, int r )
{
	lp ( i, 0, l ) cout << ( ( s[i] ^ '?' ) ? s[i] : 'A' );
	lp ( i, l, r ){
		if ( s[i] ^ '?' ) cout << s[i];
		else{
			lp ( i, 0, BASE ){
				if ( !cc[i] ){
					++cc[i];
					cout << SC ( char, i + 'A' );
					break;
				}
			}
		}
	}
	lp ( i, r, n ) cout << ( ( s[i] ^ '?' ) ? s[i] : 'A' );

	cout << endl;
}
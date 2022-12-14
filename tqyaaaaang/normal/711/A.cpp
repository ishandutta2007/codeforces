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
const int MAXN = 1007;
const int MAXL = 17;

int n;
char s[MAXN][MAXL];

void init ();
void input ();
void work ();



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

	cin >> n;
	lp ( i, 0, n ) cin >> s[i];
}

void work ()
{
	// main work

	bool flag = false;
	lp ( i, 0, n ){
		if ( s[i][0] == 'O' && s[i][1] == 'O' ){
			s[i][0] = s[i][1] = '+';
			flag = true;
			break;
		}
		if ( s[i][3] == 'O' && s[i][4] == 'O' ){
			s[i][3] = s[i][4] = '+';
			flag = true;
			break;
		}
	}

	if ( flag ){
		cout << "YES" << endl;
		lp ( i, 0, n ) cout << s[i] << endl;
	}else
		cout << "NO" << endl;
}
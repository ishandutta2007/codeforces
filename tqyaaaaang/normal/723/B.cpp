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
const int MAXL = 277;

int n;
char s[MAXL];
int sum = 0, maxi = 0, tmp = 0;
int inpar = 0;

void init ();
void input ();
void work ();

void upd ();



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
	cin >> s;
}

void work ()
{
	// main work

	lp ( i, 0, n ){
		if ( s[i] == '_' ){
			upd();
		}else if ( s[i] == '(' ){
			upd();
			++inpar;
		}else if ( s[i] == ')' ){
			upd();
			--inpar;
		}else ++tmp;
	}

	upd();

	cout << maxi << " " << sum << endl;
}



void upd ()
{
	if ( inpar ){
		if ( tmp ) ++sum, tmp = 0;
	}else{
		maxi = qmax ( maxi, tmp );
		tmp = 0;
	}
}
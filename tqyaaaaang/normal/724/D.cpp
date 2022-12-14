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
const int MAXN = 100007;
const int BASE = 26;

int m;
char s[MAXN];
char ans[MAXN];
AR(int) pos[BASE];
bool cho[MAXN];
bool isin[MAXN];

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
	
	scanf ( "%d%s", &m, s );
}

void work ()
{
	// main work

	int n = strlen ( s );
	lp ( i, 0, n ){
		pos[s[i]-'a'].push_back ( i );
	}

	memset ( cho, false, sizeof ( cho ) );
	bool suc;
	int size, tmp;
	int len = 0;
	lp ( i, 0, BASE ){
		size = pos[i].size();
		lp ( j, 0, size )
			cho[pos[i][j]] = true;

		tmp = 0;
		suc = true;
		lp ( j, 0, n ){
			if ( cho[j] ){
				tmp = 0;
			}else{
				++tmp;
				if ( tmp == m ){
					suc = false;
					break;
				}
			}
		}

		if ( suc ){
			int cc = 0, last = 0;
			tmp = 0;
			memset ( isin, false, sizeof ( isin ) );
			lp ( j, 0, size ){
				cho[pos[i][j]] = false, isin[pos[i][j]] = true;
			}
			lp ( j, 0, n ){
				if ( cho[j] )
					tmp = 0;
				else{
					if ( isin[j] ){
						last = j;
					}
					++tmp;
					if ( tmp == m ){
						++cc;
						tmp = j-last;
					}
				}
			}
			lp ( j, 0, cc ) ans[len++] = i+'a';
			break;
		}else{
			lp ( j, 0, size ) ans[len++] = i+'a';
		}
	}

	ans[len] = '\0';
	printf ( "%s\n", ans );
}
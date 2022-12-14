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
const int MAXN = 18;
const int MAX2 = (1<<18);

struct qT
{
	int st, last, cc;
}t, now;

LL dp[MAX2][MAXN];
bool vis[MAX2][MAXN];

int sr[MAXN];
LL rules[MAXN][MAXN];
LL sat[MAXN];

int main()
{
	ios::sync_with_stdio ( false );

	memset ( sr, 0, sizeof ( sr ) );
	memset ( dp, 0, sizeof ( dp ) );
	memset ( vis, false, sizeof ( vis ) );
	memset ( rules, 0, sizeof ( rules ) );

	int n, m, k, x, y;
	LL maxi = 0;
	cin >> n >> m >> k;
	lp ( i, 0, n ) cin >> sat[i];
	lp ( i, 0, k ){
		cin >> x >> y;
		cin >> rules[x-1][y-1];
	}

	queue < qT > q;
	lp ( i, 0, n ){
		t.st = ( 1 << i ), t.last = i, t.cc = 1;
		dp[t.st][t.last] = sat[i];
		vis[t.st][t.last] = true;
		q.push ( t );
	}
	while ( !q.empty () ){
		now = q.front();
		q.pop();

		if ( now.cc < m ){
			lp ( i, 0, n ){
				if ( !( now.st & ( 1 << i ) ) ){
					t.st = now.st + ( 1 << i ), t.last = i, t.cc = now.cc+1;
					dp[t.st][i] = qmax ( dp[t.st][i], dp[now.st][now.last] + rules[now.last][i] + sat[i] );

					if ( !vis[t.st][i] ){
						q.push ( t );
						vis[t.st][i] = true;
					}
				}
			}
		}else maxi = qmax ( maxi, dp[now.st][now.last] );
	}

	cout << maxi << endl;
}
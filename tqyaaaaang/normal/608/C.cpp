#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const int MAXSIZE = 1000005;

struct beaconType
{
	int place, power;
};

int mmap[MAXSIZE], pre[MAXSIZE], dp[MAXSIZE];

int main()
{
	ios::sync_with_stdio ( false );

	int n, a, b, mini, now;

	cin >> n;

	vector < beaconType > beacons ( n+1 );
	lp ( i, 1, (n+1) ){
		cin >> a >> b;
		beacons[i].place = a;
		beacons[i].power = b;

		mmap[a] = i;
	}

	pre[0] = ( mmap[0] ? 1 : 0 );
	lp ( i, 1, MAXSIZE )
		pre[i] = pre[i-1] + ( mmap[i] ? 1 : 0 );
	
	dp[0] = 0;
	lp ( i, 1, MAXSIZE ){
		if ( mmap[i] ){
			if ( i-beacons[mmap[i]].power-1 < 0 ){
				dp[i] = pre[i-1];
			}else{
				dp[i] = dp[i-beacons[mmap[i]].power-1] + pre[i-1] - pre[i-beacons[mmap[i]].power-1];
			}
		}else
			dp[i] = dp[i-1];
	}

	mini = INF;
	lp ( i, 0, MAXSIZE ){
		now = dp[i] + n - pre[i];

		if ( now < mini ) mini = now;
	}

	cout << mini << endl;
}
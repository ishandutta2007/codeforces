#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

int main()
{
	ios::sync_with_stdio ( false );

	int n, k, nl, kl, maxi = 0;

	cin >> n >> k;

	vector < int > items ( n );
	
	lp( i, 0, n ) cin >> items[i];

	nl = n;
	kl = k;
	
	while ( ( ( nl + 1 ) / 2 ) < kl ){
		nl--; kl--;

		if ( maxi < items[nl] ) maxi = items[nl];

		if ( nl == 0 ) break;
	}

	if ( ( nl & 1 ) && nl ){
		nl--; kl--;
		if ( maxi < items[nl] ) maxi = items[nl];
	}

	lp( i, 0, ( nl / 2 ) ) if ( maxi < ( items[i] + items[nl-i-1] ) ) maxi = items[i] + items[nl-i-1];

	cout << maxi << endl;
}
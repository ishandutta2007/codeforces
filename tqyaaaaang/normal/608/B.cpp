// CodeForces
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

	string a, b;
	cin >> a >> b;

	int size = b.size(), as = a.size();
	LL ans = 0;

	vector < int > n0 ( size+1 );
	vector < int > n1 ( size+1 );

	n0[0] = n1[0] = 0;
	lp ( i, 1, (size+1) ){
		n0[i] = n0[i-1];
		n1[i] = n1[i-1];
		if ( b[i-1] == '0' )
			n0[i]++;
		else
			n1[i]++;
	}

	lp ( i, 0, as ){
		if ( a[i] == '0' ){
			ans += n1[size-as+i+1] - n1[i];
		}else{
			ans += n0[size-as+i+1] - n0[i];
		}
	}

	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

const char *outputs[3] = { "Possible", "Ambiguity", "Impossible" };

int main()
{
	ios::sync_with_stdio ( false );

	bool suc = true, mul = false;
	int n, m;
	cin >> n >> m;
	AR(int) f ( n+1 );
	AR(int) ff ( n+1, 0 );
	AR(int) b ( m );
	AR(int) a ( m );
	AR(bool) mu ( n+1, false );

	lp ( i, 1, (n+1) ){
		cin >> f[i];
	}
	lp ( i, 0, m ){
		cin >> b[i];
	}
	
	lp ( i, 1, (n+1 ) ){
		if ( ff[f[i]] ){
			mu[f[i]] = true;
		}
		ff[f[i]] = i;
	}

	lp ( i, 0, m ){
		if ( !ff[b[i]] ){
			suc = false;
			break;
		}

		if ( mu[b[i]] ){
			mul = true;
		}

		a[i] = ff[b[i]];
	}

	if ( !suc ){
		cout << outputs[2] << endl;
	}else if ( mul ){
		cout << outputs[1] << endl;
	}else{
		cout << outputs[0] << endl;
		lp ( i, 0, (m-1) ){
			cout << a[i] << " ";
		}
		cout << a[m-1] << endl;
	}
}
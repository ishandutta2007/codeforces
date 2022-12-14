#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )
#define cy(k,b,x) ( (k) * (x) + (b) );

const int INF = 0x3fffffff;
const LD IG = 1e-8;

struct lineT
{
	int k, b;
};

struct nodeT
{
	bool operator < ( nodeT &a ) const
	{
		return val < a.val;
	}

	int id;
	LD val;
};

int main()
{
	ios::sync_with_stdio ( false );

	int n, k, b;
	LD val, x1, x2;
	cin >> n >> x1 >> x2;
	vector < lineT > l ( n );
	lp ( i, 0, n )
		cin >> l[i].k >> l[i].b;

	x1 += IG;
	x2 -= IG;
	vector < nodeT > n1 ( n ), n2 ( n );

	lp ( i, 0, n ){
		n1[i].id = n2[i].id = i;
		n1[i].val = cy ( l[i].k, l[i].b, x1 );
		n2[i].val = cy ( l[i].k, l[i].b, x2 );
	}

	sort ( n1.begin(), n1.end() );
	sort ( n2.begin(), n2.end() );

	bool f = false;
	lp ( i, 0, n ){
		if ( n1[i].id != n2[i].id ){
			f = true;
			break;
		}
	}
	
	if ( f )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
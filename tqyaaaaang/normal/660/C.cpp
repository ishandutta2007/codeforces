#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;
const int MAXN = 300005;
int a[MAXN];
int beg, en;
int n, k;

bool judge ( int test );

int main()
{
	ios::sync_with_stdio ( false );

	cin >> n >> k;
	lp ( i, 0, n ) cin >> a[i];

	int low = 0, high = n, mid;

	while ( low < high ){
		mid = ( low + high ) / 2;

		if ( judge ( mid ) )
			low = mid + 1;
		else
			high = mid - 1;
	}

	if ( !judge ( low ) ){
		low--;
		judge ( low );
	}
	cout << low << endl;
	lp ( i, 0, n ){
		if ( i == beg ){
			for ( ; i < en; i++ ){
				cout << "1" << " ";
			}
		}

		if ( i == n ) break;

		cout << a[i] << " ";
	}
	cout << endl;
}

bool judge ( int test )
{
	int num0, mini;
	num0 = mini = 0;
	lp ( i, 0, test ){
		if ( !a[i] ) num0++;
	}
	mini = num0;
	beg = 0;
	en = test;
	lp ( i, 0, (n-test) ){
		if ( !a[i] ) num0--;
		if ( !a[i+test] ) num0++;

		if ( num0 <= mini ){
			mini = num0;
			beg = i+1;
			en = i+test+1;
		}
	}

	return ( mini <= k );
}
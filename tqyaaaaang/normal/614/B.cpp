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

	int n, k = 0, zeros = 0;
	bool flag;
	string str, sp;
	int num[10];
	cin >> n;

	while ( k != n ){
		cin >> str;
		memset ( num, 0, sizeof ( num ) );
		lp ( i, 0, str.size() ){
			num[str[i]-'0']++;
		}

		flag = true;
		lp ( i, 2, 10 ){
			if ( num[i] ){
				flag = false;
				break;
			}
		}

		if ( flag && !num[1] ){
			cout << "0" << endl;
			return 0;
		}

		if ( flag && num[1] <= 1 )
			zeros += num[0];
		else
			sp = str;

		k++;
	}

	if ( sp == "" )
		sp = "1";

	cout << sp;
	lp ( i, 0, zeros ) cout << "0";
	cout << endl;
}
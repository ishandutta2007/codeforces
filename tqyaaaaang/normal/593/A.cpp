#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

bool _cmp ( int a, int b )
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio ( false );

	int n, cnt, ans, plus, m;
	string str;

	int cc[101][26];
	memset ( cc, 0, sizeof ( cc ) );

	cin >> n;
	lp ( i, 0, n ){
		cin >> str;

		cnt = 0;
		lp ( j, 0, str.size() ){
			if ( !cc[i][str[j]-'a'] ){
				cnt++;
				if ( cnt == 3 ){
					memset ( cc[i], 0, sizeof ( cc[i] ) );
					n--;i--;
					break;
				}
			}
			
			cc[i][str[j]-'a']++;
		}
	}

	m = 0;
	lp ( i, 0, 26 ){
		lp ( j, 0, 26 ){
			ans = 0;
			lp ( k, 0, n ){
				plus = 0;
				lp ( l, 0, 26 ){
					if ( cc[k][l] && ( i != l ) && ( j != l ) ){
						plus = 0;
						break;
					}

					plus += cc[k][l];
				}
				ans += plus;
			}

			m = max ( m, ans );
		}
	}

	cout << m << endl;
}
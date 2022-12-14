#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

struct inType
{
	bool operator < ( inType &a ) const
	{
		if ( w < a.w )
			return true;
		else if ( w > a.w )
			return false;
		else if ( choose && ( !a.choose ) )
			return true;
		else
			return false;
	};

	int id;
	int w;
	bool choose;
};

struct edgeType
{
	bool operator < ( edgeType &a ) const
	{
		return ( id < a.id );
	}

	void s ( int a, int b, int i )
	{
		u = a;
		v = b;
		id = i;
	};

	int u, v, id;
};

int main()
{
	ios::sync_with_stdio ( false );

	int n, m, u, v, reached;
	bool yes;

	cin >> n >> m;

	vector < inType > inputs ( m );
	lp ( i, 0, m ){
		cin >> inputs[i].w >> inputs[i].choose;

		inputs[i].id = i;
	}

	sort ( inputs.begin(), inputs.end() );

	vector < edgeType > graph ( m );
	if ( m == 1 ){
		yes = true;
		graph[0].s ( 1, 2, inputs[0].id );
	}else if ( inputs[0].choose && inputs[1].choose ){
		yes = true;
		graph[0].s ( 1, 2, inputs[0].id );
		graph[1].s ( 1, 3, inputs[1].id );
		u = 2;
		v = 3;
		reached = 4;

		lp ( i, 2, m ){
			if ( inputs[i].choose ){
				graph[i].s ( 1, reached, inputs[i].id );
				reached++;
			}else{
				if ( v == reached ){
					yes = false;
					break;
				}

				graph[i].s ( u, v, inputs[i].id );
				u++;
				if ( u == v ){
					u = 2;
					v++;
				}
			}
		}
	}else{
		yes = false;
	}

	if ( yes ){
		sort ( graph.begin(), graph.end() );

		lp ( i, 0, m ){
			cout << graph[i].u << " " << graph[i].v << endl;
		}
	}else
		cout << -1 << endl;
}
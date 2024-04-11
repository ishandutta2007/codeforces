#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

// More templates here

#define MAXX (2000004)

int N, X, Y;
int A[MAXX];

int main()
{
	cin >> N >> X >> Y;

	int g = __gcd(X, Y);
	X /= g;
	Y /= g;

	int m = 0;
	{
		A[m++] = 2;
		LL a = 1;
		LL b = 1;
		while(a < X || b < Y)
		{
			if(a*Y < b*X)
			{
				++a;
				A[m++] = 0;
			}
			else
			{
				++b;
				A[m++] = 1;
			}
		}
		A[m++] = 2;
	}

	FOR(i,0,N)
	{
		int a;
		scanf("%d", &a);
		a %= m;
		if(A[a] == 0) printf("Vanya\n");
		else if(A[a] == 1) printf("Vova\n");
		else printf("Both\n");
	}

	return 0;
}
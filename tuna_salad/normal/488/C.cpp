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

int A[4];
int B[4];
int C[4];

int main()
{
	FOR(i,0,3) cin >> A[i];
	FOR(i,0,3) cin >> B[i];
	FOR(i,0,3) cin >> C[i];

	int sol = 1e9;
	FOR(a,max(0,B[2]-A[1]+1),200)
	{
		int a1 = a + A[1] - B[2];
		int tm = (B[0] + a1-1) / a1;

		FOR(d,0,max(0,B[1]-A[2])+1)
		{
			int h = 0;
			if(B[1] > A[2]+d)
			{
				int h1 = tm * (B[1] - A[2] - d) + 1;
				h = max(0, h1-A[0]);
			}

			int res = C[0]*h + C[1]*a + C[2]*d;
			mina(sol, res);
		}
	}
	cout << sol << endl;

	return 0;
}
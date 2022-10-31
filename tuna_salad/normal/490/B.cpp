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

#define MAXA (1000005)
#define MAXN (200005)

int N;
int A[MAXA];
int B[MAXA];

int sol[MAXN];

int main()
{
	MSET(A, -1);
	MSET(B, -1);

	cin >> N;
	FOR(i,0,N)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		B[a] = b;
		A[b] = a;
	}

	if(N & 1)
	{
		int a = B[0];
		int j = 1;
		while(a != 0)
		{
			sol[j] = a;
			a = B[a];
			j += 2;
		}

		FOR(i,1,MAXA) if(A[i] == -1 && B[i] != -1)
		{
			a = i;
			break;
		}
		j = 0;
		while(a != -1)
		{
			sol[j] = a;
			a = B[a];
			j += 2;
		}
	}
	else
	{
		int a = B[0];
		int j = 1;
		while(a != -1)
		{
			sol[j] = a;
			a = B[a];
			j += 2;
		}

		a = A[0];
		j = N-2;
		while(a != -1)
		{
			sol[j] = a;
			a = A[a];
			j -= 2;
		}
	}

	FOR(i,0,N) printf("%d ", sol[i]);
	cout << endl;

	return 0;
}
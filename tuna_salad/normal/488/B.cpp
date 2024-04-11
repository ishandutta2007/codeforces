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

int N;
int A[4];
int B[4];
int C[4];

int main()
{
	cin >> N;
	FOR(i,0,N) cin >> A[i];
	sort(A, A+N);

	for(int a = 2; a <= 1000; a += 2)
	{
		B[0] = a/2;
		B[3] = B[0]*3;
		FOR(b,B[0],a+1)
		{
			B[1] = b;
			B[2] = 2*a - b;

			int i = 0;
			int j = 0;
			int k = 0;
			while(j < 4)
			{
				if(i < N)
				{
					if(A[i] < B[j]) break;
					else if(A[i] == B[j]) ++i, ++j;
					else C[k++] = B[j++];
				}
				else C[k++] = B[j++];
			}

			if(i == N)
			{
				printf("YES\n");
				FOR(i,0,k) printf("%d\n", C[i]);
				return 0;
			}
		}
	}

	printf("NO\n");

	return 0;
}
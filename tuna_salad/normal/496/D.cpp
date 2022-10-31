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

#define MAXN (100004)

int N;
int A[MAXN];
int B[MAXN][2];
int C[MAXN][2];

int main()
{
	cin >> N;
	FOR(i,1,N+2) C[i][0] = C[i][1] = N+1;
	FOR(i,1,N+1)
	{
		int a;
		scanf("%d", &a);
		--a;
		A[i] = a;
		B[i][0] = B[i-1][0] + (a==0);
		B[i][1] = B[i-1][1] + (a==1);
		if(a == 0) C[B[i][0]][0] = i;
		else       C[B[i][1]][1] = i;
	}

	set <PII> sol;
	FOR(i,1,N+1)
	{
		if(B[i][A[i]] > B[i][!A[i]])
		{
			int t = B[i][A[i]];
			int S[2] = {A[i]==0, A[i]==1};
			int j = i;
			int valid = 1;
			while(j < N)
			{
				int k = (B[j][0] + t <= N) ? C[B[j][0] + t][0] : N+1;
				int l = (B[j][1] + t <= N) ? C[B[j][1] + t][1] : N+1;
				if(min(k,l) == N+1)
				{
					valid = 0;
					break;
				}

				if(k < l)
				{
					++S[0];
					if(k == N) valid = S[0] > S[1];
					j = k;
				}
				else
				{
					++S[1];
					if(l == N) valid = S[0] < S[1];
					j = l;
				}
			}

			if(valid)
			{
				int s = max(S[0], S[1]);
				sol.insert(PII(s, t));
			}
		}
	}

	cout << sol.size() << endl;
	for(PII p: sol) printf("%d %d\n", p._1, p._2);

	return 0;
}
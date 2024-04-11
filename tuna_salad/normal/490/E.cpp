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

#define MAXN (100005)
#define MAXS (12)

int N;
char S[MAXN][MAXS];
int L[MAXN];

void start(int id)
{
	if(S[id][0] == '?') S[id][0] = '1';
	FOR(i,1,L[id]) if(S[id][i] == '?') S[id][i] = '0';
}

int check(int id)
{
	FOR(j,0,L[id])
	{
		if(S[id][j] == '?')
		{
			if(S[id-1][j] != '9') return 1;
		}
		else
		{
			if(S[id-1][j] < S[id][j]) return 1;
			else if(S[id-1][j] > S[id][j]) return 0;
		}
	}
	return 0;
}

int main()
{
	cin >> N;
	FOR(i,0,N)
	{
		scanf("%s", S[i]);
		L[i] = strlen(S[i]);
	}

	start(0);
	int valid = 1;
	FOR(i,1,N)
	{
		int n = L[i-1];
		int m = L[i];
		if(n > m)
		{
			valid = 0;
			break;
		}
		else if(n < m)
		{
			start(i);
		}
		else
		{
			if(!check(i))
			{
				valid = 0;
				break;
			}

			FOR(j,0,n)
			{
				if(S[i][j] == '?')
				{
					FOR(k,'0','9'+1)
					{
						S[i][j] = k;
						if(check(i)) break;
					}
				}
			}
		}
	}

	if(valid)
	{
		printf("YES\n");
		FOR(i,0,N) printf("%s\n", S[i]);
	}
	else printf("NO\n");

	return 0;
}
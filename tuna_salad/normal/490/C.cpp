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

#define MAXN (1000005)

char S[MAXN];
int A, B;
int N;

int X[MAXN];
int Y[MAXN];

int main()
{
	scanf("%s", S);
	if(S[0] == '0')
	{
		printf("NO\n");
		return 0;
	}

	cin >> A >> B;
	N = strlen(S);

	{
		int x = 0;
		FOR(i,0,N) X[i] = x = (x*10 + S[i]-'0') % A;
	}
	{
		int x = 1;
		int y = 0;
		ROF(i,N-1,0)
		{
			Y[i] = y = (y + x*(S[i]-'0')) % B;
			x = (x*10) % B;
		}
	}

	FOR(i,0,N-1) if(S[i+1] != '0' && X[i] == 0 && Y[i+1] == 0)
	{
		char t = S[i+1];
		S[i+1] = 0;

		printf("YES\n");
		printf("%s\n", S);
		S[i+1] = t;
		printf("%s\n", S+i+1);
		return 0;
	}
	printf("NO\n");

	return 0;
}
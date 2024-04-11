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

#define MAXS (100004)

char S[MAXS];
int P[128];

int main()
{
	scanf("%s", S);
	int N = strlen(S);
	int i = 0;
	int j = N-1;
	int valid = 1;
	for(char c: string("AHIMOTUVWXY")) P[int(c)] = 1;
	while(i <= j)
	{
		if(!P[int(S[i])] || !P[int(S[j])] || S[i] != S[j])
		{
			valid = 0;
			break;
		}
		++i;
		--j;
	}
	if(valid) printf("YES\n");
	else printf("NO\n");

	return 0;
}
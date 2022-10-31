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

#define MAXS (100005)

char S[MAXS];

int getNext(int p)
{
	++p;
	while(S[p] == '0' && S[p] != 0) ++p;
	return p;
}

int main()
{
	cin >> S;
	int i = getNext(0);
	int sol = 1;

	while(S[i])
	{
		int j = getNext(i);
		int g = 0;
		if(i*2 < j) g = 1;
		else if(i*2 == j) FOR(k,0,i)
		{
			if(S[k] < S[k+i])
			{
				g = 1;
				break;
			}
		}

		if(g) sol = 1;
		else ++sol;
		i = j;
	}
	cout << sol << endl;

	return 0;
}
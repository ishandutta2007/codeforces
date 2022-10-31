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

int N, M, X, Y, A, B;
const int inf = 1e7;

int check(int x, int y)
{
	if(x == X && y == Y) return 0;
	if(abs(x-X) % A || abs(y-Y) % B) return inf;
	if((abs(x-X) / A + abs(y-Y) / B) & 1) return inf;

	if(A >= N || B >= M) return inf;
	else return max(abs(x-X) / A, abs(y-Y) / B);
}

int main()
{
	cin >> N >> M >> X >> Y >> A >> B;

	int sol = inf;
	mina(sol, check(1, 1));
	mina(sol, check(1, M));
	mina(sol, check(N, M));
	mina(sol, check(N, 1));
	if(sol == inf) cout << "Poor Inna and pony!\n";
	else cout << sol << endl;

	return 0;
}
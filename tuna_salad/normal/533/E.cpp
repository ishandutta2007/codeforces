// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
typedef long long LL; typedef long double LD; typedef unsigned int uint;
typedef pair<int,int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXN (100005)

char S[MAXN], T[MAXN];
int N;

int main()
{
	cin >> N;
	scanf("%s%s", S, T);

	int i = 0;
	int j = N-1;
	while(S[i] == T[i]) ++i;
	while(S[j] == T[j]) --j;

//	printf("%d %d\n", i, j);
	int c1 = 0;
	int c2 = 0;
	FOR(k,i,j)
	{
		c1 += S[k] == T[k+1];
		c2 += S[k+1] == T[k];
	}
	printf("%d\n", (c1==j-i)+(c2==j-i));

	return 0;
}
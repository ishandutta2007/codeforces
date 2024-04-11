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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

#define MAXN (1004)
#define MAXT (104)

int N, T;
MAX_PQ(int) Q[MAXT];

int main()
{
	cin >> N >> T;
	FOR(i,0,N)
	{
		int t, q;
		cin >> t >> q;
		Q[t].push(q);
	}
	FOR(i,1,T)
	{
		while(!Q[i].empty())
		{
			if(Q[i].size() == 1)
			{
				Q[i+1].push(Q[i].top());
				Q[i].pop();
				break;
			}

			int a = Q[i].top(); Q[i].pop();
			a += Q[i].top(); Q[i].pop();
			Q[i+1].push(a);
		}
	}

	cout << Q[T].top() << endl;

	return 0;
}
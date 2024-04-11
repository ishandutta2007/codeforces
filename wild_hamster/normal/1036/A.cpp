#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> VI;
#define mp make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const double PI = acos(-1.0);
const long long INF = 1e9 + 7;
const long long LINF = INF * INF;
ll n,m;
int main()
{
	//freopen("In.txt","r",stdin);
	cin >> n >> m;
	cout << (m-1)/n+1 << endl;
	return 0;
}
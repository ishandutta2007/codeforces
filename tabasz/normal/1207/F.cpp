#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
Sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
Sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
Sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 5e5 + 1;
const int magic = 700;

int T[M], R[magic][magic];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	int q;
	scanf("%d", &q);
	FOR(i, 1, q)
	{
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1)
		{
			T[x] += y;
			FOR(i, 1, magic - 1)
			{
				R[i][x % i] += y;
			}
		}
		else
		{
			if (x < magic)
			{
				printf("%d\n", R[x][y]);
			}
			else
			{
				int tmp = 0;
				for (int j = y; j < M; j += x)
				{
					tmp += T[j];
				}
				printf("%d\n", tmp);
			}
		}
		
	}
	return 0;
}
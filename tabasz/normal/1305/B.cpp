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
const int M = 1024;

string s;
int n;
int A[2][M];

int32_t main()
{
	cin >> s;
	n = SIZ(s);
	int tmp = 0, mxi = 0;
	FOR(i, 0, n - 1)
	{
		if (s[i] == '(')
		{
			tmp++;
		}
		A[0][i] = tmp;
	}
	tmp = 0;
	FORD(i, n - 1, 0)
	{
		if (s[i] == ')')
		{
			tmp++;
		}
		if (i > 0)
		{
			maxi(mxi, min(A[0][i - 1], tmp));
		}
	}
	if (mxi <= 0)
	{
		printf("0\n");
		return 0;
	}
	printf("1\n%d\n", 2 * mxi);
	tmp = mxi;
	FOR(i, 0, n - 1)
	{
		if (s[i] == '(')
		{
			printf("%d ", i + 1);
			tmp--;
		}
		if (tmp == 0)
		{
			break;
		}
	}
	VI V;
	tmp = mxi;
	FORD(i, n - 1, 0)
	{
		if (s[i] == ')')
		{
			V.PB(i + 1);
			tmp--;
		}
		if (tmp == 0)
		{
			break;
		}
	}
	FORD(i, mxi - 1, 0)
	{
		printf("%d ", V[i]);
	}
	printf("\n");
}
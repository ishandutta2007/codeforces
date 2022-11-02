#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
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
const int M = 1024 * 128;

int n, m, l, res;
int T[M], A[M];

int find(int a)
{
	if (T[a] == a)
	{
		return a;
	}
	return T[a] = find(T[a]);
}

void onion(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		res--;
	}
	T[b] = a;
}

int main()
{
	scanf("%d%d%d", &n, &m, &l);
	FOR(i, 1, n)
	{
		scanf("%d", A + i);
		T[i] = i;
		if (A[i] > l)
		{
			res++;
		}
	}
	FOR(i, 2, n)
	{
		if (A[i - 1] > l && A[i] > l)
		{
			onion(i - 1, i);
		}
	}
	FOR(i, 1, m)
	{
		int t, b, a;
		scanf("%d", &t);
		if (t == 0)
		{
			printf("%d\n", res);
		}
		else
		{
			scanf("%d%d", &a, &b);
			if (A[a] > l)
			{
				continue;
			}
			A[a] += b;
			if (A[a] > l)
			{
				res++;
				if (a > 1 && A[a - 1] > l)
				{
					onion(a, a - 1);
				}
				if (a < n && A[a + 1] > l)
				{
					onion(a, a + 1);
				}
			}
		}
	}
	return 0;
}
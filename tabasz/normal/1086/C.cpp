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
const int M = 100;

int k, n;
string s, a, b, c;
int T[M], F[M];

bool isLess(string& x, string& y)
{
	FOR(i, 0, SIZ(x) - 1)
	{
		if (x[i] != y[i])
		{
			return x[i] < y[i];
		}
	}
	return true;
}

bool check(int ind)
{
	FOR(i, 0, k - 1)
	{
		T[i] = -1;
		F[i] = 1;
	}
	FOR(i, 0, ind - 1)
	{
		int let = (int)(s[i] - 'a');
		int to = (int)(a[i] - 'a');
		if ((T[let] != -1 && T[let] != to) || (T[let] == -1 && !F[to]))
		{
			return false;
		}
		T[let] = to;
		F[to] = 0;
		c[i] = a[i];
	}
	
	bool boo = true;
	FOR(i, ind, n - 1)
	{
		int let = (int)(s[i] - 'a');
		int to = (int)(a[i] - 'a');
		if (T[let] == -1)
		{
			int st = 0;
			if (boo)
			{
				st = to + 1;
			}
			FOR(j, st, k - 1)
			{
				if (F[j])
				{
					F[j] = 0;
					T[let] = j;
					break;
				}
			}
		}
		if (T[let] == -1)
		{
			FORD(j, k - 1, 0)
			{
				if (F[j])
				{
					F[j] = 0;
					T[let] = j;
					break;
				}
			}
		}
		if (boo && T[let] < to)
		{
			return false;
		}
		if (T[let] > to)
		{
			boo = false;
		}
		c[i] = (char)((int)'a' + T[let]);
	}
	return true;
}


void solve()
{
	cin >> k >> s >> a >> b;
	c = a;
	n = SIZ(s);
	int st = 0, en = n, mid = (st + en) / 2, r = -1;
	while (st <= en)
	{
		if (check(mid))
		{
			maxi(r, mid);
			st = mid + 1;
		}
		else
		{
			en = mid - 1;
		}
		mid = (st + en) / 2;
	}
	
	debug(r);
	
	if (r == -1)
	{
		cout << "NO\n";
		return;
	}
	
	check(r);
	
	debug("T	");
	FOR(i, 0, k - 1)
	{
		debug(i, T[i]);
	}
	debug("F");
	FOR(i, 0, k - 1)
	{
		debug(i, F[i]);
	}
	
	FOR(i, 0, k - 1)
	{
		if (T[i] == -1)
		{
			FORD(j, k - 1, 0)
			{
				if (F[j])
				{
					F[j] = 0;
					T[i] = j;
					break;
				}
			}
		}
	}
	
	FOR(i, 0, k - 1)
	{
		debug(i, T[i]);
	}
	
	FOR(i, 0, n - 1)
	{
		int let = (int)(s[i] - 'a');
		s[i] = (char)((int)'a' + T[let]);
	}
	debug(s);
	
	if (isLess(s, b))
	{
		cout << "YES\n";
		FOR(i, 0, k - 1)
		{
			cout << (char)((int)'a' + T[i]);
		}
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
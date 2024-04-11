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
const int M = 1024 * 1024;
const LL mod = 998244353;

string s;
LL res;
int T[2][M], X[M];
PII fi[M];
VPII V[M];

LL poww(LL x, LL e)
{
	if (e == 0)
	{
		return 1;
	}
	if (e % 2 == 0)
	{
		return poww(x * x % mod, e / 2);
	}
	return poww(x, e - 1) * x % mod;
}

PII find(int x)
{
	if (fi[x].f == x)
	{
		return fi[x];
	}
	return fi[x] = find(fi[x].f);
}

void onion(int a, int b, int v)
{
	PII aa = find(a);
	PII bb = find(b);
	fi[bb.f].f = aa.f;
	fi[aa.f].s ^= fi[bb.f].s ^ v; 
}

void solve(int a, int b)
{
	debug(a, b);
	FOR(i, 0, 1)
	{
		FOR(j, 0, a)
		{
			T[i][j] = -1;
		}
	}
	FOR(i, 0, a + b)
	{
		X[i] = -1;
		V[i].clear();
	}
	FOR(i, 0, (a + 1) / 2 - 1)
	{
		T[0][i] = i;
		T[0][a - i - 1] = i;
	}
	FOR(i, 0, (b + 1) / 2 - 1)
	{
		T[1][a - b + i] = a + i;
		T[1][a - i - 1] = a + i;
	}
	queue<PII> Q;
	FOR(i, 0, a - b - 1)
	{
		if (s[i] == '1')
		{
			Q.push(MP(T[0][i], 1));
			X[T[0][i]] = 1;
		}
		if (s[i] == '0')
		{
			Q.push(MP(T[0][i], 0));
			X[T[0][i]] = 0;
		}
	}
	FOR(i, a - b, a - 1)
	{
		if (s[i] == '1')
		{
			V[T[0][i]].PB(MP(T[1][i], 1));
			V[T[1][i]].PB(MP(T[0][i], 1));
		}
		if (s[i] == '0')
		{
			V[T[0][i]].PB(MP(T[1][i], 0));
			V[T[1][i]].PB(MP(T[0][i], 0));
		}
	}
	
	FOR(i, 0, a + b)
	{
		debug(i, V[i]);
	}
	while (!Q.empty())
	{
		PII x = Q.front();
		debug(x);
		Q.pop();
		if (x.s != X[x.f])
		{
			debug(x, X[x.f]);
			return;
		}
		for (auto v : V[x.f])
		{
			if (X[v.f] != -1 && (X[v.f] ^ x.s) != v.s)
			{
				debug(v, X[v.f], x.s);
				return;
			}
			else if (X[v.f] == -1)
			{
				X[v.f] = x.s ^ v.s;
				Q.push(MP(v.f, X[v.f]));
			}
		}
	}
	int ex = 0;
	
	VI ind;
	FOR(i, 0, (a + 1) / 2 - 1)
	{
		ind.PB(i);
	}
	FOR(i, 0, (b + 1) / 2 - 1)
	{
		ind.PB(a + i);
	}
	for (auto x : ind)
	{
		if (X[x] == -1)
		{
			ex++;
			fi[x] = MP(x, 0);
		}
	}
	debug("            ", ind);
	set<PII> done;
	for (auto x : ind)
	{
		if (X[x] == -1)
		{
			for (auto y : V[x])
			{
				if (done.count(MP(x, y.f)))
				{
					continue;
				}
				if (find(x) != find(y.f))
				{
					onion(x, y.f, y.s);
					done.insert(MP(y.f, x));
					ex--;
				}
				else if (find(x).s != y.s)
				{
					debug(x, y, find(x));
					return;
				}
			}
		}
	}
	
	res += poww(2, ex);
	debug("lololol       ", ex);
	res %= mod;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> s;
	if (s.back() == '1')
	{
		printf("0\n");
		return 0;
	}
	int l = SIZ(s);
	s.back() = '0';
	
	FOR(i, 1, l - 1)
	{
		solve(l, i);
	}
	printf("%lld\n", res);
	return 0;
}
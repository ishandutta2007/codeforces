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
const int M = 305;

int n, t;
int R[M];
int asd = 0;

int get(int l, int r)
{
	asd++;
	if (asd > 10000)
	{
		while (true);
	}
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int a;
	scanf("%d", &a);
	if (a == -1)
	{
		assert(false);
	}
	return a;
}

void result()
{
	printf("! ");
	FOR(i, 1, n)
	{
		printf("%d", R[i]);
	}
	printf("\n");
	fflush(stdout);
}

int A = 0, C = 0, B = 0, D = 0;

void sett(int i, int x)
{
	R[i] = x;
	if (x == 1)
	{
		A++;
		C--;
	}
	else
	{
		B++;
		D--;
	}
}

int go(int p, int k)
{
	int r = -1, tmp = t;
	while (r == -1 || tmp != t)
	{
		get(p, k);
		tmp = get(p, k);
		if (tmp != t)
		{
			r = tmp;
		}
	}
	return r;
}

void solve(int ind)
{
	if (n % 2 == 0)
	{
		int diff = go(ind, ind);
		
		if (diff == B + D + 1)
		{
			sett(ind, 1);
		}
		else
		{
			sett(ind, 0);
		}
		return;
	}
	
	if (ind % 2 == 1)
	{
		int diff = go(ind + 1, n);
		if (diff == B + C + 1)
		{
			sett(ind, 0);
		}
		else
		{
			sett(ind, 1);
		}
		return;
	}
	
	if (ind % 2 == 0)
	{
		int diff = go(1, ind);
		if (diff == A + D + 1)
		{
			sett(ind, 1);
		}
		else
		{
			sett(ind, 0);
		}
		return;
	}
	assert(false);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &t);
	C = t;
	D = n - t;
	
	if (n == 1)
	{
		R[1] = t;
		result();
		return 0;
	}
	
	FOR(i, 1, n - 1)
	{
		solve(i);
	}
	int zxc = 0;
	FOR(i, 1, n - 1)
	{
		zxc += R[i];
	}
	R[n] = t - zxc;
	
	
	result();
	return 0;
}
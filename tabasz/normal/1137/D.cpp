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

char C[100];

int l, c;

int scan()
{
	int x;
	scanf("%d", &x);
	FOR(i, 1, x)
	{
		scanf("%s", C);
	}
	return x;
}

int go()
{
	printf("next %d %d\n", 0, 1);
	printf("next %d\n", 0);
	fflush(stdout);
	scan();
	return scan();
}

int go2()
{
	printf("next %d\n", 0);
	fflush(stdout);
	return scan();
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	while (go() != 2)
	{
		l++;
	}
	while (go2() != 2)
	{
		c++;
	}
	
	while (l > c)
	{
		printf("next");
		FOR(j, 2, 9)
		{
			printf(" %d", j);
		}
		printf("\n");
		fflush(stdout);
		l--;
		scan();
	}
	
	while (true)
	{
		printf("next");
		FOR(j, 0, 9)
		{
			printf(" %d", j);
		}
		printf("\n");
		fflush(stdout);
		int x = scan();
		if (x == 1)
		{
			break;
		}
	}
	
	/*int t = countT();
	
	int a = l - t;
	FOR(i, 1, c - a)
	{
		printf("next %d %d\n", 0, 1);
		fflush(stdout);
	}
	FOR(i, 1, t)
	{
		
	}*/
	printf("done\n");
	return 0;
}
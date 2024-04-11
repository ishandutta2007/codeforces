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
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

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

VPII pola;
bool odw[8][8];

void print()
	{
	for(auto i : pola)
		printf("%c%c ", 'a'+i.f, '1'+i.s);
	}

void go(int i, int j, int en)
	{
	if(odw[i][j] || en < 0)return;
	odw[i][j] = 1;
	pola.PB(MP(i, j));
	
	if(en == 0 && i == 7 && j == 7)
		{
		print();
		exit(0);
		}
	
	VPII sas;
	REP(u, 8)
		{
		if(u != i)sas.PB(MP(u, j));
		if(u != j)sas.PB(MP(i, u));
		}
	sort(ALL(sas));
	
	if(sas.back() == MP(8, 8) && en == 1)
		{
		go(8, 8, 0);
		}
		
	for(auto ii : sas)
		go(ii.f, ii.s, en-1);
	
	
	
	odw[i][j] = 0;
	pola.pop_back();
	}

int main()
{
	int n;
	cin >> n;
	if(n == 2)
		{
		puts("a1 a8 h8");
		return 0;
		}
	go(0, 0, n);
}
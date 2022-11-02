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

const int MXN = 100;
char out[MXN][MXN][MXN];

int kra[MXN][MXN];
int osi[MXN][MXN];

	
int n;
int mkra[MXN][MXN];
void generate(vector<VI> typy, VPII kraw) // kraw[i].f > kraw[i].s
	{
	debug(typy, kraw);

	for(auto i : kraw)
		mkra[i.f][i.s] = 1;


	int x, y, z;
	x = y = n * 5;
	z = n * 2;
	REP(lvl, z)
		REP(i, y)
			REP(j, x)
				out[lvl][i][j] = '.';


	FOR(lvl, 0, z-1)
		{
		FOR(i, 0, y-1)
			{
			FOR(j, 0, x-1)
				{
				if(lvl % 2 == 0 && (i % 5 != 1 || j % 5 != 1))
					{
					out[lvl][i][j] = '#'; // na stae ustalone
					}
				if(lvl % 2 == 0 && i % 5 == 1 && j % 5 == 1) // zajazdy
					{
					int a = i / 5;
					int b = j / 5;
					int lid = lvl / 2;
					
					if(mkra[b][a] &&
					   a < lid && lid <= b)
						{
						/// puste
						if(lid < b)
						FOR(x, -1, 1)
							FOR(y, -1, 1)
								if(x != 0 || y != 0)
									out[lvl+1][i+x][j+y] = '#';
						}
					else
						{
						out[lvl][i][j] = '#';					
						}
					}
				
				if(lvl % 2 == 1 && (i % 5 != 1 || j % 5 != 1))
					{
					int lid = lvl/2;
					if(lid < typy.size() && typy[lid].size())
						{
						out[lvl][i][j] = typy[lid].back() + '0';
						typy[lid].pop_back();
						}
					
					}
				}
			}
		}
	
	cout << x << " " << y << " " << z << endl;
	
//	REP(lvl, z)
	FORD(lvl, z-1, 0)
		{
		REP(i, y)
			{
			REP(j, x)
				{
				printf("%c", out[lvl][i][j]);
				}
			puts("");
			}
		puts("");
		}
	
	}

int main()
{


	cin >> n;
	FOR(i, 1, n)
		FOR(j, 1, n)
			{
			cin >> kra[i][j];
//			kra[i][j] = i > j;
			}
	FOR(i, 1, n)
		{
		FOR(j, 1, n)
			osi[i][j] = kra[i][j];
		osi[i][i] = 1;
		}

	FOR(i, 1, n)
		FOR(j, 1, n)
			FOR(u, 1, n)
				osi[j][u] |= osi[j][i] & osi[i][u];

	
	map<VI, VI>  M;
	map<VI, int> ID;
	FOR(i, 1, n)
		{
		VI V;
		FOR(j, 1, n)
			V.PB(osi[i][j]);
			
		int s = 0;
		for(auto ii : V)s += ii;
		V.insert(V.begin(), s);
		
		M[V].PB(i);
		}
	
	int id = 0;
	for(auto i : M)ID[i.f] = id++;
	
	VPII kraw;
	for(auto i : M)
		{
		for(auto j : M)
			{
			if(j.f <= i.f)
				continue;
			
			if(osi[j.s[0]][i.s[0]])
				{
				kraw.PB(MP(ID[j.f], ID[i.f]));
				}
			}
		}

	vector<VI> typy;
	for(auto i : M)typy.PB(i.s);

	generate(typy, kraw);

}
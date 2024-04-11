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
const int M = 62;
const LL mod = 998244353;

int n;
LL res;
set<string> V[11];
int ile[M][M][8], ile2[M][M][M][8];

bool pal(string& s)
{
	FOR(i, 0, SIZ(s) / 2)
	{
		if (s[i] != s[SIZ(s) - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int getnum(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 26;
	}
	return c - '0' + 52;
}

void solve(int l)
{
	for (auto& s : V[l])
	{
		PII x = MP(getnum(s[0]), getnum(s.back()));
		ile[x.f][x.s][l - 3]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	//n = 1;
	
	FOR(i, 1, n)
	{
		string s;
		cin >> s;
		//s = "robot";
		V[SIZ(s)].insert(s);
		reverse(ALL(s));
		V[SIZ(s)].insert(s);
	}
	FOR(i, 3, 10)
	{
		solve(i);
	}
	
	FOR(i, 0, M - 1)
	{
		FOR(j, i, M - 1)
		{
			FOR(k, j, M - 1)
			{
				FOR(l, 0, M - 1)
				{
					FOR(z, 0, 7)
					{
						LL tmp = (LL)ile[i][l][z] * ile[j][l][z] % mod;
						ile2[i][j][k][z] = (tmp * ile[k][l][z] + ile2[i][j][k][z]) % mod;
					}
				}
			}
		}
	}
	
	FOR(i, 0, M - 1)
	{
		FOR(j, i, M - 1)
		{
			FOR(k, j, M - 1)
			{
				FOR(l, k, M - 1)
				{
					VI V{i, j, k, l};
					int tmp = 0;
					do
					{
						tmp++;
					} while (next_permutation(ALL(V)));
					FOR(z, 0, 7)
					{
						LL tmp1 = (LL)ile2[i][j][k][z] * ile2[i][j][l][z] % mod;
						LL tmp2 = (LL)ile2[i][k][l][z] * ile2[j][k][l][z] % mod;
						res = ((tmp1 * tmp2 % mod) * tmp + res) % mod;
					}
				}
			}
		}
	}
	
	cout << res << "\n";
	return 0;
}
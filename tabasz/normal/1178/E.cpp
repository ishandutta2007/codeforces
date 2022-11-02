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

string s;
vector<char> V1, V2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> s;
	int p = 0, k = SIZ(s) - 1;
	while (k - p + 1 >= 4)
	{
		if (s[p] == s[k])
		{
			V1.PB(s[p]);
			V2.PB(s[k]);
			p++;
			k--;
			continue;
		}
		if (s[p + 1] == s[k])
		{
			V1.PB(s[p + 1]);
			V2.PB(s[k]);
			p += 2;
			k--;
			continue;
		}
		int ind = p;
		if (s[p] != s[k - 1])
		{
			ind = p + 1;
		}
		V1.PB(s[ind]);
		V2.PB(s[k - 1]);
		p += 2;
		k -= 2;
	}
	if (p <= k)
	{
		V1.PB(s[p]);
	}
	for (auto x : V1)
	{
		cout << x;
	}
	reverse(ALL(V2));
	for (auto x : V2)
	{
		cout << x;
	}
	cout << "\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
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
#define ll long long
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.st << ", " << x.nd << ">";}
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


map<int, VI> M;
int main()
{
	int n;
	scanf("%d", &n);
	REP(i, n)
		{
		int a, b;
		scanf("%d%d", &a, &b);
		debug(a, b);
		M[a].PB(b);
		}
	for(auto &i : M)
		{
		sort(ALL(i.s));
		}
	
	int all = 0, jed = 0, dwa = 0, sum = 0;
	for(auto i : M[11])
		{
		all += i;
		jed++;
		sum++;
		dwa++;
		}
	debug(sum, jed, dwa, all);
	
	while(M[10].size() && M[1].size())
		{
		all += M[10].back();
		all += M[1].back();
		M[10].pop_back();
		M[1].pop_back();
		sum += 2;
		jed++;
		dwa++;
		}
	if(M[1].size() < M[10].size())swap(M[1], M[10]);
	
	debug(sum, jed, dwa, all);
	//M[1] wieksze
	while(M[1].size() || M[0].size())
		{
		if(dwa * 2 >= sum+1)
			{
			if(M[0].size() == 0 || (M[1].size() && M[1].back() > M[0].back()))
				{
				all += M[1].back();
				M[1].pop_back();
				}		
			else
				{
				all += M[0].back();
				M[0].pop_back();
				}
			jed++;
			sum++;
			}
		else
			break;
		}	
	debug(sum, jed, dwa, all);
	cout << all << endl;
}
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
const int M = 1024 * 256;

int n, k, sum;
int T[M];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", T + i);
		sum += T[i];
	}
	if (sum % k != 0)
	{
		printf("No\n");
		return 0;
	}
	
	int qwe = sum / k;
	vector<int> V;
	int tmp = 0, il = 0;
	for (int i = 0; i < n; i++)
	{
		tmp += T[i];
		il++;
		if (tmp > qwe)
		{
			printf("No\n");
			return 0;
		}
		if (tmp == qwe)
		{
			V.PB(il);
			il = 0;
			tmp = 0;
		}
	}
	if (tmp != 0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (auto x : V)
	{
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
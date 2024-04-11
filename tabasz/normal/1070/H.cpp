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

int n, q;

map<string, int> cnt;
map<string, string> any;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		
		vector<string> vec;
		
		for(int j = 0; j < s.size(); ++j)
		{
			for(int k = j; k < s.size(); ++k)
			{
				string t = s.substr(j, k-j+1);
				vec.pb(t);
			}
		}
		
		sort(ALL(vec));
		vec.erase(unique(ALL(vec)), vec.end());
		
		for(auto it:vec)
		{
			++cnt[it];
			any[it] = s;
		}
	}
	
	cin >> q;
	
	while(q--)
	{
		string s;
		cin >> s;
		
		cout << cnt[s] << " ";
		
		if(any.count(s))
			cout << any[s] << endl;
		else
			cout << "-" << endl;
	}
}
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
const int M = 1024 * 512;

string s, t;
int P[M], n, m;

void kmp()
{
	for (int i = 1; i < m; i++)
	{
		int ind = P[i - 1];
		while (ind != 0 && t[ind] != t[i])
		{
			ind = P[ind - 1];
		}
		if (t[ind] == t[i])
		{
			ind++;
		}
		P[i] = ind;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> s >> t;
	if (SIZ(s) < SIZ(t))
	{
		cout << s << "\n";
		return 0;
	}
	n = SIZ(s);
	m = SIZ(t);
	kmp();
	int pre = P[m - 1], jed = 0, zer = 0;
	debug(pre);
	for (auto& x : s)
	{
		if (x == '1')
		{
			jed++;
		}
		else
		{
			zer++;
		}
		x = '0';
	}
	debug(jed, zer);
	FOR (i, 0, pre - 1)
	{
		if (t[i] == '1')
		{
			if (jed != 0)
			{
				jed--;
				s[i] = '1';
			}
			else
			{
				zer--;
				s[i] = '0';
			}
		}
		else
		{
			if (zer != 0)
			{
				zer--;
				s[i] = '0';
			}
			else
			{
				jed--;
				s[i] = '1';
			}
		}
	}
	int ind = pre, ind2 = pre;
	debug(ind, ind2, jed, zer, s);
	while (zer != 0 && jed != 0)
	{
		if (t[ind2] == '1')
		{
			jed--;
			s[ind] = '1'; 
		}
		else
		{
			zer--;
			s[ind] = '0';
		}
		ind++;
		ind2++;
		if (ind2 == m)
		{
			ind2 = pre;
		}
	}
	debug(ind, ind2, jed, zer, s);
	while (jed != 0 || zer != 0)
	{
		if (jed != 0)
		{
			s[ind] = '1';
			jed--;
		}
		else
		{
			s[ind] = '0';
			zer--;
		}
		ind++;
	}
	cout << s << "\n";
	return 0;
}
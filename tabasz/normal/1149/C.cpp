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
const int M = 1024 * 256;
const int inf = 1e9;

struct node
{
	int s, mx, r, mi;
};

ostream & operator << (ostream &p, node x)
{
	return p << "{" << x.s << ", " << x.mx << ", " << x.mi << ", " << x.r << "}";
}

int n, q;
string s[2];
PII D[2][2 * M];
node X[2][2 * M];

void add(int ind, int v, int vp, int vk, int p, int k, int x)
{
	if (v == 1)
	{
		//debug(ind, v, vp, vp, p, k, x);
	}
	if (vp > k || vk < p)
	{
		return;
	}
	if (vp >= p && vk <= k)
	{
		D[ind][v].s += x;
		return;
	}
	int mid = (vp + vk) / 2;
	add(ind, 2 * v, vp, mid, p, k, x);
	add(ind, 2 * v + 1, mid + 1, vk, p, k, x);
	D[ind][v].f = max(D[ind][2 * v].f + D[ind][2 * v].s, D[ind][2 * v + 1].f + D[ind][2 * v + 1].s);
}

int get2(int ind, int v, int s)
{
	if (v >= M)
	{
		return v - M;
	}
	s -= D[ind][v].s;
	if (D[ind][2 * v + 1].f + D[ind][2 * v + 1].s == s)
	{
		return get2(ind, 2 * v + 1, s);
	}
	return get2(ind, 2 * v, s);
}

node join(node& a, node& b)
{
	node r;
	r.s = a.s + b.s;
	r.mx = max(a.mx, a.s + b.mx);
	r.mi = min(a.mi, a.s + b.mi);
	r.r = max(a.r, b.r - a.s);
	maxi(r.r, a.mx - 2 * (a.s + b.mi));
	return r;
}

void add2(int ind, int v, int x)
{
	v += M;
	X[ind][v].s = x;
	X[ind][v].mx = max(x, 0);
	X[ind][v].mi = min(x, 0);
	if (x == -1)
	{
		X[ind][v].r = 2;
	}
	else
	{
		X[ind][v].r = 0;
	}
	while (v > 1)
	{
		v /= 2;
		X[ind][v] = join(X[ind][2 * v], X[ind][2 * v + 1]);
		if (ind == 0 && v == 32768 * 2 + 1)
		{
			//debug("         ", ind, v, X[ind][v], X[ind][2 * v], X[ind][2* v + 1]);
		}
	}
}

node empt;

node get(int ind, int v, int vp, int vk, int p, int k)
{
	if (vp > k || vk < p)
	{
		return empt;
	}
	if (vp >= p && vk <= k)
	{
		//debug(ind, v, vp, vk, p, k, X[ind][v]);
		return X[ind][v];
	}
	int mid = (vp + vk) / 2;
	node l = get(ind, 2 * v, vp, mid, p, k);
	node r = get(ind, 2 * v + 1, mid + 1, vk, p, k);
	//debug(ind, v, vp, vk, l, r, join(l, r));
	return join(l, r);
}

int solve(int ind)
{
	int s = D[ind][1].f + D[ind][1].s;
	int x = get2(ind, 1, s);
	node r = get(ind, 1, 0, M - 1, 0, x);
	//debug(ind, s, x, r);
	return r.r + s;
}

int main()
{
	empt.s = 0;
	empt.mx = -inf;
	empt.mi = inf;
	empt.r = -inf;
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> q >> s[0];
	n = 2 * (n - 1);
	s[1] = s[0];
	reverse(ALL(s[1]));
	FOR(i, 0, n - 1)
	{
		if (s[1][i] == '(')
		{
			s[1][i] = ')';
		}
		else
		{
			s[1][i] = '(';
		}
	}
	FOR(i, 0, 1)
	{
		FOR(j, 0, n - 1)
		{
			if (s[i][j] == '(')
			{
				add(i, 1, 0, M - 1, j, n - 1, 1);
				add2(i, j, 1);
			}
			else
			{
				add(i, 1, 0, M - 1, j, n - 1, -1);
				add2(i, j, -1);
			}
		}
	}
	int res = max(solve(0), solve(1));
	cout << res << "\n";
	FOR(i, 1, q)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (s[0][a] == '(')
		{
			add(0, 1, 0, M - 1, a, n - 1, -2);
			add(0, 1, 0, M - 1, b, n - 1, 2);
			add2(0, a, -1);
			add2(0, b, 1);
		}
		else
		{
			add(0, 1, 0, M - 1, a, n - 1, 2);
			add(0, 1, 0, M - 1, b, n - 1, -2);
			add2(0, a, 1);
			add2(0, b, -1);
		}
		swap(s[0][a], s[0][b]);
		b = n - 1 - b;
		a = n - 1 - a;
		if (s[1][a] == '(')
		{
			add(1, 1, 0, M - 1, a, n - 1, -2);
			add(1, 1, 0, M - 1, b, n - 1, 2);
			add2(1, a, -1);
			add2(1, b, 1);
		}
		else
		{
			add(1, 1, 0, M - 1, a, n - 1, 2);
			add(1, 1, 0, M - 1, b, n - 1, -2);
			add2(1, a, 1);
			add2(1, b, -1);
		}
		swap(s[1][a], s[1][b]);
		res = max(solve(0), solve(1));
		cout << res << "\n";
	}
	return 0;
}
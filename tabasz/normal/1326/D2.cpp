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

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

//Wzite std http://codeforces.com/blog/entry/12143
//zapisuje w tablicy p[0] promienie parzyste a w p[1] promienie nieparzyste
//promie nieparzystego p[1][x] to liczba liter w jednej powce nie liczc rodowej,
//tj. maksymalny palindrom to s[x - p[1][x]] ... s[x + p[1][x]]
//promie parzystego p[0][x] to liczba liter w powce palindromu o rodku midzy s[x - 1] i s[x]
//tj. maksymalny palindrom to s[x - p[0][x] - 1] ... s[x + p[0][x]] UWAGA w uywaniu tego wzorku na palindrom dugoci 0
//Przetestowane na zadaniu z serocka
const int MN = 1e6 + 44;
int p[2][MN];
//dostaje stringa indexowanego od 0
void manacher(int n, char * s) {
	for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0)
		for (int i = 0; i < n; i++)
		{
			if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
			int L = i - p[z][i], R = i + p[z][i] - !z;
			while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
			if (R > r) l = L, r = R;
		}
}
//Sowo od l do r wcznie
bool is_palindrome(int l, int r) {
	return p[(l + r + 1) % 2][(l + r + 1) / 2] >= (r - l + 1) / 2;
}

char C[MN];
int n;
int res, pref, sr, mxpre;

void jebaj(int il, int ip, int p, int k)
{
	int mi = min(p, n - k - 1);
	if (mxpre < mi)
	{
		return;
	}
	int psuf = mi;
	if (psuf > il || n - psuf <= ip)
	{
		return;
	}
	int lew = il - psuf + 1, praw = n - psuf - ip;
	int r = psuf * 2;
	if (il == ip)
	{
		r += min(lew, praw) * 2 - 1;
	}
	else
	{
		r += min(lew, praw) * 2;
	}
	
	if (r <= res)
	{
		return;
	}
	res = r;
	pref = psuf;
	debug(il, ip, p, k, r, psuf);
	if (lew <= praw)
	{
		sr = -(res - psuf * 2);
	}
	else
	{
		sr = res - psuf * 2;
	}
}

void solve()
{
	scanf("%s", C);
	n = strlen(C);
	FOR(i, 0, 1)
	{
		FOR(j, 0, n)
		{
			p[i][j] = 0;
		}
	}
	debug(n, C[0]);
	manacher(n, C);
	FOR(i, 0, 1)
	{
		FOR(j, 0, n)
		{
			debug(i, j, p[i][j]);
		}
	}
	res = 0;
	pref = 0;
	sr = 0;
	mxpre = 0;
	while ((mxpre + 1) * 2 <= n && C[mxpre] == C[n - 1 - mxpre])
	{
		mxpre++;
	}
	res = mxpre * 2;
	pref = mxpre;

	FOR(i, 0, n - 1)
	{
		jebaj(i, i, i - p[1][i], i + p[1][i]);
		if (i > 0 && p[0][i] > 0)
		{
			jebaj(i - 1, i, i - p[0][i], i + p[0][i] - 1);
		}
	}
	
	debug("         ", res, pref, sr);
	debug(pref - 1);
	FOR(i, 0, pref - 1)
	{
		debug(i);
		printf("%c", C[i]);
	}
	int pocz = pref;
	if (sr > 0)
	{
		pocz = n - pref - sr;
	}
	FOR(i, 0, abs(sr) - 1)
	{
		debug(i + pocz);
		printf("%c", C[pocz + i]);
	}
	FOR(i, n - pref, n - 1)
	{
		debug(i);
		printf("%c", C[i]);
	}
	printf("\n");
}

int32_t main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}
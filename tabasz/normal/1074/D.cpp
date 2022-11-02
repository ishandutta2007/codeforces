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

int q, tmp;
map<int, int> inde;
vector<int> T, S;
vector<vector<int>> J, X;
vector<int> dep;
vector<vector<PII>> V;
vector<int> inds;

void addV(int ind)
{
	tmp++;
	inde[ind] = tmp;
	T.PB(tmp);
	S.PB(1);
	V.PB(vector<PII>());
	J.PB(VI(20, 0));
	X.PB(VI(20, 0));
	dep.PB(0);
}

int find(int a)
{
	if (T[a] == a)
	{
		return a;
	}
	return T[a] = find(T[a]);
}

void DFS(int v, int pr, int d, int e)
{
	dep[v] = d;
	inds.PB(v);
	J[v][0] = pr;
	X[v][0] = e;
	
	for (auto u : V[v])
	{
		if (u.f == pr)
		{
			continue;
		}
		DFS(u.f, v, d + 1, u.s);
	}
}

void onion(int a, int b, int x)
{
	int aa = find(a);
	int bb = find(b);
	//debug("onion", aa, bb, a, b, x);
	if (S[aa] < S[bb])
	{
		swap(a, b);
		swap(aa, bb);
	}
	S[aa] += S[bb];
	T[bb] = aa;

	inds.clear();
	DFS(b, a, dep[a] + 1, x);
	
	FOR(i, 1, 19)
	{
		for (auto v : inds)
		{
			J[v][i] = J[J[v][i - 1]][i - 1];
			X[v][i] = X[v][i - 1] ^ X[J[v][i - 1]][i - 1];
		}
	}
	V[b].PB(MP(a, x));
	V[a].PB(MP(b, x));
}

int dist(int a, int b)
{
	int r = 0;
	int i = 19;
	if (dep[a] < dep[b])
	{
		swap(a, b);
	}
	int diff = dep[a] - dep[b];
	while (diff > 0)
	{
		if ((1<<i) <= diff)
		{
			diff -= (1<<i);
			r ^= X[a][i];
			a = J[a][i];
		}
		i--;
	}
	i = 19;
	while (i >= 0)
	{
		if (J[a][i] != J[b][i])
		{
			r ^= X[a][i];
			r ^= X[b][i];
			a = J[a][i];
			b = J[b][i];
		}
		i--;
	}
	if (a != b)
	{
		r ^= X[a][0];
		r ^= X[b][0];
	}
	return r;
}

int main() 
{
	T.PB(0);
	S.PB(0);
	V.PB(vector<PII>());
	J.PB(VI(20, 0));
	X.PB(VI(20, 0));
	dep.PB(0);
	scanf("%d", &q);
	int last = 0;
	FOR(i, 1, q)
	{
		int t, l, r, x;
		scanf("%d%d%d", &t, &l, &r);
		l ^= last;
		r ^= last;
		if (l > r)
		{
			swap(l, r);
		}
		if (inde.count(l) == 0)
		{
			addV(l);
		}
		if (inde.count(r + 1) == 0)
		{
			addV(r + 1);
		}
		//debug("aaaaaaaaaa", l, r);
		l = inde[l];
		r = inde[r + 1];
		if (t == 1)
		{
			scanf("%d", &x);
			x ^= last;
			//debug("oo", l, r, x);
			if (find(l) == find(r)) 
			{
				continue;
			}
			onion(l, r, x);
		}
		if (t == 2)
		{
			//debug("q", l, r);
			if (find(l) != find(r))
			{
				printf("-1\n");
				last = 1;
			}
			else
			{
				last = dist(l, r);
				printf("%d\n", last);
			}
		}
	}
	return 0;
}
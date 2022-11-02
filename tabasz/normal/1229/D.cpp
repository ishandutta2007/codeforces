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

LL res;
int n, k, sil = 1;
int T[M];
VI secik;
set<int> inds;
int mapa[M];
bool mam[M], isall;

int A[1000][1000];
map<VI, int> nums;
VI perms[M];

const int M2 = 1000;
VI jeden[M], dwa[M2][M2];
/*int fu[M];
VI cojest[M];*/

VI zloz(VI a, VI b)
{
	//debug(a, b);
	VI r;
	FOR(i, 0, SIZ(b) - 1)
	{
		r.PB(a[b[i] - 1]);
	}
	return r;
}

void add(int per)
{
	if (mam[per])
	{
		return;
	}
	VI neww;
	neww.PB(per);
	secik.PB(per);
	mam[per] = 1;
	int tmp = A[per][per];
	while (!mam[tmp])
	{
		secik.PB(tmp);
		neww.PB(tmp);
		mam[tmp] = 1;
		tmp = A[tmp][per];
	}
	bool boo = 1;
	while (boo)
	{
		boo = 0;
		VI todo;
		for (auto x : neww)
		{
			for (auto y : secik)
			{
				if (!mam[A[x][y]])
				{
					todo.PB(A[x][y]);
					mam[A[x][y]] = 1;
					boo = 1;
				}
				if (!mam[A[y][x]])
				{
					todo.PB(A[y][x]);
					mam[A[y][x]] = 1;
					boo = 1;
				}
			}
		}
		neww.clear();
		for (auto x : todo)
		{
			mam[x] = 1;
			secik.PB(x);
			neww.PB(x);
		}
		if (SIZ(secik) * 2 > sil)
		{
			isall = true;
			return;
		}
	}
}

void solve(int pos)
{
	isall = false;
	secik.clear();
	secik.PB(0);//ident
	FOR(i, 0, sil - 1)
	{
		mam[i] = 0;
	}
	mam[0] = 1;
	
	for (auto x : inds)
	{
		int xx = -x;
		debug(pos, xx, secik);
		res += (LL)SIZ(secik) * (pos - xx);
		add(T[xx]);
		pos = xx;
		if (SIZ(secik) == sil || isall)
		{
			break;
		}
	}
	debug("   ", pos, SIZ(secik), secik);
	if (!isall)
	{
		res += (LL)SIZ(secik) * pos;
	}
	else
	{
		res += (LL)sil * pos;
	}
	debug(res);
}

/*int find(int a)
{
	if (fu[a] == a)
	{
		return a;
	}
	return fu[a] = find(fu[a]);
}

void onion(int a, int b)
{
	fu[find(b)] = find(a);
}*/

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &k);
	FOR(i, 1, k)
	{
		sil *= i;
	}
	VI X;
	FOR(i, 1, k)
	{
		X.PB(i);
	}
	int tmp = 0;
	do
	{
		nums[X] = tmp;
		perms[tmp] = X;
		tmp++;
	} while (next_permutation(ALL(X)));
	
	FOR(i, 0, sil - 1)
	{
		//fu[i] = i;
		FOR(j, 0, sil - 1)
		{
			A[i][j] = nums[zloz(perms[i], perms[j])];
		}
	}
	/*int ile = sil;
	FOR(i, 0, sil - 1)
	{
		if (find(i) != find(A[i][i]))
		{
			onion(i, A[i][i]);
			ile--;
		}
	}
	debug(ile);
	FOR(i, 0, sil - 1)
	{
		debug(i, find(i));
		cojest[find(i)].PB(i);
	}*/
	
	
	FOR(i, 1, n)
	{
		VI lol;
		FOR(j, 1, k)
		{
			int a;
			scanf("%d", &a);
			lol.PB(a);
		}
		T[i] = nums[lol];
	}
	
	
	FOR(i, 1, n)
	{
		if (mapa[T[i]] != 0)
		{
			inds.erase(mapa[T[i]]);
		}
		mapa[T[i]] = -i;
		inds.insert(-i);
		
		solve(i);
	}
	
	printf("%lld\n", res);
	return 0;
}
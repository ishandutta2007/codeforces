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
const int M = 1024 * 128;

struct el
{
	int x, ind, z;
};

ostream & operator << (ostream &p, el x)
{
	return p << "{" << x.x << ", " << x.ind << ", " << x.z << "}";
}

int n, q;
vector<el> V;
int R[M], T[M];
char C[M], C2[100];

bool cmp1(el a, el b)
{
	if (a.x == b.x)
	{
		return a.ind < b.ind;
	}
	return a.x < b.x;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d", &n, &q);
	FOR(i, 1, n)
	{
		int a;
		scanf("%d", &a);
		el x;
		x.x = abs(a);
		x.ind = i;
		x.z = 0;
		if (a < 0)
		{
			//debug(i, a);
			x.z = 1;
		}
		V.PB(x);
	}
	sort(ALL(V), cmp1);
	//debug(V);
	FOR(i, 1, q)
	{
		scanf("%s%d", C2, T + i);
		C[i] = C2[0];
	}
	int flips = 0;
	FORD(i, q, 1)
	{
		//debug(i, flips, SIZ(V), V);
		if (C[i] == '<')
		{
			while (!V.empty() && ((T[i] >= 0 && V.back().x >= abs(T[i])) || (T[i] < 0 && V.back().x > abs(T[i]))))
			{
				R[V.back().ind] = abs(V.back().x);
				if (flips % 2)
				{
					R[V.back().ind] *= -1;
				}
				V.pb();
			}
			if (T[i] > 0)
			{
				flips++;
			}
		}
		else
		{
			while (!V.empty() && ((T[i] >= 0 && V.back().x > abs(T[i])) || (T[i] < 0 && V.back().x >= abs(T[i]))))
			{
				R[V.back().ind] = -abs(V.back().x);
				if (flips % 2)
				{
					R[V.back().ind] *= -1;
				}
				V.pb();
			}
			if (T[i] < 0)
			{
				flips++;
			}
		}	
	}
	//debug(SIZ(V), V, flips);
	while (!V.empty())
	{
		if ((V.back().z + flips) % 2 == 0)
		{
			R[V.back().ind] = V.back().x;
		}
		else
		{
			R[V.back().ind] = -V.back().x;
		}
		V.pb();
	}
	FOR(i, 1, n)
	{
		printf("%d ", R[i]);
	}
	printf("\n");
	return 0;
}
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


void pmask(pair<LL, int> i)
	{
//	printf("%lld.%lld.%lld.%lld/%d\n", i.f>>24, (i.f>>16)&255, (i.f>>8)&255, i.f&255, i.s);
	}
	
struct trie
	{
	trie *t[2];
	int plusy;
	int minusy;
	int sump, summ;
	trie()
		{
		t[0] = t[1] = NULL;
		plusy = minusy = 0;
		sump = summ = 0;
		}
	};
trie *root = new trie();
	
void add(trie *root, int i, LL mask, int pod, bool plus)
	{
//	debug(i, mask, pod);
	
	if(pod == 0)
		{
//		debug(i, mask, pod, plus);
//		pmask({mask, 0});
		root->plusy += plus;
		root->minusy += 1-plus;
		return;
		}
	bool k = ((1LL<<i) & mask) > 0;
	if(root->t[k] == NULL)
		{
		root->t[k] = new trie();
		}
	add(root->t[k], i-1, mask, pod-1, plus);
	}

void dfs(trie *root, LL mask, int lvl)
	{
	if(root == NULL)return;
	
	REP(i, 2)
		{
		if(lvl!=32)dfs(root->t[i], mask + (1LL<<(31-lvl)) * i, lvl+1);
		if(root->t[i])
			{
			root->sump += root->t[i]->sump;
			root->summ += root->t[i]->summ; 
			}
		root->sump += root->plusy;
		root->summ += root->minusy; 
		}
	}


vector<pair<LL, int>> ans;

void dfs2(trie *root, LL mask, int lvl)
	{
	if(root == NULL)return;

//	debug(root->summ, root->sump, root->plusy, root->minusy, mask, lvl);
//	pmask({mask, lvl});

	if(root->sump == 0 && root->summ == 0)return;
	if(root->sump != 0 && root->summ == 0)return;
	if(root->sump == 0 && root->summ != 0)
		{
		ans.PB({mask, lvl});
		return;
		}
	assert(root->sump != 0 && root->summ != 0);

	if(root->minusy != 0 || root->plusy != 0)
		{
		puts("-1");
		exit(0);
		}
	
	REP(i, 2)
		{
		dfs2(root->t[i], mask + (1LL<<(31-lvl)) * i, lvl+1);
		}
	}
int main()
	{
	int n;
	scanf("%d", &n);
	REP(i, n)
		{
		char plus;
		int a, b, c, d;
		scanf(" %c%d.%d.%d.%d", &plus, &a, &b, &c, &d);
		char ch = getchar();
		int x = 32;
		if(ch == '/')
			{
			scanf("%d", &x);
			}
//		debug(plus, a, b, c, d, x);
		
		unsigned int mask = (((LL)a) << 24) + (b << 16) + (c << 8) + d;
		add(root, 31, mask, x, plus == '+');
		}
	dfs(root, 0, 0);
	dfs2(root, 0, 0);
	
	printf("%d\n", (int)ans.size());
	for(auto i: ans)
		{
		printf("%lld.%lld.%lld.%lld/%d\n", i.f>>24, (i.f>>16)&255, (i.f>>8)&255, i.f&255, i.s);
		}
	
	}
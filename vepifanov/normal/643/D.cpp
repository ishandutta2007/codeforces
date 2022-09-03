#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int maxn = 100005;

ll t[maxn], others[maxn], me[maxn];
int f[maxn];
vector<int> from[maxn];
int kv[maxn];
ll ans[maxn];
int n, m;
multiset<ll> global;
multiset<ll> cur[maxn];
bool in[maxn], in2[maxn];

void pop(int x)
{
	if (!in[x]) return;
	in[x] = false;
	if (cur[x].size() > 0)
	{
		global.erase(global.find(others[x] + *cur[x].begin()));
		global.erase(global.find(others[x] + *cur[x].rbegin()));
	}
}

void push(int x)
{
	if (in[x]) return;
	in[x] = true;
	if (cur[x].size() > 0)
	{
		global.insert(others[x] + *cur[x].begin());
		global.insert(others[x] + *cur[x].rbegin());
	}
}

void delfrom(int a, int b)
{
	if (!in2[a]) return;
	in2[a] = false;
	cur[b].erase(cur[b].find(ans[a]));
}

void addto(int a, int b)
{
	if (in2[a]) return;
	in2[a] = true;
	cur[b].insert(ans[a]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &t[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &f[i]);
		f[i]--;
		kv[i]++;
		kv[f[i]]++;
		from[f[i]].pb(i);
	}
	for (int i = 0; i < n; i++)
	{
		others[i] = t[i] / (kv[i] + 1);
		me[i] = t[i] - (kv[i] * others[i]);
	}
	for (int i = 0; i < n; i++)
	{
		ans[i] = me[i];
		for (auto z : from[i]) ans[i] += others[z];
	}
	for (int i = 0; i < n; i++)
	{
		for (auto z : from[i])
		{
			cur[i].insert(ans[z]);
		}
		if (cur[i].size() > 0)
		{
			global.insert(others[i] + *cur[i].begin());
			global.insert(others[i] + *cur[i].rbegin());
		}
		in[i] = true;
		in2[i] = true;
	}
// 	for (int j = 0; j < n; j++) printf("%lld ", ans[j]);
// 	printf("\n");
// 	for (int j = 0; j < n; j++)
// 	{
// 		printf("cur %d contents:\n", j);
// 		for (auto it : cur[j]) printf("%lld ", it);
// 		printf("\n");
// 	}
// 	printf("global contents:\n");
// 	for (auto it : global) printf("%lld ", it);
// 	printf("\n");
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			int was = f[a];
			pop(a);
			pop(was);
			pop(f[was]);
			pop(f[f[was]]);
			pop(b);
			pop(f[b]);
			pop(f[f[b]]);
			delfrom(a, was);
			delfrom(was, f[was]);
			delfrom(f[was], f[f[was]]);
			delfrom(b, f[b]);
			delfrom(f[b], f[f[b]]);
			
			ans[was] -= others[a];
			ans[f[was]] -= others[was];
			kv[was]--;
			others[was] = ::t[was] / (kv[was] + 1);
			ans[was] -= me[was];
			me[was] = ::t[was] - (kv[was] * others[was]);
			ans[was] += me[was];
			ans[f[was]] += others[was];
			
			f[a] = b;
			ans[b] += others[a];
			ans[f[b]] -= others[b];
			kv[b]++;
			others[b] = ::t[b] / (kv[b] + 1);
			ans[b] -= me[b];
			me[b] = ::t[b] - (kv[b] * others[b]);
			ans[b] += me[b];
			ans[f[b]] += others[b];

			addto(a, b);
			addto(was, f[was]);
			addto(f[was], f[f[was]]);
			addto(b, f[b]);
			addto(f[b], f[f[b]]);
			push(a);
			push(was);
			push(f[was]);
			push(f[f[was]]);
			push(b);
			push(f[b]);
			push(f[f[b]]);
			
// 			for (int j = 0; j < n; j++) printf("%lld ", ans[j]);
// 			printf("\n");
// 			for (int j = 0; j < n; j++)
// 			{
// 				printf("cur %d contents:\n", j);
// 				for (auto it : cur[j]) printf("%lld ", it);
// 				printf("\n");
// 			}
// 			printf("global contents:\n");
// 			for (auto it : global) printf("%lld ", it);
// 			printf("\n");
		} else if (t == 2)
		{
			int x;
			scanf("%d", &x);
			x--;
			printf("%lld\n", ans[x] + others[f[x]]);
		} else
		{
			printf("%lld %lld\n", *global.begin(), *global.rbegin());
		}
	}
    return 0;
}
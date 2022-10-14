#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 203;

char s[N];
set<int> adj[26];
int vis[N];
int pos[26];

void addEdge(char x, char y) {
	int u = x - 'a', v = y - 'a';
	adj[u].insert(v);
	adj[v].insert(u);
}

vector<int> ans;

void dfs(int u) {
	ans.pb(u);
	vis[u] = 1;
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < 26; i++)
			adj[i].clear(), vis[i] = 0;
		for (int i = 0; i < n; i++) {
			if (i - 1 > 0) addEdge(s[i], s[i - 1]);
			if (i + 1 < n) addEdge(s[i], s[i + 1]);
		}
		ans.clear();
		bool ok = true;
		for (int i = 0; i < 26; i++)
			if (adj[i].size() > 2)
				ok = false;
		for (int i = 0; i < 26; i++) 
			if (!vis[i] && adj[i].size() <= 1)
				dfs(i);
		for (int i = 0; i < 26; i++)
			pos[ans[i]] = i;
		for (int i = 1; i < n; i++)
			if (abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']) > 1) 
				ok = false;
		if (!ok) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i = 0; i < 26; i++)
			printf("%c", ans[i] + 'a');
		printf("\n");
	}
}
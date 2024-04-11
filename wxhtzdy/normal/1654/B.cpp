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

const int N = 200050;
char s[N];
set<int> pos[26];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < 26; i++)
		pos[i].clear();
	for(int i = 0; i < n; i++)
		pos[s[i] - 'a'].insert(i);
	for(int i = 0; i < n; i++) {
		int cs = s[i] - 'a';
		if(pos[cs].find(i) != pos[cs].end()) {
			if(pos[cs].size() == 1) 
				break;
			pos[cs].erase(pos[cs].begin());
		}
	}
	vector<pii> state;
	for(int i = 0; i < 26; i++)
		for(int id : pos[i])
			state.push_back(mp(id, i));
	sort(state.begin(), state.end());
	for(int i = 0; i < state.size(); i++)
		printf("%c", (char)(state[i].second + 'a'));
	puts("");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0; 
}
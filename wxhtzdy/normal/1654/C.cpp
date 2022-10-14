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
int n;
int a[N];
multiset<ll> setik;

void solve() {
	scanf("%d", &n);
	setik.clear();
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]), setik.insert(a[i]);
	ll sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i];
	deque<ll> que;
	que.push_back(sum);
	while(!que.empty() && que.size() <= n) {
		ll x = que[0];
		if(setik.find(x) != setik.end()) {
			setik.erase(setik.find(x));
		} else {
			ll sX = x / 2;
			ll sY = (x + 1) / 2;
			que.push_back(sX);
			que.push_back(sY);
		}
		que.pop_front();
	}
	puts(setik.empty() ? "YES" : "NO");
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
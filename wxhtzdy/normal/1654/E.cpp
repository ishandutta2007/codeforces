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

const int N = 100050;
const int S = 400;
int n;
int a[N];

int solve() {
	int ans = 1;
	for(int j = 0; j < S; j++) {
		vector<int> vec;
		for(int i = 0; i < n; i++) {
			vec.push_back(a[i] - i * j);
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < vec.size(); i++) {
			int ptr = i;
			while (ptr + 1 < vec.size() && vec[ptr + 1] == vec[ptr])
				ptr++;
			ans = max(ans, ptr - i + 1);
			i = ptr;
		}
 	}
	for (int i = 0; i < n; i++) {
 		vector<int> vec;
 		for (int j = 1; j < N / S + 5; j++) {
 			int L = i - j;
 			int R = i + j;
 			if(L >= 0) {
 				int d = a[i] - a[L];
 				if(abs(d) % (i - L) == 0) {
 					int coeff = d / (i - L);
 					vec.push_back(coeff);
 				}
 			}
 			if(R < n) {
 				int d = a[R] - a[i];
 				if(abs(d) % (R - i) == 0) {
 					int coeff = d / (R - i);
 					vec.push_back(coeff);
 				}
 			}
 			if(L < 0 && R >= n) 
 				break;
 		}
 		sort(vec.begin(), vec.end());
 		for(int j = 0; j < vec.size(); j++) {
 			int ptr = j;
 			while(ptr + 1 < vec.size() && vec[ptr + 1] == vec[ptr])
 				ptr++;
 			ans = max(ans, ptr - j + 2);
 			j = ptr;
 		}
 	}
 	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = solve();
	for(int i = 0; i < n; i++)
		a[i] = -a[i];
	ans = max(ans, solve());
	printf("%d", n - ans);

	return 0; 
}
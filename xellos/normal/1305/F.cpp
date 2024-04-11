// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
#include <random>
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) {
		// A[i] = 0;
		// for(int j = 0; j < 39; j++) A[i] = rand()%2+A[i]*2;
		cin >> A[i];
	}
	cat ans = N;
	for(int p = 2; p <= 30; p++) {
		cat cur = 0;
		for(int i = 0; i < N; i++) {
			cat d = A[i]%p;
			if(p-d <= d || A[i] < p) d = p-d;
			cur += d;
		}
		ans = min(ans, cur);
	}
	srand(1);
    mt19937 rng(N+A[rand()%N]);
    for(int rep = 0; rep < 80; rep++) {
		int id = rng()%N;
		for(int k = -1; k <= 1; k++) if(A[id]+k > 0) {
			cat a = A[id]+k;
			static vector<cat> pd;
			pd.clear();
			for(cat i = 2; i*i <= a; i++) if(a%i == 0) {
				pd.push_back(i);
				while(a%i == 0) a /= i;
			}
			if(a > 1) pd.push_back(a);
			for(cat p : pd) if(p > 30) {
				cat cur = 0;
				for(int i = 0; i < N; i++) {
					cat d = A[i]%p;
					if(p-d <= d || A[i] < p) d = p-d;
					cur += d;
					if(cur > ans) break;
				}
				ans = min(ans, cur);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
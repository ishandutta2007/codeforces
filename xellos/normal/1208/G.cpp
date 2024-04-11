#include <bits/stdc++.h>
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
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
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
	int N, K;
	cin >> N >> K;
	if(K == 1) {
		cout << "3\n";
		return 0;
	}
	K += 2;
	vector< pair<int, int> > phi(N);
	for(int i = 0; i < N; i++) phi[i] = {i+1, i+1};
	vector<char> is_prime(N+1, 1);
	for(int i = 2; i <= N; i++) if(is_prime[i]) {
		for(int j = i; j <= N; j += i) {
			phi[j-1].ff = phi[j-1].ff/i*(i-1);
			is_prime[j] = false;
		}
	}
	sort(begin(phi), end(phi));
	cat ans = 0;
	for(int i = 0; i < K; i++) ans += phi[i].ff;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
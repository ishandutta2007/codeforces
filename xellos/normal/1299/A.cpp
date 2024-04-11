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
	int N;
	cin >> N;
	vector<int> A(N), cnt(40, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		int a = A[i];
		for(int j = 0; j < 40; j++) {
			if(a&1) cnt[j]++;
			a /= 2;
		}
	}
	int mask = 0;
	for(int i = 0; i < 40; i++) if(cnt[i] == 1) mask |= 1<<i;
	int ans = 0;
	for(int i = 0; i < N; i++) ans = max(ans, A[i]&mask);
	for(int i = 0; i < N; i++) if(ans == (A[i]&mask)) {
		cout << A[i];
		for(int j = 0; j < N; j++) if(i != j)
			cout << " " << A[j];
		cout << "\n";
		return 0;
	}
	return 0;
}

// look at my code
// my code is amazing
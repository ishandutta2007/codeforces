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

struct fin {
	vector<int> T;
	fin(int N) : T(N+1, 0) {}

	int lastone(int x) { return x & (x ^ (x-1)); }

	int get(int pos) {
		if(pos < 0) return 0;
		pos = min(pos, (int)T.size()-2);
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int ans = 0;
	fin F(10000010);
	for(int k = 0; k <= 24; k++) {
		for(int i = 0; i < N; i++) F.put(A[i] & ((2<<k)-1), 1);
		cat cnt = 0;
		for(int i = 0; i < N; i++) {
			int a = A[i] & ((2<<k)-1);
			cnt += F.get((1<<(k+1))-1-a) - F.get((1<<k)-1-a);
			cnt += F.get((1<<(k+2))-1-a) - F.get((1<<(k+1))+(1<<k)-1-a);
			if(((2*a)>>k)&1) cnt--;
		}
		cnt /= 2;
		if(cnt&1) ans ^= 1<<k;
		for(int i = 0; i < N; i++) F.put(A[i] & ((2<<k)-1), -1);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
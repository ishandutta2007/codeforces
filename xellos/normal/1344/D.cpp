// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat K;
	cin >> N >> K;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<cat> B(N);
	cat min_d = -(1LL<<62), max_d = 1LL<<40;
	while(max_d-min_d > 1) {
		cat d = min_d+(max_d-min_d)/2;
		cat cnt = 0;
		static vector<cat> B_cur(N);
		for(int i = 0; i < N; i++) {
			if(d > A[i]) {
				B_cur[i] = 0;
				continue;
			}
			// max x: A[i]-3x^2-3x >= d
			cat x = sqrt((A[i]-d)/3.+1/4.)-1/2.;
			x = min(x, A[i]-1);
			while(x+1 < A[i] && A[i]-3*(x+1)*(x+2) >= d) x++;
			while(A[i]-3*x*(x+1) < d) x--;
			cnt += x+1;
			B_cur[i] = x+1;
			if(cnt > K) break;
		}
		if(cnt <= K) {
			max_d = d;
			B = B_cur;
		}
		else min_d = d;
	}
	priority_queue< pair<cat, int> > D;
	for(int i = 0; i < N; i++) {
		if(B[i] != A[i]) D.push({A[i]-3*B[i]*(B[i]+1), i});
		K -= B[i];
	}
	while(K) {
		auto [a, b] = D.top();
		D.pop();
		B[b]++;
		K--;
		if(B[b] != A[b]) D.push({A[b]-3*B[b]*(B[b]+1), b});
	}
	for(int i = 0; i < N; i++) cout << B[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
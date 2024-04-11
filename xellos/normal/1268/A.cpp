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
	string S;
	cin >> N >> K >> S;
	string X = S;
	for(int i = K; i < N; i++) X[i] = X[i-K];
	if(X >= S) {
		cout << N << "\n" << X << "\n";
		return 0;
	}
	int cur = K-1;
	while(cur >= 0 && S[cur] == '9') cur--;
	if(cur == -1) {
		cout << N+1 << "\n";
		string ans = "1";
		for(int i = 0; i < K; i++) ans += '0';
		for(int i = 0; i < N-K; i++) ans += (i%K == 0) ? '1' : '0';
		cout << ans << "\n";
		return 0;
	}
	S[cur]++;
	for(int i = cur+1; i < K; i++) S[i] = '0';
	for(int i = K; i < N; i++) S[i] = S[i-K];
	cout << N << "\n" << S << "\n";
	return 0;
}

// look at my code
// my code is amazing
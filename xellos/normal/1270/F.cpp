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
	string S;
	cin >> S;
	int N = S.length();
	vector<int> ids;
	for(int i = 0; i < N; i++) if(S[i] == '1') ids.push_back(i);
	int K = ids.size(), B = 450;
	// n0 == r * n1
	cat ans = 0;
	// n1 <= B, r >= B
	for(int i = 0; i < K; i++) for(int j = i; j < min(K, i+B); j++) {
		int n1 = j-i+1;
		int L = (i == 0) ? ids[0] : (ids[i]-ids[i-1]-1);
		int R = (j == K-1) ? N-ids[j]-1 : (ids[j+1]-ids[j]-1);
		for(int x = 0; x <= L; x++) {
			int y = (ids[i]-1-x-ids[j])%n1;
			if(y < 0) y += n1;
			if(y > R) continue;
			int m = max(0, B+1-(ids[j]-ids[i]+1+x+y)/n1);
			ans += max(0, (R-y)/n1+1-m);
		}
	}
	// r < B
	for(int r = 0; r < B; r++) {
		static vector<int> val_groups[10010];
		if(r == 0)
			for(int i = 0; i <= 10000; i++) val_groups[i].dibs(1000);
		val_groups[N/10000].push_back(N%10000);
		for(int i = 0, v = N; i < N; i++) {
			v += (S[i] == '1' ? r : -1);
			val_groups[v/10000].push_back(v%10000);
		}
		for(int k = 0; k <= 10000; k++) {
			static int val_cnt[10000];
			for(auto v : val_groups[k]) ans += val_cnt[v]++;
			for(auto v : val_groups[k]) val_cnt[v] = 0;
			val_groups[k].clear();
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
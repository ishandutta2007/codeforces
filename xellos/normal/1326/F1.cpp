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
	char G[14][14];
	for(int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for(int j = 0; j < N; j++) G[i][j] = S[j]-'0';
	}
	vector<cat> cnt[1<<14][14];
	for(int i = 0; i < (1<<N); i++) if(__builtin_popcount(i) <= N-N/2)
		for(int j = 0; j < N; j++) if((i>>j)&1) cnt[i][j].resize(1<<6, 0);
	for(int i = 0; i < N; i++) cnt[1<<i][i][0] = 1;
	for(int i = 1; i < (1<<N); i++) if(__builtin_popcount(i) < N-N/2)
		for(int j = 0; j < N; j++) if((i>>j)&1)
			for(int k = 0; k < N; k++) if(!((i>>k)&1))
				for(int s = 0; s < (1<<5); s++)
					cnt[i|(1<<k)][k][2*s+G[j][k]] += cnt[i][j][s];
	vector<int> rev(1<<N, 0);
	for(int i = 0; i < (1<<(N-N/2-1)); i++)
		for(int k = 0; k < N-N/2-1; k++) rev[i] = 2*rev[i] + ((i>>k)&1);
	vector<cat> ans(1<<(N-1), 0);
	for(int i = 1; i < (1<<N); i++) if(__builtin_popcount(i) == N/2)
		for(int j = 0; j < N; j++) if((i>>j)&1)
			for(int k = 0; k < N; k++) if(!((i>>k)&1)) {
				auto cnt_l = cnt[i][j].data();
				auto cnt_r = cnt[(1<<N)-1-i][k].data();
				for(int s1 = 0; s1 < (1<<(N/2-1)); s1++) if(cnt_l[s1]) {
					int s_start = (2*s1+G[j][k]) << (N-N/2-1);
					for(int s2 = 0; s2 < (1<<(N-N/2-1)); s2++)
						ans[s_start+rev[s2]] += cnt_l[s1] * cnt_r[s2];
				}
			}
	for(int i = 0; i < (1<<(N-1)); i++) {
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing
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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<cat> C(N);
		for(int i = 0; i < N; i++) cin >> C[i];
		vector< vector<int> > G;
		G.resize(N);
		for(int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			G[b].push_back(a);
		}
		cat ans = 0;
		for(int i = 0; i < N; i++) if(!G[i].empty()) ans += C[i];
		vector<cat> H(N, 0);
		cat mod[2] = {1000000007, 1000000009};
		cat p = 999983;
		vector< vector<int> > by_sz(N+1);
		for(int i = 0; i < N; i++) {
			sort(begin(G[i]), end(G[i]));
			by_sz[G[i].size()].push_back(i);
			cat h[2] = {0, 0};
			for(int j = 0; j < (int)G[i].size(); j++)
				for(int k = 0; k < 2; k++)
					h[k] = (h[k] * p + G[i][j]+1) % mod[k];
			H[i] = h[0] * mod[1] + h[1];
		}
		for(int i = 1; i <= N; i++) {
			static vector< pair<cat, int> > Hs;
			Hs.resize(by_sz[i].size());
			for(int j = 0; j < (int)by_sz[i].size(); j++)
				Hs[j] = {H[by_sz[i][j]], by_sz[i][j]};
			sort(begin(Hs), end(Hs));
			for(int j = 0; j < (int)by_sz[i].size(); j++) if(!j || Hs[j].ff != Hs[j-1].ff) {
				cat sum = 0;
				for(int k = j; k < (int)Hs.size(); k++) {
					if(Hs[k].ff != Hs[j].ff) break;
					sum += C[Hs[k].ss];
				}
				ans = gcd(ans, sum);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
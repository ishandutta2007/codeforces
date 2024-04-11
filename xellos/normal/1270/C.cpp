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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> cnt(60, 0);
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			for(int e = 0; a; a /= 2, e++) if(a&1) cnt[e]++;
		}
		cat a[3] = {0, 0, 0};
		for(int i = 0; i <= 56; i++) {
			while(cnt[i] >= 4) {
				cnt[i+1] += 2;
				cnt[i] -= 4;
			}
			if(cnt[i] == 0) continue;
			if(cnt[i] == 3) {
				a[0] |= 1LL<<i;
				cnt[i+1] += 2;
				continue;
			}
			if(cnt[i] == 1) {
				a[0] |= 1LL<<i;
				cnt[i]++;
			}
			if(cnt[i] == 2 && i < 56) {
				a[1] |= 1LL<<i;
				a[2] |= 1LL<<i;
				cnt[i+1] += 2;
				continue;
			}
			if(cnt[i] == 2 && i == 56) {
				a[2] |= 1LL<<(i+1);
				break;
			}
		}
		cout << "3\n" << a[0] << " " << a[1] << " " << a[2] << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
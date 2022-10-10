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

using cat = unsigned long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = 50000;
	cin >> N;
	vector<int> A(2*N);
	for(int i = 0; i < 2*N; i++) cin >> A[i];
	sort(begin(A), end(A));
	reverse(begin(A), end(A));
	int sum = 0;
	for(int i = 0; i < 2*N; i++) sum += A[i];
	vector<cat> pos[60][30];
	for(int i = 0; i < 2*N; i++) for(int j = 0; j < N; j++)
		pos[i][j] = vector<cat>((j*MX)/64+10, 0);
	pos[0][0][0] = 1;
	int cost = sum+1;
	vector< vector<int> > ans(2, vector<int>(N));
	for(int i = 0; i < 2*N-2; i++) {
		for(int j = 0; j <= N-1; j++) {
			for(int k = 0; k <= (j*MX)/64; k++) pos[i+1][j][k] |= pos[i][j][k];
			if(j == N-1) break;
			for(int k = 0; k <= (j*MX)/64; k++) {
				pos[i+1][j+1][k+A[i]/64] |= pos[i][j][k] << (A[i]%64);
				if(A[i]%64 != 0) pos[i+1][j+1][k+A[i]/64+1] |= pos[i][j][k] >> (64-A[i]%64);
			}
		}
		if(i >= N-1) for(int j = i+2; j < 2*N; j++) {
			int mi = (sum-A[i+1]-A[j]+1)/2;
			if(pos[i+1][N-1][mi/64]>>(mi%64)) {
				while(((pos[i+1][N-1][mi/64]>>(mi%64))&1) == 0) mi++;
			}
			else {
				int k = mi/64+1;
				while(k <= (N-1)*MX/64 && pos[i+1][N-1][k] == 0) k++;
				if(k > (N-1)*MX/64) continue;
				mi = k*64;
				while(((pos[i+1][N-1][mi/64]>>(mi%64))&1) == 0) mi++;
			}
			if(cost > mi+A[i+1]+A[j]) {
				cost = mi+A[i+1]+A[j];
				ans[0][0] = A[i+1];
				ans[1][N-1] = A[j];
				int pos_small = 1, pos_large = N-2;
				for(int k = 2*N-1; k > i+1; k--) if(k != j)
					ans[0][pos_small++] = A[k];
				int cur = N-1;
				for(int k = i; k >= 0; k--) {
					if(mi >= A[k] && mi-A[k] <= (cur-1)*MX && cur && (pos[k][cur-1][(mi-A[k])/64]>>((mi-A[k])%64))&1)
						cur--, mi -= A[k], ans[1][pos_large--] = A[k];
					else ans[0][pos_small++] = A[k];
				}
			}
		}
	}
	for(int i = 0; i < N; i++) cout << ans[0][i] << ((i == N-1) ? "\n" : " ");
	for(int i = 0; i < N; i++) cout << ans[1][i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
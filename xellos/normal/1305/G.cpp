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
	int N, MX = 1<<18;
	cin >> N;
	vector<int> occ(MX, 0);
	for(int i = 0, a; i < N; i++) {
		cin >> a;
		occ[a]++;
	}
	occ[0]++;
	vector<int> A;
	int B[19][MX];
	memset(B, 0, sizeof(B));
	for(int i = MX-1; i >= 0; i--) if(occ[i]) {
		A.push_back(i);
		B[0][i] = i;
	}
	N = A.size();
	for(int k = 0; k < 18; k++) {
		for(int i = 0; i < MX; i++) B[k+1][i] = B[k][i];
		for(int i = 0; i < MX; i++)
			B[k+1][i|(1<<k)] = max(B[k+1][i|(1<<k)], B[k][i] & (MX-1+((i>>k)&1)));
	}
	cat ans = 0;
	for(int i = 0; i < MX; i++) if(occ[i]) ans += 1LL * (occ[i]-1) * B[18][MX-1-i];
	vector< vector<int> > G(MX);
	vector<int> max_cur(MX, -1), used(MX, 0);
	for(int i = 0; i < N; i++)
		if(B[18][MX-1-A[i]] > A[i])
			G[B[18][MX-1-A[i]]].push_back(A[i]);
	memset(B, -1, sizeof(B));
	int live[19][MX];
	memset(live, 0, sizeof(live));
	for(int i = 0; i < N; i++) live[18][MX-1-A[i]] = A[i];
	for(int k = 17; k >= 0; k--)
		for(int i = 0; i < MX; i++) if(live[k+1][i]) {
			live[k][i] = max(live[k][i], live[k+1][i]);
			if((i>>k)&1) live[k][i-(1<<k)] = max(live[k][i-(1<<k)], live[k+1][i]);
		}
	priority_queue< pair<int, int> > q_v, q_e;
	q_v.push({live[0][0], 0});
	B[0][0] = live[0][0];
	used[0] = 1;
	for(int k = 0; k < N-1; k++) {
		while(!q_e.empty()) {
			auto [a, b] = q_e.top();
			if(used[b]) q_e.pop();
			else break;
		}
		while(!q_v.empty()) {
			auto [a, x] = q_v.top();
			int i = x/MX;
			x %= MX;
			if(!q_e.empty() && a <= q_e.top().ff) break;
			q_v.pop();
			if(a != B[i][x]) continue;
			if(i == 18) {
				if(!used[MX-1-x] && max_cur[MX-1-x] < a) {
					max_cur[MX-1-x] = a;
					q_e.push({a, MX-1-x});
				}
				continue;
			}
			a -= live[i][x];
			a += live[i+1][x];
			if(B[i+1][x] < a && live[i+1][x]) {
				B[i+1][x] = a;
				q_v.push({a, MX*(i+1)+x});
			}
			int y = x | (1<<i);
			a -= live[i+1][x];
			a += live[i+1][y];
			if(y != x && B[i+1][y] < a && live[i+1][y]) {
				B[i+1][y] = a;
				q_v.push({a, MX*(i+1)+y});
			}
		}
		int nxt = -1;
		while(!q_e.empty()) {
			auto [a, b] = q_e.top();
			q_e.pop();
			if(used[b]) continue;
			nxt = b;
			break;
		}
		assert(nxt != -1);
		ans += max_cur[nxt];
		static queue<int> q_t;
		q_t.push(nxt);
		used[nxt] = 1;
		while(!q_t.empty()) {
			if(live[0][q_t.front()]) {
				q_v.push({q_t.front()+live[0][q_t.front()], q_t.front()});
				B[0][q_t.front()] = q_t.front()+live[0][q_t.front()];
			}
			for(auto x : G[q_t.front()]) if(!used[x]) {
				used[x] = 1;
				ans += x + q_t.front();
				k++;
				q_t.push(x);
			}
			q_t.pop();
		}
	}
	for(int i = 0; i < N; i++) ans -= A[i];
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
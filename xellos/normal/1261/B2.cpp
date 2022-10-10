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
#define OVER9000 1234567890123456789LL
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

struct query {
	int K, id, q_id;

	bool operator<(const query & Q) const {
		return K < Q.K;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	vector< pair<int, int> > As(N);
	for(int i = 0; i < N; i++) As[i] = {A[i], -i};
	sort(begin(As), end(As));
	reverse(begin(As), end(As));
	vector<query> qu(Q);
	for(int q = 0; q < Q; q++) {
		int K, id;
		cin >> K >> id;
		qu[q] = {K, id, q};
	}
	sort(begin(qu), end(qu));
	vector<int> ans(Q);
	vector<char> used(N, 0);
	int K = 300;
	vector< vector<int> > id_seq(N+1);
	for(int q = 0, l = 0; q < Q; q++) {
		while(l < qu[q].K) {
			int id = -As[l++].ss;
			used[id] = true;
			vector<int> & v = id_seq[id-id%K];
			v.push_back(id);
			int cur = v.size()-1;
			while(cur && v[cur] < v[cur-1]) {
				swap(v[cur-1], v[cur]);
				cur--;
			}
		}
		int bl = 0, sz = 0;
		while(id_seq[bl * K].size() + sz < qu[q].id) {
			sz += id_seq[bl * K].size();
			bl++;
		}
		ans[qu[q].q_id] = id_seq[bl * K][qu[q].id - sz - 1];
	}
	for(int i = 0; i < Q; i++) cout << A[ans[i]] << "\n";
	return 0;
}

// look at my code
// my code is amazing
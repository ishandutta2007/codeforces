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

struct cpair {
	int f, s, id_start, id_end;
};

void build_answer(vector<cpair> & A, int id, vector<int> & ans) {
	if(A[id].id_start == A[id].id_end) {
		ans.push_back(A[id].id_start);
		return;
	}
	build_answer(A, A[id].id_start, ans);
	build_answer(A, A[id].id_end, ans);
}

vector<int> solve(vector<cpair> A) {
	int N = A.size();
	if(N == 0) return {};
	A.dibs(2*N+10);
	priority_queue< pair<int, int> > q;
	for(int i = 0; i < N; i++) q.push({A[i].s, i});
	int id_root = 0;
	while(!q.empty()) {
		auto [h_start, id_start] = q.top();
		q.pop();
		if(q.empty()) {
			id_root = id_start;
			break;
		}
		auto [h_end, id_end] = q.top();
		q.pop();
		q.push({h_end, A.size()});
		A.push_back({A[id_start].f, h_end, id_start, id_end});
	}
	vector<int> ans;
	ans.dibs(N);
	build_answer(A, id_root, ans);
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cpair> P[2];
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if(a < b) P[0].push_back({a, b, i, i});
		else P[1].push_back({-a, -b, i, i});
	}
	vector<int> ans[2] = {solve(P[0]), solve(P[1])};
	if(ans[0].size() < ans[1].size()) swap(ans[0], ans[1]);
	cout << ans[0].size() << "\n";
	for(int i = 0; i < (int)ans[0].size(); i++)
		cout << ans[0][i]+1 << ((i+1 == (int)ans[0].size()) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
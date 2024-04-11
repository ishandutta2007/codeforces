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
#define soclose 1e-5
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

struct knight {
	int id, p;
	cat c;

	bool operator<(const knight & K) const {
		return p < K.p;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector<knight> V(N);
	for(int i = 0; i < N; i++) {
		V[i].id = i;
		cin >> V[i].p;
	}
	for(int i = 0; i < N; i++) cin >> V[i].c;
	sort(begin(V), end(V));
	vector<cat> ans(N);
	priority_queue<cat, vector<cat>, greater<cat> > H;
	cat sum = 0;
	for(int i = 0; i < N; i++) {
		ans[V[i].id] = sum+V[i].c;
		H.push(V[i].c);
		sum += V[i].c;
		while((int)H.size() > K) {
			sum -= H.top();
			H.pop();
		}
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
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
/*
class ITree {
	struct node {};
	int b;

public:
	ITree(int N) {
		b = 1;
		while(b < N) b *= 2;
		T.resize(2*b+10, {0, 0});
	}

	void () {

	}
};
*/
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat P;
	cin >> N >> P;
	priority_queue< pair<cat, int>, vector< pair<cat, int> >, greater< pair<cat, int> > > q;
	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		q.push({t, i+1});
	}
	vector<cat> T(N), T_go(N);
	queue<int> f;
	set<int> w, in_f;
	while(!q.empty()) {
		auto [t, id] = q.top();
		q.pop();
		if(id > 0) w.insert(id-1);
		else {
			id = -id-1;
			f.pop();
			in_f.erase(id);
			if(!f.empty()) {
				T[f.front()] = max(T_go[f.front()], T[id]) + P;
				q.push({T[f.front()], -1-f.front()});
			}
		}
		if(q.empty() || q.top().ff > t)
		while(!w.empty() && (in_f.empty() || *begin(in_f) > *begin(w))) {
			T_go[*begin(w)] = t;
			if(f.empty()) {
				T[*begin(w)] = T_go[*begin(w)] + P;
				q.push({T[*begin(w)], -1-*begin(w)});
			}
			f.push(*begin(w));
			in_f.insert(*begin(w));
			w.erase(begin(w));
		}
	}
	for(int i = 0; i < N; i++) cout << T[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
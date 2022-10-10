// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);
	}
	vector<int> V(N);
	vector< vector<int> > by_topic(N);
	for(int i = 0; i < N; i++) {
		cin >> V[i];
		by_topic[--V[i]].push_back(i);
	}
	vector<int> P;
	for(int k = 0; k < N; k++) {
		for(auto v : by_topic[k]) {
			P.push_back(v+1);
			static vector<int> occ(N, 0);
			for(auto e : G[v]) if(V[e] <= V[v]) occ[V[e]]++;
			int cur = 0;
			while(cur < V[v] && occ[cur]) cur++;
			if(cur != V[v] || occ[cur]) {
				cout << "-1\n";
				return 0;
			}
			for(auto e : G[v]) if(V[e] <= V[v]) occ[V[e]]--;
		}
	}
	for(int i = 0; i < N; i++) cout << P[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
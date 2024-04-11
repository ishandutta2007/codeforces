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
	vector< vector<int> > G(N), Gi(N);
	vector<int> deg(N, 0);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		Gi[v].push_back(u);
		deg[v]++;
	}
	queue<int> q;
	for(int i = 0; i < N; i++) if(!deg[i]) q.push(i);
	vector<int> seq;
	while(!q.empty()) {
		seq.push_back(q.front());
		for(auto v : G[q.front()]) if(--deg[v] == 0) q.push(v);
		q.pop();
	}
	if((int)seq.size() != N) {
		cout << "-1\n";
		return 0;
	}
	vector<int> min_reach_up(N), min_reach_down(N);
	for(int i = 0; i < N; i++) min_reach_down[i] = min_reach_up[i] = i;
	for(auto v : seq) for(auto s : G[v])
		min_reach_up[s] = min(min_reach_up[s], min_reach_up[v]);
	reverse(begin(seq), end(seq));
	for(auto v : seq) for(auto s : Gi[v])
		min_reach_down[s] = min(min_reach_down[s], min_reach_down[v]);
	string ans;
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		bool b = (min_reach_down[i] < i || min_reach_up[i] < i);
		if(b) ans += 'E';
		else cnt++, ans += 'A';
	}
	cout << cnt << "\n" << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
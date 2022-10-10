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
	int L, N;
	cin >> L >> N;
	N--;
	vector<int> A(N+1);
	for(int i = 0; i <= N; i++) cin >> A[i];
	sort(begin(A), end(A));
	vector<int> D(N);
	for(int i = 0; i < N; i++) D[i] = A[i+1]-A[i];
	int G, R;
	cin >> G >> R;
	int T = (G+R)*(N+1);
	vector<int> X(T+1, 0);
	vector< vector<int> > V;
	vector<int> dist((G+1)*(N+1), T+1);
	dist[G*(N+1)] = 0;
	X[0] = G*(N+1)*4+1;
	for(int i = 0; i < T; i++) {
		if(X[i] == 0) continue;
		vector<int> * states;
		static vector<int> vs = {0};
		if((X[i]&3) == 1) {
			vs[0] = X[i]/4;
			states = &vs;
		}
		else states = &V[X[i]/4];
		for(auto st : *states) {
			if(dist[st] != i) continue;
			int g = st/(N+1), pos = st%(N+1);
			if(pos == N) {
				cout << i << "\n";
				return 0;
			}
			if(g == 0 && dist[G*(N+1)+pos] > i+R) {
				int next = G*(N+1)+pos;
				dist[next] = i+R;
				if(X[i+R] == 0) X[i+R] = next*4+1;
				else if((X[i+R]&3) == 1) {
					V.push_back({X[i+R]/4, next});
					X[i+R] = (V.size()-1)*4+2;
				}
				else V[X[i+R]/4].push_back(next);
			}
			if(g >= D[pos] && dist[(g-D[pos])*(N+1)+(pos+1)] > i+D[pos]) {
				int next = (g-D[pos])*(N+1)+(pos+1);
				dist[next] = i+D[pos];
				if(X[i+D[pos]] == 0) X[i+D[pos]] = next*4+1;
				else if((X[i+D[pos]]&3) == 1) {
					V.push_back({X[i+D[pos]]/4, next});
					X[i+D[pos]] = (V.size()-1)*4+2;
				}
				else V[X[i+D[pos]]/4].push_back(next);
			}
			if(pos && g >= D[pos-1] && dist[(g-D[pos-1])*(N+1)+(pos-1)] > i+D[pos-1]) {
				int next = (g-D[pos-1])*(N+1)+(pos-1);
				dist[next] = i+D[pos-1];
				if(X[i+D[pos-1]] == 0) X[i+D[pos-1]] = next*4+1;
				else if((X[i+D[pos-1]]&3) == 1) {
					V.push_back({X[i+D[pos-1]]/4, next});
					X[i+D[pos-1]] = (V.size()-1)*4+2;
				}
				else V[X[i+D[pos-1]]/4].push_back(next);
			}
		}
	}
	cout << "-1\n";
	return 0;
}

// look at my code
// my code is amazing
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
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int abs(int x) {return (x < 0) ? -x : x;}

int gcd(int x, int y) {
	if(x > y) swap(x, y);
	return (x == 0) ? y : gcd(y%x, x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int K, N;
	cin >> N >> K;
	map< pair<int, int>, vector<double> > P;
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		double d = sqrt(1LL*x*x+1LL*y*y);
		if(x || y) {
			int g = gcd(abs(x), abs(y));
			x /= g, y /= g;
		}
		P[{x, y}].push_back(d);
	}
	vector< vector<double> > PV;
	for(auto p : P) PV.push_back(p.ss);
	for(auto & v : PV) sort(begin(v), end(v));
	vector< pair<double, pair<int, int> > > V;
	for(int i = 0; i < (int)PV.size(); i++) {
		double s = 0, s0 = 0;
		double last = 0;
		for(int j = (int)PV[i].size()-1; j >= 0; j--) {
			int n = PV[i].size()-j;
			if(n > K) break;
			s += s0-PV[i][j]*(n-1);
			s0 += PV[i][j];
			V.push_back({s0*(K-n)+s-last, {i, j}});
			last = s0*(K-n)+s;
		}
	}
	sort(begin(V), end(V));
	double ans = 0;
	for(int i = (int)V.size()-1; i >= (int)V.size()-K; i--) ans += V[i].ff;
	vector< vector<int> > pos(PV.size());
	for(int i = 0; i < (int)PV.size(); i++) pos[i].resize(PV[i].size(), -1);
	int SZ = V.size();
	for(int i = 0; i < SZ; i++) pos[V[i].ss.ff][V[i].ss.ss] = i;
	int H = (K+1)/2; // number at the end
	double ans0 = ans;
	for(int i = 0; i < (int)PV.size(); i++) {
		int sz_c = PV[i].size();
		if(sz_c <= H) continue;
		double s = 0, s0 = 0;
		double last = 0;
		int cur = SZ-K, cur1 = K;
		double cur0 = ans0;
		int cur2 = SZ;
		for(int j = 0; j < sz_c; j++) if(sz_c-j <= K) {
			cur2--;
			if(pos[i][j] >= SZ-K) cur0 -= V[pos[i][j]].ff, cur1--;
		}
		for(int j = sz_c-1; j >= sz_c-H; j--) {
			int n = sz_c-j;
			s += s0-PV[i][j]*(n-1);
			s0 += PV[i][j];
		}
		double s1 = 0, sv = 0;
		for(int j = 0; j < sz_c-H; j++) {
			s += PV[i][j]*j-s1;
			s1 += PV[i][j];
			if(K-H-j-1 < 0 || K-H-j-1 > cur2) continue;
			while(cur1 > K-H-j-1) {
				while(V[cur].ss.ff == i) cur++;
				cur1--;
				cur0 -= V[cur].ff;
				cur++;
			}
			while(cur1 < K-H-j-1) {
				cur--;
				while(V[cur].ss.ff == i) cur--;
				cur0 += V[cur].ff;
			}
			// chcem z nepouzitych K-H-j-1 spravit sv
			ans = max(ans, (s0+s1)*(K-H-j-1)+s+s0*(j+1)-s1*H+cur0);
		}
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
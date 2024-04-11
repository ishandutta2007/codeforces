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

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

struct fin {
	vector<int> T;
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {return x & (x ^ (x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat K;
	cin >> N >> K;
	K = 1LL*N*(N-1)/2-K+1;
	vector< pair<cat, cat> > P(N);
	for(int i = 0; i < N; i++) cin >> P[i].ff >> P[i].ss;
	dbl ans_le = 0, ans_gt = 1e5;
	while(ans_gt-ans_le > soclose) {
		dbl R = (ans_le + ans_gt) / 2;
		vector< pair<dbl, int> > events;
		for(int i = 0; i < N; i++) {
			dbl d = sqrt(P[i].ff*P[i].ff+P[i].ss*P[i].ss);
			if(d < R+soclose) continue;
			dbl ang_c = atan2(P[i].ss, P[i].ff);
			if(ang_c < 0) ang_c = 2*pi+ang_c;
			dbl ang_d = acos(R/d);
			if(ang_c-ang_d < soclose) {
				events.push_back({ang_c+ang_d, 2*i});
				events.push_back({ang_c-ang_d, 2*i+1});
				events.push_back({ang_c-ang_d+2*pi, 2*i+1});
			}
			else if(ang_c+ang_d > 2*pi-soclose) {
				events.push_back({ang_c+ang_d-2*pi, 2*i});
				events.push_back({ang_c-ang_d, 2*i+1});
				events.push_back({ang_c-ang_d-2*pi, 2*i+1});
			}
			else {
				events.push_back({ang_c+ang_d, 2*i});
				events.push_back({ang_c-ang_d, 2*i+1});
			}
		}
		sort(begin(events), end(events));
		vector<int> last_open(N, -1);
		cat cnt = 0;
		fin F(events.size());
		for(int i = 0; i < (int)events.size(); i++) {
			int id = events[i].ss/2;
			if(events[i].ss%2 == 0) {
				if(last_open[id] != -1) {
					F.put(events.size()-last_open[id], -1);
					cnt += F.get(events.size()-last_open[id]);
					last_open[id] = -1;
				}
			}
			else {
				last_open[id] = i;
				F.put(events.size()-i, 1);
			}
		}
		if(cnt >= K) ans_le = R;
		else ans_gt = R;
	}
	cout << ans_le << "\n";
}

// look at my code
// my code is amazing
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cat D;
	cin >> N >> D >> M;
	vector<int> A_l, A_g;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a <= M) A_l.push_back(a);
		else A_g.push_back(a);
	}
	sort(begin(A_l), end(A_l));
	sort(begin(A_g), end(A_g));
	reverse(begin(A_l), end(A_l));
	reverse(begin(A_g), end(A_g));
	vector<cat> B_g(A_g.size()+1, 0);
	vector<cat> B_l(A_l.size()+1, 0);
	for(int i = 0; i < (int)A_g.size(); i++) B_g[i+1] = B_g[i]+A_g[i];
	for(int i = 0; i < (int)A_l.size(); i++) B_l[i+1] = B_l[i]+A_l[i];
	cat ans = 0;
	for(int k = 0; k <= (int)A_g.size(); k++) {
		if((D+1LL)*k < (cat)A_g.size()) continue;
		cat cur = B_g[k];
		int rm = 0;
		if(k && (k-1LL)*D+k-(cat)A_g.size() >= 0) {
			if((k-1LL)*D+k-(cat)A_g.size() > (cat)A_l.size()) continue;
			rm = (k-1LL)*D+k-(cat)A_g.size();
		}
		cur += B_l[A_l.size()-rm];
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MAX = 200006;
int n, A[MAX], B[MAX], LG[MAX];

template <typename F>
struct RMQ{
	int sz, lg;
	int **d;
	RMQ(int size, int *arr){
		sz = size;
		lg = 1;
		while((1<<lg) < sz) lg++;
		d = new int*[lg];
		FOR(i, lg) d[i] = new int[sz];
		FOR(i, sz) d[0][i] = arr[i];
		int i = 1;
		while((1<<i) <= sz){
			FOR(j, sz-(1<<i)+1){
				d[i][j] = F::ret(d[i-1][j], d[i-1][j+(1<<(i-1))]);
			}
			++i;
		}
	}

	~RMQ(){
		FOR(i, lg) delete[] d[i];
		delete[] d;
	}
	
	int query(int l, int r){
		int s = r - l + 1;
		return F::ret(d[LG[s]][l], d[LG[s]][l+s-(1<<LG[s])]);
	}
};
struct RMQmin{static int ret(const int &a, const int &b){return std::min(a, b);}};
struct RMQmax{static int ret(const int &a, const int &b){return std::max(a, b);}};


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	REP(i, 2, MAX) LG[i] = LG[i>>1]+1;
	std::cin >> n;
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) std::cin >> B[i];
	RMQ<RMQmax> mx(n, A);
	RMQ<RMQmin> mn(n, B);
	ll ans = 0;
	FOR(i, n){
		if(A[i] > B[i]) continue;
		int l = i;
		int r = n;
		while(l < r){
			int mid = (r + l) >> 1;
			if(mn.query(i, mid) - mx.query(i, mid) > 0){
				l = mid+1;
			}else{
				r = mid;
			}
		}
		int lu = i;
		int ru = n;
		while(lu < ru){
			int mid = (ru + lu) >> 1;
			if(mn.query(i, mid) - mx.query(i, mid) >= 0){
				lu = mid+1;
			}else{
				ru = mid;
			}
		}
		ans += std::max(0, lu - l);
	}
	std::cout << ans << "\n";
	return 0;
}
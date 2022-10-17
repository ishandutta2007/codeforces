#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

typedef std::pair<ll, ll> PLL;
constexpr ll INF = 1000666666ll*1000000000ll;

ll ans = 0;
int have = 0;

constexpr int N = 62;
typedef std::function<bool(ll, ll)> Comp;
struct Stack{
	Comp cmp;
	Stack* other;
	std::vector<PR<ll, PII>> vec;
	std::vector<std::vector<PR<int, PII>>> sum;

	Stack(Comp cmp_) : cmp(cmp_) {
		sum.resize(N);
	}

	int get_impl(int a, int kt){
		auto& xdd = sum[kt];

		int left = 0;
		int right = SZ(xdd);

		while(left < right){
			int mid = (left+right)/2;
			if(xdd[mid].Y.X > a){
				right = mid;
			}else{
				left = mid+1;
			}
		}
		left--;

		if(left == -1) return 0;

		int ret = xdd[left].X;
		return ret - std::max(0, xdd[left].Y.Y - a);
	}

	int get(int a, int b, int kt){
		return get_impl(b, kt) - get_impl(a-1, kt);
	}

	void prepush(ll v, int cur){
		while(SZ(vec) && cmp(v, vec.back().X)){
			int kt = __builtin_popcountll(vec.back().X);
			have -= other->get(vec.back().Y.X, vec.back().Y.Y, kt);
			sum[kt].pop_back();
			vec.pop_back();
		}

		int kt = __builtin_popcountll(v);
		int from = (SZ(vec) == 0 ? 0 : vec.back().Y.Y+1);
		vec.push_back(MP(v, MP(from, cur)));
		sum[kt].push_back(MP((sum[kt].empty() ? cur - from + 1 : sum[kt].back().X + cur - from + 1), MP(from, cur)));
	}

	int ost(){
		return vec.back().Y.Y - vec.back().Y.X;
	}

	void push(){
		have += other->get(vec.back().Y.X, vec.back().Y.Y, __builtin_popcountll(vec.back().X));
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<ll> A(n);
	FOR(i, n) std::cin >> A[i];

	Stack min([](ll a, ll b){return a < b;});
	Stack max([](ll a, ll b){return a > b;});
	min.other = &max;
	max.other = &min;

	FOR(i, n){
		max.prepush(A[i], i);
		min.prepush(A[i], i);
		if(max.ost() > min.ost()) max.push();
		else min.push();
		ans += have;
	}

	std::cout << ans << "\n";
	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef std::function<ll(ll)> fun;

class Map{
	int n, w, r;
	std::vector<int> A, B;
	std::function<int(ll)> lower, upper;
	std::vector<ll> who;
	std::vector<int> val;

	void find_array(std::vector<int> &a, const std::vector<ll> &S, fun f, fun g){
		a.resize(1<<r);
		std::vector<std::list<ll> > set(1<<r);
		std::vector<int> m(1<<(r+1));
		for(ll x : S) set[f(x)].push_back(x);
		std::vector<int> ind(1<<r);
		std::vector<int> pref(S.size()+1);
		for(int i = 0; i < (1<<r); ++i) pref[set[i].size()]++;
		for(int i = 1; i < (int)S.size()+1; ++i) pref[i] += pref[i-1];
		for(int i = 0; i < (1<<r); ++i) ind[--pref[set[i].size()]] = i;
		std::reverse(ind.begin(), ind.end());
		std::mt19937 gen;
		gen.seed(666);
		std::uniform_int_distribution<int> rnd(0, (1<<r)-1);
		int prev = 0;
		for(auto i : ind){
			if(set[i].size() == 0) break;
			while(true){
				a[i] = rnd(gen);
				int sum = 0;
				for(ll y : set[i]) sum += m[g(y)^a[i]];
				if(sum <= ((((ll)set[i].size())*prev)>>(r-1))) break;
			}
			for(ll y : set[i]) m[g(y)^a[i]]++;
			prev += set[i].size();
		}
	}
public:
	Map(){}
	Map(const std::vector<ll> &S, int word){ init(S, word); }
	int operator()(ll x){
		return lower(x)^B[upper(x)^A[lower(x)]];
	}
	int size(){
		return (1<<r);
	}
	bool have(ll x){
		return who[(*this)(x)] == x;
	}
	int& operator[](ll i){
		return val[(*this)(i)];
	}
	void init(const std::vector<ll> &S, int word){
		n = (int)S.size();
		w = word;
		r = std::max(w/2, (int)std::log2(n)+3)+1;
		lower = [&](ll x){
			return x&((1<<r)-1);
		};
		upper = [&](ll x){
			return x>>(w-r);
		};
		find_array(A, S, lower, upper);
		auto f2 = [&](ll x){
			return upper(x)^A[lower(x)];
		};
		auto &g2 = lower;
		find_array(B, S, f2, g2);
		who.resize(1<<r, -1);
		for(ll x : S) who[(*this)(x)] = x;
		val.resize(1<<r);
	}
};

void make_unique(std::vector<ll> &A){
	std::sort(A.begin(), A.end());
	A.resize(std::unique(A.begin(), A.end())-A.begin());
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> A(n);
	ll pref = 0;
	std::vector<ll> values;
	values.push_back(pref);
	for(int i = 0; i < n; ++i){
		std::cin >> A[i];
		pref += A[i];
		values.push_back(pref);
	}
	make_unique(values);
	ll min = *std::min_element(values.begin(), values.end());
	std::vector<ll> lower, upper;
	for(ll x : values) lower.push_back((x-min)&((1<<24)-1)), upper.push_back((x-min)>>24);
	make_unique(lower);
	make_unique(upper);
	Map ml(lower, 24);
	Map mu(upper, 24);
	std::vector<ll> vals;
	auto kto = [&](ll x){
		if(!ml.have((x-min)&((1<<24)-1)) || !mu.have((x-min)>>24)) return -1ll;
		return ml((x-min)&((1<<24)-1)) + 1ll*ml.size()*mu((x-min)>>24);
	};
	for(ll x : values) vals.push_back(kto(x));
	make_unique(vals);
	Map map(vals, 40);
	ll ans = 0;
	pref = 0;
	map[kto(pref)]++;
	for(int i = 0; i < n; ++i){
		pref += A[i];
		ll pow = 1;
		while(std::abs(pow) < 1000000000ll*100000ll+5ll){
			ll want = (pref-pow);
			if(want >= min && want <= min + (1ll<<48)){
				if(kto(want) != -1 && map.have(kto(want))){
					ans += map[kto(want)];
				}
			}
			pow *= k;
			if(pow == 1) break;
		}
		map[kto(pref)]++;
	}
	std::cout << ans << "\n";
	return 0;
}
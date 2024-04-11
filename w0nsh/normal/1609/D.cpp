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

std::multiset<int> sizes;
int moge;
struct UF{
	VI repr;
	VI size;

	void Init(int n){
		repr = VI(n);
		FOR(i, n) repr[i] = i;
		size = VI(n, 1);
		FOR(i, n) sizes.insert(1);
	}

	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}

	void Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a == b){
			moge++;
		}else{
			sizes.erase(sizes.find(size[a]));
			sizes.erase(sizes.find(size[b]));
			repr[a] = b;
			size[b] += size[a];
			sizes.insert(size[b]);
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, d;
	std::cin >> n >> d;

	UF uf;
	uf.Init(n);
	moge = 1;

	FOR(_, d){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		uf.Union(a, b);

		auto it = sizes.end();
		int ans = 0;
		FOR(xdd, moge){
			if(it == sizes.begin()) break;
			it--;
			ans += *it;
		}

		std::cout << ans-1 << "\n";
	}

	return 0;
}
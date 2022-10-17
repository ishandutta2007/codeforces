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

constexpr int MAX = 500005;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m, k, n, s;
	std::cin >> m >> k >> n >> s;
	VI A(m);
	VI want(MAX);
	VI have(MAX);
	FOR(i, m) std::cin >> A[i];
	int need = 0;
	FOR(i, s){
		int a;
		std::cin >> a;
		if(want[a] == 0) need++;
		want[a]++;
	}

	auto dawaj = [&](int a, int b){
		int pre = a%k;
		VI ans;
		int pos = 0;
		while(SZ(ans) < pre) ans.push_back(pos++);

		std::fill(have.begin(), have.end(), 0);
		int srod = b-a - k;
		REP(i, a, b){
			if(srod <= 0) break;
			if(have[A[i]] < want[A[i]]){
				have[A[i]]++;
				continue;
			}
			ans.push_back(i);
			srod--;
		}

		// std::cerr << a << " " << b-1 << std::endl;

		std::cout << SZ(ans) << "\n";
		TRAV(i, ans) std::cout << i+1 << " ";

	};

	int wyjeb = m - k*n;

	int left = 0;
	int right = 0;
	while(left < m){
		while(need && right < m){
			have[A[right]]++;
			if(have[A[right]] == want[A[right]]){
				need--;
			}
			right++;
		}

		if(!need){
			int pre = left % k;
			int len = right - left;
			assert(len >= s);
			int srod = std::max(0, len - k);

			if(pre + srod <= wyjeb){
				dawaj(left, right);
				return 0;
			}
		}

		if(have[A[left]] == want[A[left]]){
			need++;
		}
		have[A[left]]--;
		left++;
	}

	std::cout << -1 << "\n";

	return 0;
}
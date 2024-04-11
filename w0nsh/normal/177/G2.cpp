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

// pi[i] = lps of prefix of length i
std::vector<int> calc_pi(const std::string &s){
	std::vector<int> pi(s.size()+1);
	int b;
	pi[0] = b = -1;
	for(int i = 1; i <= (int)s.size(); i++){
		while((b > -1) && (s[b] != s[i - 1])) b = pi[b];
		pi[i] = ++b;
	}
	return pi;
}

int find(const std::string &w, const std::string &s){
	int ret = 0;
	std::vector<int> pi = calc_pi(w);
	int b = 0, m = (int)w.size();
	for(int i = 0; i < (int)s.size(); ++i){
		while((b > -1) && (w[b] != s[i])) b = pi[b];
		if(++b == m) ret++, b = pi[b];
	}
	return ret;
}

std::vector<std::string> fibo;

constexpr int MOD = 1000000007;

struct Mat{
	int tab[2][2];
	Mat(){
		tab[0][0] = tab[1][1] = 1;
		tab[0][1] = tab[1][0] = 0;
	}
};

std::ostream& operator<<(std::ostream& stream, const Mat& mat){
	FOR(i, 2){
		FOR(j, 2){
			stream << mat.tab[i][j] << " ";
		}
		stream << "\n";
	}
	return stream;
}

Mat mul(const Mat& a, const Mat& b){
	Mat ret;
	FOR(i, 2){
		FOR(j, 2){
			ret.tab[i][j] = 0;
			FOR(k, 2){
				ret.tab[i][j] = (ret.tab[i][j] + 1ll * a.tab[i][k] * b.tab[k][j]) % MOD;
			}
		}
	}
	return ret;
}

Mat fastpow(Mat a, ll e){
	Mat ret;
	while(e){
		if(e&1) ret = mul(a, ret);
		a = mul(a, a);
		e>>=1;
	}
	return ret;
}

int get_fib(ll k){
	Mat mat;
	mat.tab[1][0] = 1;
	mat.tab[0][1] = 1;
	mat.tab[1][1] = 0;
	return fastpow(mat, k).tab[0][0];
}

int solve(std::string s, ll k){
	int kt = 0;
	while(kt < k && SZ(fibo[kt]) < SZ(s)){
		kt++;
	}

	if(kt == k || kt+1 == k){
		return find(s, fibo[k]);
	}

	int a = find(s, fibo[kt]);
	int b = find(s, fibo[kt+1]);
	int ab = find(s, fibo[kt] + fibo[kt+1]) - a - b;
	int ba = find(s, fibo[kt+1] + fibo[kt]) - a - b;
	int bb = find(s, fibo[kt+1] + fibo[kt+1]) - b - b;
	k -= kt;

	assert(k >= 2);

	int ret = 0;
	ret = (ret + 1ll * get_fib(k-2) * a)%MOD;
	ret = (ret + 1ll * get_fib(k-1) * b)%MOD;
	{
		int ile = get_fib(k-2);
		if(k % 2 == 0){
			ile--;
			if(ile < 0) ile += MOD;
		}
		ret = (ret + 1ll * ile * ab)%MOD;
	}
	ret = (ret + 1ll * get_fib(k-2) * ba)%MOD;
	{
		int ile = 0;
		if(k > 2){
			ile = get_fib(k-3);
			if(k % 2 == 1){
				ile--;
				if(ile < 0) ile += MOD;
			}
		}
		ret = (ret + 1ll * ile * bb) % MOD;
	}

	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fibo.push_back("a");
	fibo.push_back("b");
	while(SZ(fibo.back()) < 500'000){
		fibo.push_back(fibo[SZ(fibo)-1] + fibo[SZ(fibo)-2]);
	}

	// std::vector<std::string> xd = {
	// 	"a",
	// 	"b",
	// 	"ab",
	// 	"ba",
	// 	"aa",
	// 	"bb"
	// };
	// TRAV(x, xd){
	// 	std::cout << x << ":";
	// 	FOR(i, 20){
	// 		std::cout << "  " << find(x, fibo[i]) << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	ll k, m;
	std::cin >> k >> m;
	k--;

	FOR(i, m){
		std::string s;
		std::cin >> s;
		std::cout << solve(s, k) << "\n";
	}

	return 0;
}
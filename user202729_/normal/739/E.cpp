// http://codeforces.com/contest/739/problem/E
// Codeforces Round #381 (Div. 1)
// E. Gosha is hunting
// DP optimization technique

#include <iostream>
#include <vector>
#include <iomanip>

std::vector<double> pokeprob, ultraprob;
double npokeball, nultraball;
int npokemon;

struct res {
	double expected; // with subtracting cost
	int nultra;

	void optimizeby(res r1) {
		if (r1.expected > expected) {
			expected = r1.expected; nultra = r1.nultra;
		}
	}

	res add(double expected, int nultra) {
		return {this->expected + expected, this->nultra + nultra};
	}

	bool operator < (res r1) const {
		return expected < r1.expected;
	}
};

res solve(double ultracost) { // solve the problem: what is the maximum expected value
	// of pokemons if for each ultra ball you throw, you lose [ultracost] pokemons ?

	// let result [mpokemon][mpokeball] = result when you tried to catch [mpokemon] first pokemons
	// and used [mpokeball] poke balls.
	std::vector<std::vector<res>> result (npokemon + 1, std::vector<res>(npokeball + 1, {0., 0}));

	for (int mpokemon = 1; mpokemon <= npokemon; ++mpokemon) {
		for (int mpokeball = 0; mpokeball <= npokeball; ++mpokeball) {
			res& cur = result[mpokemon][mpokeball];

			// doesn't try to catch this pokemon
			cur.optimizeby(result[mpokemon - 1][mpokeball]);

			// throw 1 ultraball
			cur.optimizeby(result[mpokemon - 1][mpokeball]
				.add(ultraprob[mpokemon - 1] - ultracost, 1));

			if (mpokeball != 0) {

				// throw 1 pokeball
				cur.optimizeby(result[mpokemon - 1][mpokeball - 1].add(pokeprob[mpokemon - 1], 0));

				// throw 1 pokeball and 1 ultraball
				cur.optimizeby(result[mpokemon - 1][mpokeball - 1].add(
					pokeprob[mpokemon - 1] + ultraprob[mpokemon - 1] -
					ultraprob[mpokemon - 1] * pokeprob[mpokemon - 1] - ultracost, 1
				));

			}
		}
	}

	// max element by expected
	// return *std::max_element(result[npokemon].begin(), result[npokemon].end());

	// wait, the more balls you throw, the more pokemons you can catch.
	return result[npokemon][npokeball];
}

int main() {
	#ifndef _GLIBCXX_DEBUG
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	#endif // _GLIBCXX_DEBUG

	std::cin >> npokemon >> npokeball >> nultraball;
	pokeprob.resize(npokemon); for (double & x : pokeprob) std::cin >> x;
	ultraprob.resize(npokemon); for (double & x : ultraprob) std::cin >> x;

	std::cout << std::fixed << std::setprecision(10);
	std::cerr << std::setprecision(17);

	double l = 0, r = 1;

	// must loop a nonzero times otherwise r and mid won't be initialized
	// 53 times are probably enough, because double...
	for (int _ = 0; _ < 53; ++_) {
		double mid = (l + r) / 2;
		res a = solve(mid);

//		std::cerr << "mid = " << mid << ", a = {" << a.expected << ", " << a.nultra << "}\n";

		if (a.nultra > nultraball) {
			// you spent more than necessary, need to increase cost for each ultraball
			l = mid;
		} else {
			r = mid;
		}
	}

	res a = solve(r);

//	if (a.nultra != nultraball) {
//		std::cerr << "Number of ultra ball thrown = " << a.nultra << ", "
//		"expected number of ultra ball = " << nultraball << '\n';
//	}

	std::cout << a.expected + nultraball * r << '\n';
	std::cout .flush();

}
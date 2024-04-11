#include <iostream>
#include <string>
#include <array>

std::string const f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
std::string const fa = "What are you doing while sending \"", fb = "\"? Are you busy? Will you send \"", fc = "\"?";

int64_t const MAX = 3e18;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	std::array<int64_t, 100001> len;
	len[0] = f0.length();
	for (size_t i = 1; i < len.size(); ++i) {
		len[i] = std::min(MAX, 2 * (int64_t)len[i-1] + fa.length() + fb.length() + fc.length());
	}

	int q; std::cin >> q;
	while (q --> 0) {
		int n; int64_t k;
		std::cin >> n >> k; --k;

		while (true) {
			if (n == 0) {
				std::cout << (k < f0.length() ? f0[k] : '.');
				break;
			}

			// f[n] = fa + f[n-1] + fb + f[n-1] + fc
			if (k < fa.length()) { std::cout << fa[k]; break; }
			k -= fa.length();
			if (k < len[n-1]) { --n; continue; }
			k -= len[n-1];
			if (k < fb.length()) { std::cout << fb[k]; break; }
			k -= fb.length();
			if (k < len[n-1]) { --n; continue; }
			k -= len[n-1];
			if (k < fc.length()) { std::cout << fc[k]; break; }

			std::cout << '.'; break;
		}

	}
	std::cout << '\n';
}
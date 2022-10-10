#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

const int ms = 1001000;
const int me = 26;

int f[ms][me], w[ms][me];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m;
	std::cin >> n >> m;
	std::string a, b;
	std::cin >> a >> b;
	long long ans = n * a.size();
	long long size = ans;
	long long g = gcd(a.size(), b.size());
	for(int i = 0; i < (int) a.size(); i++) {
		f[i % g][a[i] - 'a']++;
	}
	for(int i = 0; i < (int) b.size(); i++) {
		w[i % g][b[i] - 'a']++;
	}
	long long groups = size / lcm(a.size(), b.size());
	for(int i = 0; i < g; i++) {
		for(int j = 0; j < 26; j++) {
			ans -= groups * f[i][j] * w[i][j];
		}
	}
	std::cout << ans << '\n';
}
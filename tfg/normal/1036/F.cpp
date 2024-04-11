#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 65;
const int mv = 1.1e6;
const long long INF = (long long) 1e18;

long long top[mv], cur[mv];
std::vector<long long> down[ms];
int pt[ms];
bool np[ms];
int mob[ms];

void pre() {
	// calculating mobius
	for(int i = 1; i < ms; i++) {
		mob[i] = 1;
	}
	for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		for(int j = i; j < ms; j += i) {
			np[j] = true;
			mob[j] *= -1;
			if((j / i) % i == 0) {
				mob[j] = 0;
			}
		}
	}
	for(int i = 1; i < ms; i++) {
		//std::cout << "mobius of " << i << " is " << mob[i] << std::endl;
	}
	// calculating groups
	for(int i = 2; i < mv; i++) {
		top[i] = INF;
		top[i] /= i;
		top[i] /= i;
		cur[i] = (long long) i * i;
	}
	for(int j = 3; j < ms; j++) {
		for(int i = 2; top[i] / i > 0; i++) {
			//std::cout << "pushing (" << top[i] << ", " << i << ", " << cur[i] << ") for " << j << std::endl;
			top[i] /= i;
			cur[i] *= i;
			down[j].push_back(cur[i]);
			//std::cout << "pushing (" << top[i] << ", " << i << ", " << cur[i] << ") for " << j << std::endl;
		}
	}
}

long long solve(long long n) {
	long long ans = n - 1;
	// fixing pointers
	for(int i = 3; i < ms; i++) {
		while(pt[i] < (int) down[i].size() && down[i][pt[i]] <= n) {
			pt[i]++;
		}
	}
	// calculating
	long long sqr = (long long) sqrt((double)ans);
	sqr = std::max(sqr - 2, 1LL);
	while((sqr + 1) * (sqr + 1) <= n) sqr++;
	//std::cout << "answering " << n << ", base is " << ans << ", sqr is " << sqr << std::endl;
	ans -= sqr - 1;
	for(int i = 3; i < ms; i++) {
		/*if(mob[i] * pt[i] > 0) {
			std::cout << " on " << i << ", got " << mob[i] << " * " << pt[i] << std::endl;
		}*/
		ans += mob[i] * pt[i];
	}
	//std::cout << "returning " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	pre();
	int t;
	std::cin >> t;
	std::vector<std::pair<long long, int>> qries;
	for(int i = 0; i < t; i++) {
		long long n;
		std::cin >> n;
		qries.emplace_back(n, i);
	}
	std::vector<long long> ans(t, 0);
	std::sort(qries.begin(), qries.end());
	for(auto q : qries) {
		ans[q.second] = solve(q.first);
	}
	for(int i = 0; i < t; i++) {
		std::cout << ans[i] << '\n';
	}
}
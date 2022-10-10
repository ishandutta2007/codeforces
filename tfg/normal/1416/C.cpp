#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int me = 30;

int c = 1;
int f[ms * 31], to[ms * 31][2];

long long wtf[me];
long long curInv = 0;

void add(int x) {
	int on = 0;
	for(int i = me-1; i >= 0; i--) {
		int b = (x >> i) & 1;
		if(!to[on][b]) {
			to[on][b] = c++;
		}
		if(to[on][b^1]) {
			if(b == 0) {
				curInv += f[to[on][b^1]];
				wtf[i] -= f[to[on][b^1]];
			} else {
				wtf[i] += f[to[on][b^1]];
			}
		}
		on = to[on][b];
		f[on]++;
	}
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		int x;
		std::cin >> x;
		add(x);
	}
	int ans = 0;
	for(int i = me - 1; i >= 0; i--) {
		if(wtf[i] < 0) {
			ans |= 1 << i;
			curInv += wtf[i];
		}
	}
	std::cout << curInv << ' ' << ans << '\n';
}
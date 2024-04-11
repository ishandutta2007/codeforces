#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

long long n;

void answer(){
	long long count = 1;
	// from 2 to n-1
	long long last = 0;
	long long cur_pot = (1ll<<44);
	while(cur_pot >= 2){
		long long now = (n-1)/cur_pot;
		count += (now - last)*cur_pot;
		last = now;
		cur_pot >>= 1;
	}
	count += (n>>1)-1;
	std::cout << count << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	answer();
	return 0;
}
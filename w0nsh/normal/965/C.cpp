#include <iostream>
#include <algorithm>
long long n, k, M, D, best;
int main(){
	std::cin >> n >> k >> M >> D;
	for(int d = 1; d <= std::min((n/k)+1, D); ++d){
		long long max = std::min(M, n / (k*(d-1) + 1));
		long long min = n / (k*d) - 1;
		if(max >= min && max*d > best) best = max*d; 
	}
	std::cout << best << "\n";
	return 0;
}
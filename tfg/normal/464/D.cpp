#include <iostream>
#include <iomanip>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cout << std::fixed << std::setprecision(20);
	int n, k;
	std::cin >> n >> k;
	long double ratio = 1.0 / k;
	//ratio = 1;
	int m = std::min(n + 2, 700);
	std::vector<double> prob(m, 0);
	std::vector<double> nxtp(m, 0);
	prob[1] = 1;
	long double sum = 0;
	int l = 1;
	for(int i = 0; i < n; i++) {
		//std::vector<long double> nxtp(m + 1, 0);
		while(l + 1 < m && prob[l] < 1e-25) {
			l++;
		}
		for(int j = l; j < m && (j - l <= 50 || prob[j] > 1e-25 || prob[j-1] > 1e-25); j++) {
			nxtp[j] = (prob[j] * j / (j + 1) + prob[j - 1] * 1 / j) * ratio + prob[j] * (1 - ratio);
			double getProbability = (prob[j] * j / (j + 1)) * ratio;
			double thisProbability = (prob[j] * 1 / (j + 1)) * ratio;
			//std::cout << "probability for " << j << " is " << (double) getProbability << " and " << (double) thisProbability << std::endl;
			sum += getProbability * (j + 1) / 2 + thisProbability * j;
		}
		while(l + 1 < m && prob[l] < 1e-17) {
			l++;
		}
		/*for(int j = 0; j < m; j++) {
			std::cout << (double)nxtp[j] << (j + 1 == m ? '\n' : ' ');
		}*/
		nxtp.swap(prob);
	}
	std::cout << (double) sum * k << std::endl;
}
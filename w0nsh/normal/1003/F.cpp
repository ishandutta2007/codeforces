#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

const int NMAX = 300;

int n;
int s[NMAX+5][NMAX+5];
std::string w[NMAX];

void answer(){
	int total_size = n-1;
	for(int i = 0; i < n; ++i) total_size += w[i].size();
	int best = total_size;
	for(int i = 0; i < n; ++i){
		int size = 0;
		for(int j = 0; j+i < n; ++j){
			size += w[j+i].size() - 1;
			int count = 1;
			int k = i+j+1;
			while(k < n){
				if(s[i][k] >= j + 1){
					k += j + 1;
					count++;
				}else k++;
			}
			if(count >= 2){
				best = std::min(best, total_size - (size * count) - count*j);
			}
		}
	}
	std::cout << best << "\n";
}

void calc_s(){
	for(int i = n-2; i >= 0; i--){
		for(int j = n-1; j > i; j--){
			s[i][j] = s[j][i] = (w[i] == w[j] ? 1+s[i+1][j+1] : 0);
		}
	}
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 0; i < n; ++i) std::cin >> w[i];
}

int main(){
	read();
	calc_s();
	answer();
	return 0;
}
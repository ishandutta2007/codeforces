#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

const int MOD = 998244353;

int n;
std::vector<int> A;
int binco_tab[1001][1001];

int binco(int vn, int vk){
	if(vk == 0 || vk == vn) return 1;
	return binco_tab[vn][vk];
}

std::vector<int> starting;
int ret;

void answer(){
	ret = 0;
	starting.resize(n+1, 0);
	int before = 1;
	for(int i = 0; i < n; ++i){
		before = (before + starting[i]) % MOD;
		if(A[i] <= 0) continue;
		for(int j = i+1; j < n; ++j){
			if(j-i < A[i]) continue;
			int moz = binco(j-i-1, A[i]-1);
			int add = (1ll*moz*before) % MOD;	
			starting[j+1] = (starting[j+1] + add) % MOD;
			ret = (ret + add) % MOD;
		}
	}
	std::cout << ret << "\n";
}
/*
void answer(){
	ret = 0;
	starting.resize(n+1, 1);
	for(int i = 0; i < n; ++i){
		if(A[i] <= 0) continue;
		for(int j = i+1; j < n; ++j){
			if(j-i < A[i]) continue;
			int moz = binco(j-i-1, A[i]-1);
			int add = (1ll*moz*starting[i]) % MOD;
			for(int k = j+1; k < n; ++k){
				starting[k] = (starting[k] + add) % MOD;
			}
			// starting[j+1] = (starting[j+1] + add) % MOD;
			ret = (ret + add) % MOD;
		}
	}
	std::cout << ret << "\n";
}*/

void calc_binco(){
	for(int i = 1; i < 1000; ++i){
		for(int j = 1; j < i; ++j){
			binco_tab[i][j] = (binco(i-1, j-1) + binco(i-1, j)) % MOD;
		}
	}	
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	for(int i = 0; i < n; ++i){
		std::cin >> A[i];
	}
}

int main(){
	read();
	calc_binco();
	answer();
	return 0;
}
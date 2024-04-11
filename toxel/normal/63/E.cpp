#include<bits/stdc++.h>

const int N = 20;

bool dp[1 << N];
std::vector <std::vector <int>> vec = {{0, 1, 2},
									   {3, 4, 5, 6},
									   {7, 8, 9, 10, 11},
									   {12, 13, 14, 15},
									   {16, 17, 18},
									   {0, 3, 7},
									   {1, 4, 8, 12},
									   {2, 5, 9, 13, 16},
									   {6, 10, 14, 17},
									   {11, 15, 18},
									   {7, 12, 16},
									   {3, 8, 13, 17},
									   {0, 4, 9, 14, 18},
									   {1, 5, 10, 15},
									   {2, 6, 11}};

char s[N];

int main(){
	int n = 0;
	for (int i = 0; i < 19; ++ i){
		scanf("%s", s);
		n |= (s[0] == 'O' ? 1 : 0) << i;
	}
	std::vector <int> trans;
	for (auto &u : vec){
		int sz = u.size();
		for (int i = 0; i < sz; ++ i){
			for (int j = i; j < sz; ++ j){
				int x = 0;
				for (int k = i; k <= j; ++ k){
					x |= 1 << u[k];
				}
				trans.push_back(x);
			}
		}
	}
	for (int i = 1; i < 1 << 19; ++ i){
		for (auto u : trans){
			if ((i & u) == u && !dp[i ^ u]){
				dp[i] = true;
				break;
			}
		}
	}
	puts(dp[n] ? "Karlsson" : "Lillebror");
	return 0;
}
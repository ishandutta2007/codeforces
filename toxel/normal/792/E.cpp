#include<bits/stdc++.h>

const int N = 10000010;

int cnt[N], a[1000];
std::map <int, int> Hash;

void insert(int x){
	if (x < N){
		++ cnt[x];
	}
	else{
		++ Hash[x];
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		a[i] = x;
		for (int j = 1; j * j <= x; ++ j){
			if (x % j){
				continue;
			}
			insert(j);
			if (j > 1 && x % (j - 1)){
				insert(j - 1);
			}
			if (j * j == x){
				continue;
			}
			insert(x / j);
			if (x % (x / j - 1)){
				insert(x / j - 1);
			}
		}
		for (int j = 1, k; j < x; j = k + 1){
			k = x / (x / j);
			if (!(x % (x / k)) || !(x % (x / k + 1))){
				continue;
			}
			insert(x / k);
		}
		std::vector<int> vec;
		for (auto u : Hash){
			if (u.second <= i){
				vec.push_back(u.first);
				//Hash.erase(u.first);
			}
		}
		for(auto u : vec){
			Hash.erase(u);
			
		}
	}
	int max = 0;
	for (int i = 1; i < N; ++ i){
		if (cnt[i] == n){
			max = std::max(max, i);
		}	
	}
	for (auto u : Hash){
		max = std::max(max, u.first);
	}
	long long ret = 0;
	for (int i = 0; i < n; ++ i){
		int left = 1, right = a[i];
		if (!(a[i] % (max + 1))){
			ret += a[i] / (max + 1);
			continue;
		}
		while (left < right){
			int mid = left + right + 1 >> 1;
			if (a[i] / mid > max){
				left = mid;
			}
			else{
				right = mid - 1;
			}
		}
		ret += a[i] / left == max ? left : left + 1;
	}
	return printf("%I64d\n", ret), 0;
}
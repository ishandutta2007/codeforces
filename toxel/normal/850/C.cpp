#include<bits/stdc++.h>

const int N = 40010;

struct HashFunc{
	unsigned long long operator()(const std::set <int> &key)const &{
		unsigned long long ret = 0;
		for (auto u : key){
			ret = ret * 233 + u;
		}
		return ret;
	}
};

int n;
int a[N], min[N];
std::vector <int> prime;
std::set <int> primes;
std::unordered_map <std::set <int>, int, HashFunc> Hash;

int solve(std::set <int> set){
	if (set.empty()) return 0;
	if (Hash.count(set)){
		return Hash[set];
	}
	int max = *(-- set.end());
	std::set <int> sg;
	for (int i = 1; i <= max; ++ i){
		std::set <int> sset;
		for (auto u : set){
			if (u < i){
				sset.insert(u);
			}
			else if (u > i){
				sset.insert(u - i);
			}
		}
		sg.insert(solve(sset));
	}
	for (int i = 0; ; ++ i){
		if (!sg.count(i)){
			return Hash[set] = i;
		}
	}
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            prime.push_back(i);
            min[i] = i;
        }
        for (int j = 0, k, sz = (int) prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
    	scanf("%d", &a[i]);
    	int x = a[i];
		for (auto u : prime){
			if (!(x % u)){
				primes.insert(u);
				while (!(x % u)){
    				x /= u;
    			}
    		}
    	}
    	if (x > 1){
    		primes.insert(x);
    	}
    }
    int ans = 0;
    for (auto u : primes){
    	std::set <int> set;
    	for (int i = 0; i < n; ++ i){
    		int x = a[i], cnt = 0;
    		while (!(x % u)){
    			x /= u;
    			++ cnt;
    		}
    		if (cnt){
    			set.insert(cnt);
    		}
    	}
    	ans ^= solve(set);
    }
	return printf(ans ? "Mojtaba\n" : "Arpa\n"), 0;
}
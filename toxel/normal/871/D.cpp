#include<bits/stdc++.h>

const int N = 10000010;
typedef long long ll;

int min[N], cnt[N], phi[N];
std::vector <int> prime;

int main(){
    int n;
    scanf("%d", &n);
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i){
        if (!min[i]){
        	min[i] = i;
            phi[i] = i - 1;
            prime.push_back(i);
        }
        for (int j = 0, k, sz = (int) prime.size(); j < sz && i * prime[j] <= n; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                phi[k] = phi[i] * prime[j];
                break;
            }
        	phi[k] = phi[i] * (prime[j] - 1);
        }
        ++ cnt[min[i]];
    }
    ll cnt0 = 1;
	for (auto u : prime){
    	cnt0 += u << 1 > n;
    }
    cnt0 = cnt0 * (n - cnt0) + cnt0 * (cnt0 - 1) / 2;
    ll cnt1 = 1ll * n * (n - 1) >> 1;
	for (int i = 2; i <= n; ++ i){
		cnt1 -= phi[i];
	}
	ll cnt2 = 0;
    for (int i = 0, sz = prime.size(); i < sz; ++ i){
    	for (int j = 0; j < sz; ++ j){
    		if (prime[i] * prime[j] > n) break;
    		if (prime[i] == prime[j]) continue;
    		cnt2 += 1ll * cnt[prime[i]] * cnt[prime[j]];
    	}
    }
    for (auto u : prime){
    	cnt2 += 1ll * cnt[u] * cnt[u];
    }
    for (int i = 2; i <= n; ++ i){
    	if (1ll * min[i] * min[i] > n){
    		for (int j = i << 1; j <= n; j += i){
    			if (1ll * min[j] * min[i] > n){
    				cnt2 += 2;
    			}
    		}
		}
	}
	cnt2 -= cnt1 << 1;
	cnt2 -= n - 1;
	cnt2 >>= 1;
	ll cnt3 = 1ll * n * (n - 1) / 2 - cnt0 - cnt1 - cnt2;
	return printf("%I64d\n", cnt1 + 2 * cnt2 + 3 * cnt3), 0;
}
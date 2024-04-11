#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;

int powermod(int a, int exp, int moder){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

struct poly{
	static const int N = 3010;
	
	int a[N];
	int length, moder;
	
	poly():length(-1), moder(0){memset(a, 0, sizeof(a));}
	poly(int moder):length(-1), moder(moder){memset(a, 0, sizeof(a));}
	
	int value(int x){
		int ret = 0;
		for (int i = 0, now = 1; i <= length; ++ i){
			ret = (ret + 1ll * a[i] * now) % moder;
			now = 1ll * now * x % moder;
		}
		return ret;
	}
	
	int &operator [](int sit){return a[sit];}
	
	static poly interpolation(std::vector <pii> vec, int moder){
		int n = vec.size() - 1;
		poly aux(moder); aux.length = 0; aux.a[0] = 1;
		for (int i = 0; i <= n; ++ i, ++ aux.length){
            int coe = moder - vec[i].first;
            coe -= coe >= moder ? moder : 0;
            for (int j = aux.length; j >= 0; -- j){
                aux.a[j + 1] += aux.a[j];
                aux.a[j + 1] -= aux.a[j + 1] >= moder ? moder : 0;
                aux.a[j] = 1ll * aux.a[j] * coe % moder;
            }
		}
		poly ret(moder);
		for (int i = 0; i <= n; ++ i){
            int coe = moder - vec[i].first;
            coe -= coe >= moder ? moder : 0;
            int x = 1;
            for (int j = 0; j <= n; ++ j){
                if (i == j) continue;
                x = 1ll * x * (vec[i].first - vec[j].first) % moder;
                x += x < 0 ? moder : 0;
            }
            x = 1ll * powermod(x, moder - 2, moder) * vec[i].second % moder;
            int left = aux.a[aux.length];
            for (int j = aux.length; j; -- j){
                ret.a[j - 1] = (ret.a[j - 1] + 1ll * left * x) % moder;
                left = (aux.a[j - 1] - 1ll * left * coe) % moder;
                left += left < 0 ? moder : 0;
            }
		}
        ret.length = n;
		return ret;
	}
};

const int N = 3010;
const int moder = 1e9 + 7;

int dp[N][N];
std::vector <int> e[N];

void dfs(int u){
    for (int i = 1; i < N; ++ i){
        dp[u][i] = 1;
    }
    for (auto v : e[u]){
        dfs(v);
        for (int i = 0; i < N; ++ i){
            dp[u][i] = 1ll * dp[u][i] * dp[v][i] % moder;
        }
    }
    for (int i = 1; i < N; ++ i){
        dp[u][i] += dp[u][i - 1];
        dp[u][i] -= dp[u][i] >= moder ? moder : 0;
    }
}

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 2, x; i <= n; ++ i){
        scanf("%d", &x);
        e[x].push_back(i);
    }
    dfs(1);
    std::vector <pii> vec;
    for (int i = 1; i <= n + 1; ++ i){
        vec.push_back({i, dp[1][i]});
    }
    poly p = poly::interpolation(vec, moder);
    printf("%d\n", p.value(d));
    return 0;
}
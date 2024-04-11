#include<bits/stdc++.h>

const int N = 32000010;
const int M = 10010;
typedef long long ll;
typedef std::pair <ll, int> pii;

int min[N];
int prime[2000010], pcnt;
bool ans[M];
bool dp[N];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime[pcnt ++] = i;
        }
        for (int j = 0; j < pcnt && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}

ll ex_euc(ll a, ll b, ll &x, ll &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    ll ret = ex_euc(b, a % b, x, y), tmp = y;
    y = x - a / b * y;
    x = tmp;
    return ret;
}

ll inv(ll a, ll moder){
    ll b = moder, s = 1, t = 0;
    while (b){
        ll tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    return s < 0 ? s + moder : s;
}

ll divide(ll a, ll b){return a / b - ((a ^ b) < 0 && a % b);}

bool check(ll u, ll v, ll x, ll y, ll n){
    return divide(-n * x + v - 1, v) <= divide(n * y, u);
}

int main(){
    init();
    int test;
    scanf("%d", &test);
    std::map <ll, std::vector <pii>> map;
    for (int i = 0; i < test; ++ i){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        map[k].push_back({n, i});
    }
    for (auto &u : map){
        ll k = u.first;
        std::vector <ll> prime;
        ll x = k;
        for (int i = 0; i < pcnt; ++ i){
            if (x % ::prime[i] == 0){
                prime.push_back(::prime[i]);
                while (x % ::prime[i] == 0){
                    x /= ::prime[i];
                }
            }
        }
        if (x > 1){
            prime.push_back(x);
        }
        if (prime.size() >= 4){
            int sz = prime[0] * prime[1];
            memset(dp, 0, sizeof(bool) * sz);
            dp[0] = true;
            for (auto v : prime){
                for (int i = 0; i + v < sz; ++ i){
                    if (dp[i]) dp[i + v] = true;
                }
            }
            for (auto v : u.second){
                ans[v.second] = v.first >= sz ? true : dp[v.first];
            }
            continue;
        }
        if (prime.empty()){
            for (auto v : u.second){
                ans[v.second] = false;
            }
            continue;
        }
        if (prime.size() == 1){
            for (auto v : u.second){
                ans[v.second] = !(v.first % prime[0]);
            }
            continue;
        }
        if (prime.size() == 2){
            for (auto v : u.second){
                ll n = v.first;
                if (n >= prime[0] * prime[1]){
                    ans[v.second] = true;
                    continue;
                }
                ll t = (n % prime[0]) * inv(prime[1], prime[0]) % prime[0];
                ans[v.second] = n - t * prime[1] >= 0;
            }
            continue;
        }
        ll uu = prime[0], vv = prime[1];
        ll y;
        ex_euc(uu, vv, x, y);
        for (auto v : u.second){
            ll n = v.first;
            if (n >= uu * vv){
                ans[v.second] = true;
                continue;
            }
            ans[v.second] = false;
            for (int i = 0; i * prime[2] <= n; ++ i){
                if (check(uu, vv, x, y, n - i * prime[2])){
                    ans[v.second] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < test; ++ i){
        puts(ans[i] ? "YES" : "NO");
    }
    return 0;
}
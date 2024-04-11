#include <bits/stdc++.h>

const int N = 10000010;
typedef long long ll;

int min[N];
bool vis[N];
std::vector <int> prime;

ll random(ll n){
    return ((ll) rand() << 45 | (ll) rand() << 30 | rand() << 15 | rand()) % n;
}

ll multmod(ll a, ll b, ll moder){
    ll ans = (a * b - (ll)((long double) a * b / moder) * moder) % moder;
    ans += ans < 0 ? moder : 0;
    return ans;
}

ll powermod(ll a, ll exp, ll moder){
    ll ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) {
            ret = multmod(ret, a, moder);
        }
        a = multmod(a, a, moder);
    }
    return ret;
}

bool solve(ll n, int t, ll u){
    ll a = random(n);
    if(!a || a == 1) return true;
    ll pre = powermod(a, u, n);
    for (int i = 0; i < t; ++ i){
        ll now = multmod(pre, pre, n);
        if (now == 1 && pre != 1 && pre != n - 1) return false;
        pre = now;
    }
    return pre == 1;
}

bool solve(ll n){
    if (n < N) return min[n] == n;
    if (!(n & 1)) return false;
    const int S = 7; ll t = 0, x = n - 1;
    for ( ; !(x & 1); x >>= 1, ++ t);
    for (int i = 0; i < S; ++ i)
        if (!solve(n, t, x)) return false;
    return true;
}

ll pollard(ll n){//n10
    ll c = random(n - 1) + 1, x = random(n), y = x, i = 0, k = 1;
    for ( ; ; ){
        ++ i;
        x = multmod(x, x, n) + c;
        x -= x >= n ? n : 0;
        ll d = std::__gcd(std::abs(y - x), n);
        if (d != 1 && d != n) return d;
        if (x == y) return n;//1
        if (i == k){ y = x; k <<= 1; }
    }
}

std::map <ll, int> fact;

void factor(ll n){
    if (solve(n)){
        ++ fact[n];
        return;
    }
    ll x = pollard(n);
    if (x != 1 && x != n){
        factor(x);
        factor(n / x);
    }
    else{
        factor(n);
    }
}

using pii = std::pair <ll, ll>;

std::vector <pii> do_factor(ll n){
    fact.clear();
    for (auto u : prime){
        if (n % u == 0){
            while (n % u == 0){
                n /= u;
                ++ fact[u];
            }
        }
    }
    if (n > 1){
        factor(n);
    }
    std::vector <pii> ret;
    for (auto u : fact){
        ret.push_back(u);
    }
    return ret;
}

int main(){
    srand((unsigned) time(nullptr));
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    ll n, p, m;
    scanf("%lld%lld%lld", &n, &m, &p);
    std::vector <pii> fact_m = do_factor(m);
    ll pr = fact_m[0].first;
    if (m < N){
        for (ll i = 0; i < m; i += pr){
            vis[i] = true;
        }
        ll now = 1;
        while (!vis[now]){
            vis[now] = true;
            now = multmod(now, p, m);
        }
        std::vector <ll> possible;
        for (ll i = 0; i < m; ++ i){
            if (!vis[i]){
                possible.push_back(i);
            }
        }
        if ((int) possible.size() < n){
            puts("-1");
            return 0;
        }
        for (ll i = 0; i < n; ++ i){
            printf("%lld%c", possible[i], " \n"[i == n - 1]);
        }
        return 0;
    }
    if (pr == 2){
        if (p % 2 == 0){
            for (ll i = 0; i < n; ++ i){
                printf("%lld%c", 2 * i + 3, " \n"[i == n - 1]);
            }
        }
        else if (p % 4 == 1){
            for (ll i = 0; i < n; ++ i){
                printf("%lld%c", m - powermod(5, i, m), " \n"[i == n - 1]);
            }
        }
        else{
            for (ll i = 0; i < n; ++ i){
                printf("%lld%c", powermod(5, 2 * i + 1, m), " \n"[i == n - 1]);
            }
        }
        return 0;
    }
    if (p % pr == 0){
        for (ll i = 2, cnt = 0; cnt < n; ++ i){
            if (i % pr != 0){
                printf("%lld%c", i, " \n"[cnt == n - 1]);
                ++ cnt;
            }
        }
        return 0;
    }
    ll phi_m = m / pr * (pr - 1);
    std::vector <pii> fact_phi = do_factor(phi_m);
    ll prm_root = 0;
    while (true){
        ll x = random(m);
        if (x % pr == 0){
            continue;
        }
        bool flag = true;
        for (auto u : fact_phi){
            if (powermod(x, phi_m / u.first, m) == 1){
                flag = false;
                break;
            }
        }
        if (flag){
            prm_root = x;
            break;
        }
    }
    ll exp = phi_m;
    for (auto u : fact_phi){
        for (int i = 0; i < u.second; ++ i){
            if (powermod(p, exp / u.first, m) == 1){
                exp /= u.first;
            }
            else{
                break;
            }
        }
    }
    if (exp == phi_m){
        puts("-1");
        return 0;
    }
    for (int i = 1, cnt = 0; cnt < n; ++ i){
        if (i % (phi_m / exp) == 0){
            continue;
        }
        printf("%lld%c", powermod(prm_root, i, m), " \n"[cnt == n - 1]);
        ++ cnt;
    }
    return 0;
}